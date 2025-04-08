#include "test_config.hh"

using namespace TestUtils;

#ifdef INIT

class LinkedListInitTest : public ::testing::Test {
protected:
    std::shared_ptr<std::pmr::memory_resource> arena;

    void SetUp() override {
        arena = MemoryManager::instance().create_arena(1024 * 10);
    }

    void TearDown() override {
        MemoryManager::instance().release_arena(arena.get());
    }
};

TEST_F(LinkedListInitTest, T_01_DefaultConstructorCreatesEmptyList) {
    LinkedList list(arena.get());
    test_linked_list_integrity(list, {});
}

TEST_F(LinkedListInitTest, T_02_InitFromEmptyVectorCreatesEmptyList) {
    std::vector<size_t> input = {};
    LinkedList list(input, arena.get());
    test_linked_list_integrity(list, input);
}

TEST_F(LinkedListInitTest, T_03_InitFromSingleElementVector) {
    std::vector<size_t> input = {42};
    LinkedList list(input, arena.get());
    test_linked_list_integrity(list, input);
}

TEST_F(LinkedListInitTest, T_04_InitFromMultipleElementsVector) {
    std::vector<size_t> input = {10, 20, 30, 40};
    LinkedList list(input, arena.get());
    test_linked_list_integrity(list, input);
}

TEST_F(LinkedListInitTest, T_05_MoveConstructor) {
    LinkedList original({1, 2, 3}, arena.get());
    LinkedList moved(std::move(original));

    test_linked_list_integrity(moved, {1, 2, 3});

    EXPECT_TRUE(original.empty());
    EXPECT_EQ(original.size, 0);
    EXPECT_EQ(original.first, nullptr);
    EXPECT_EQ(original.last, nullptr);
}

TEST_F(LinkedListInitTest, T_06_MoveAssignmentOperator) {
    LinkedList original({4, 5, 6}, arena.get());
    LinkedList moved(arena.get());

    moved = std::move(original);
    test_linked_list_integrity(moved, {4, 5, 6});

    EXPECT_TRUE(original.empty());
    EXPECT_EQ(original.size, 0);
    EXPECT_EQ(original.first, nullptr);
    EXPECT_EQ(original.last, nullptr);
}

TEST_F(LinkedListInitTest, T_07_SelfMoveAssignmentDoesNothing) {
    LinkedList list({7, 8, 9}, arena.get());
    LinkedList& ref = list;

    list = std::move(ref);  // simulate self-move
    test_linked_list_integrity(list, {7, 8, 9}); // should remain unchanged
}

TEST_F(LinkedListInitTest, T_08_ExplicitArenaSizeConstructor) {
    LinkedList list(1024);
    EXPECT_TRUE(list.empty());
    EXPECT_NE(list.arena, nullptr);
}

TEST_F(LinkedListInitTest, T_09_VectorAndArenaSizeConstructor) {
    std::vector<size_t> input = {100, 200, 300};
    LinkedList list(input, 1024);
    test_linked_list_integrity(list, input);
}

TEST_F(LinkedListInitTest, T_10_OnlyArenaConstructor) {
    LinkedList list(arena.get());
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.arena, arena);
}

TEST_F(LinkedListInitTest, T_11_RobustnessAccessAfterRelease) {
    {
        LinkedList list({9, 8, 7}, arena.get());
        test_linked_list_integrity(list, {9, 8, 7});
    }
    MemoryManager::instance().release_arena(arena.get()); // deallocate everything
    // Ensure we don't crash or reuse released arena
    LinkedList list2(arena.get());
    EXPECT_TRUE(list2.empty());
}

#endif