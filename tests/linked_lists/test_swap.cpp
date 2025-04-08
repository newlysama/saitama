#include "test_config.hh"

using namespace TestUtils;

#ifdef SWAP

class LinkedListSwapValuesTest : public ::testing::Test {
protected:
    std::shared_ptr<std::pmr::memory_resource> arena;

    void SetUp() override {
        arena = MemoryManager::instance().create_arena(1024 * 4);
    }

    void TearDown() override {
        MemoryManager::instance().release_arena(arena.get());
    }
};

TEST_F(LinkedListSwapValuesTest, T01_SwapTwoElementsAtBeginning) {
    LinkedList list({1, 2}, arena.get());
    list.swap_values(0, 1);
    test_linked_list_integrity(list, {2, 1});
}

TEST_F(LinkedListSwapValuesTest, T02_SwapTwoMiddleElements) {
    LinkedList list({1, 2, 3, 4}, arena.get());
    list.swap_values(1, 2);
    test_linked_list_integrity(list, {1, 3, 2, 4});
}

TEST_F(LinkedListSwapValuesTest, T03_SwapFirstAndLast) {
    LinkedList list({1, 2, 3, 4}, arena.get());
    list.swap_values(0, 3);
    test_linked_list_integrity(list, {4, 2, 3, 1});
}

TEST_F(LinkedListSwapValuesTest, T04_SameIndexShouldDoNothing) {
    LinkedList list({5, 6, 7}, arena.get());
    list.swap_values(1, 1);
    test_linked_list_integrity(list, {5, 6, 7});
}

TEST_F(LinkedListSwapValuesTest, T05_SwapReverseIndexOrder) {
    LinkedList list({10, 20, 30}, arena.get());
    list.swap_values(2, 0);
    test_linked_list_integrity(list, {30, 20, 10});
}

TEST_F(LinkedListSwapValuesTest, T06_IndexIOutOfBounds) {
    LinkedList list({1, 2}, arena.get());
    EXPECT_THROW(list.swap_values(5, 1), std::invalid_argument);
}

TEST_F(LinkedListSwapValuesTest, T07_IndexJOutOfBounds) {
    LinkedList list({1, 2}, arena.get());
    EXPECT_THROW(list.swap_values(0, 10), std::invalid_argument);
}

TEST_F(LinkedListSwapValuesTest, T08_EmptyListShouldThrow) {
    LinkedList list(arena.get());
    EXPECT_THROW(list.swap_values(0, 1), std::invalid_argument);
}

TEST_F(LinkedListSwapValuesTest, T09_SwapTwiceRestoresList) {
    LinkedList list({7, 8, 9}, arena.get());
    list.swap_values(0, 2);
    list.swap_values(2, 0);
    test_linked_list_integrity(list, {7, 8, 9});
}

#endif
