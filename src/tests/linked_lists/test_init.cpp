#include "test_config.hh"

using namespace TestUtils;

#ifdef INIT

class LinkedListInitTest : public ::testing::Test {
protected:
    std::shared_ptr<MemoryManager::FixedArena> fixed_arena;
    std::shared_ptr<MemoryManager::ScalableArena> scalable_arena;

    void SetUp() override {
        fixed_arena = MemoryManager::instance().create_fixed_arena(1024 * 10);
        scalable_arena = MemoryManager::instance().create_scalable_arena();
    }
};

// ======= FIXED ARENA TESTS =======

TEST_F(LinkedListInitTest, Fixed_T01_DefaultConstructor) {
    LinkedList<MemoryManager::FixedArena> list(fixed_arena);
    test_linked_list_integrity(list, {});
}

TEST_F(LinkedListInitTest, Fixed_T02_EmptyVectorConstructor) {
    std::vector<size_t> input = {};
    LinkedList<MemoryManager::FixedArena> list(input, fixed_arena);
    test_linked_list_integrity(list, input);
}

TEST_F(LinkedListInitTest, Fixed_T03_SingleElementVector) {
    std::vector<size_t> input = {42};
    LinkedList<MemoryManager::FixedArena> list(input, fixed_arena);
    test_linked_list_integrity(list, input);
}

TEST_F(LinkedListInitTest, Fixed_T04_MultipleElementsVector) {
    std::vector<size_t> input = {10, 20, 30, 40};
    LinkedList<MemoryManager::FixedArena> list(input, fixed_arena);
    test_linked_list_integrity(list, input);
}

TEST_F(LinkedListInitTest, Fixed_T05_MoveConstructor) {
    LinkedList<MemoryManager::FixedArena> original({1, 2, 3}, fixed_arena);
    LinkedList<MemoryManager::FixedArena> moved(std::move(original));

    test_linked_list_integrity(moved, {1, 2, 3});
    EXPECT_TRUE(original.empty());
}

TEST_F(LinkedListInitTest, Fixed_T06_MoveAssignmentOperator) {
    LinkedList<MemoryManager::FixedArena> original({4, 5, 6}, fixed_arena);
    LinkedList<MemoryManager::FixedArena> moved(fixed_arena);
    moved = std::move(original);

    test_linked_list_integrity(moved, {4, 5, 6});
    EXPECT_TRUE(original.empty());
}

TEST_F(LinkedListInitTest, Fixed_T07_SelfMoveAssignment) {
    LinkedList<MemoryManager::FixedArena> list({7, 8, 9}, fixed_arena);
    list = std::move(list);  // self-move
    test_linked_list_integrity(list, {7, 8, 9});
}

TEST_F(LinkedListInitTest, Fixed_T08_ExplicitSizeConstructor) {
    LinkedList<MemoryManager::FixedArena> list(1024);
    EXPECT_TRUE(list.empty());
    EXPECT_NE(list.arena, nullptr);
}

TEST_F(LinkedListInitTest, Fixed_T09_VectorAndSizeConstructor) {
    std::vector<size_t> input = {100, 200, 300};
    LinkedList<MemoryManager::FixedArena> list(input, 1024);
    test_linked_list_integrity(list, input);
}

TEST_F(LinkedListInitTest, Fixed_T10_RobustnessAfterRelease) {
    {
        LinkedList<MemoryManager::FixedArena> list({9, 8, 7}, fixed_arena);
        test_linked_list_integrity(list, {9, 8, 7});
    }
    LinkedList<MemoryManager::FixedArena> list2(fixed_arena);
    EXPECT_TRUE(list2.empty());
}

// ======= SCALABLE ARENA TESTS =======

TEST_F(LinkedListInitTest, Scalable_T01_DefaultConstructor) {
    LinkedList<MemoryManager::ScalableArena> list(scalable_arena);
    test_linked_list_integrity(list, {});
}

TEST_F(LinkedListInitTest, Scalable_T02_EmptyVectorConstructor) {
    std::vector<size_t> input = {};
    LinkedList<MemoryManager::ScalableArena> list(input, scalable_arena);
    test_linked_list_integrity(list, input);
}

TEST_F(LinkedListInitTest, Scalable_T03_SingleElementVector) {
    std::vector<size_t> input = {42};
    LinkedList<MemoryManager::ScalableArena> list(input, scalable_arena);
    test_linked_list_integrity(list, input);
}

TEST_F(LinkedListInitTest, Scalable_T04_MultipleElementsVector) {
    std::vector<size_t> input = {10, 20, 30, 40};
    LinkedList<MemoryManager::ScalableArena> list(input, scalable_arena);
    test_linked_list_integrity(list, input);
}

#endif
