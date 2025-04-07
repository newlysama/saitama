#include "test_config.hh"

using namespace TestUtils;

#ifdef POP

class LinkedListPopTest : public ::testing::Test {
protected:
    std::shared_ptr<std::pmr::memory_resource> arena;

    void SetUp() override {
        arena = MemoryManager::instance().create_arena(1024 * 16);
    }

    void TearDown() override {
        MemoryManager::instance().release_arena(arena.get());
    }
};

/*
 * ======================== pop_front ========================
 */

TEST_F(LinkedListPopTest, T_01_PopFrontThrowsOnEmptyList) {
    LinkedList list(arena);
    EXPECT_THROW(list.pop_front(), std::invalid_argument);
}

TEST_F(LinkedListPopTest, T_02_PopFrontOnSingleElementList) {
    LinkedList list({42}, arena);
    auto node = list.pop_front();

    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->value, 42);
    EXPECT_EQ(node->next, nullptr);
    EXPECT_EQ(node->prev, nullptr);

    test_linked_list_integrity(list, {});
}

TEST_F(LinkedListPopTest, T_03_PopFrontOnMultipleElementList) {
    LinkedList list({10, 20, 30}, arena);
    auto node = list.pop_front();

    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->value, 10);
    EXPECT_EQ(node->next, nullptr);
    EXPECT_EQ(node->prev, nullptr);

    test_linked_list_integrity(list, {20, 30});
}

/*
 * ======================== pop_back ========================
 */

TEST_F(LinkedListPopTest, T_04_PopBackThrowsOnEmptyList) {
    LinkedList list(arena);
    EXPECT_THROW(list.pop_back(), std::invalid_argument);
}

TEST_F(LinkedListPopTest, T_05_PopBackThrowsIfLastIsNull) {
    LinkedList list({1}, arena);
    list.last = nullptr;  // Simulate corrupted state
    EXPECT_THROW(list.pop_back(), std::logic_error);
}

TEST_F(LinkedListPopTest, T_06_PopBackOnSingleElementList) {
    LinkedList list({99}, arena);
    auto node = list.pop_back();

    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->value, 99);
    EXPECT_EQ(node->next, nullptr);
    EXPECT_EQ(node->prev, nullptr);

    test_linked_list_integrity(list, {});
}

TEST_F(LinkedListPopTest, T_07_PopBackOnMultipleElementList) {
    LinkedList list({5, 10, 15}, arena);
    auto node = list.pop_back();

    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->value, 15);
    EXPECT_EQ(node->next, nullptr);
    EXPECT_EQ(node->prev, nullptr);

    test_linked_list_integrity(list, {5, 10});
}

#endif
