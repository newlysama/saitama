#include "test_config.hh"

using namespace TestUtils;
using namespace LinkedListAlgorithm;

#ifdef SPLIT

class LinkedListSplitTest : public ::testing::Test {
    protected:
        std::shared_ptr<MemoryManager::FixedArena> arena;
        
    void SetUp() override {
        arena = MemoryManager::instance().create_fixed_arena(1024 * 100);
    }
};

/* ======================= SPLIT ======================= */

TEST_F(LinkedListSplitTest, T01_SplitThrowsOnEmptyList) {
    LinkedList<MemoryManager::FixedArena> list(arena);
    EXPECT_THROW(split(list), std::invalid_argument);
}

TEST_F(LinkedListSplitTest, T02_SplitThrowsOnSizeOneList) {
    LinkedList<MemoryManager::FixedArena> list({42}, arena);
    EXPECT_THROW(split(list), std::invalid_argument);
}

TEST_F(LinkedListSplitTest, T03_SplitAtIndexZero) {
    LinkedList<MemoryManager::FixedArena> list({1, 2, 3}, arena);
    auto [left, right] = split(list, 0);
    test_linked_list_integrity(left, {1});
    test_linked_list_integrity(right, {2, 3});
}

TEST_F(LinkedListSplitTest, T04_SplitAtEnd) {
    LinkedList<MemoryManager::FixedArena> list({4, 5, 6}, arena);
    auto [left, right] = split(list, 2);
    test_linked_list_integrity(left, {4, 5});
    test_linked_list_integrity(right, {6});
}

TEST_F(LinkedListSplitTest, T05_SplitEvenLength) {
    LinkedList<MemoryManager::FixedArena> list({10, 20, 30, 40}, arena);
    auto [left, right] = split(list);
    test_linked_list_integrity(left, {10, 20});
    test_linked_list_integrity(right, {30, 40});
}

TEST_F(LinkedListSplitTest, T06_SplitOddLength) {
    LinkedList<MemoryManager::FixedArena> list({1, 2, 3, 4, 5}, arena);
    auto [left, right] = split(list);
    test_linked_list_integrity(left, {1, 2});
    test_linked_list_integrity(right, {3, 4, 5});
}

TEST_F(LinkedListSplitTest, T07_SplitAtCustomIndex) {
    LinkedList<MemoryManager::FixedArena> list({1, 3, 5, 7, 9}, arena);
    auto [left, right] = split(list, 3);
    test_linked_list_integrity(left, {1, 3, 5});
    test_linked_list_integrity(right, {7, 9});
}

TEST_F(LinkedListSplitTest, T08_SplitOutOfBoundsThrows) {
    LinkedList<MemoryManager::FixedArena> list({1, 2}, arena);
    EXPECT_THROW(split(list, 5), std::invalid_argument);
}

TEST_F(LinkedListSplitTest, T09_SplitThenConcatRestoresList) {
    LinkedList<MemoryManager::FixedArena> list({1, 2, 3, 4}, arena);
    auto [left, right] = split(list);
    concat(left, right);
    test_linked_list_integrity(left, {1, 2, 3, 4});
}

TEST_F(LinkedListSplitTest, T10_SplitThenMergeRestoresSortedList) {
    LinkedList<MemoryManager::FixedArena> list({1, 3, 5, 7}, arena);
    auto [left, right] = split(list);
    merge(left, right);
    test_linked_list_integrity(left, {1, 3, 5, 7});
}


#endif

#ifdef SPLIT_AROUND_PIVOT

/* ================= SPLIT AROUND PIVOT ================= */


TEST_F(LinkedListSplitTest, T11_SplitAroundPivotThrowsOnEmpty) {
    LinkedList<MemoryManager::FixedArena> list(arena);
    EXPECT_THROW(split_around_pivot(list, 0), std::invalid_argument);
}

TEST_F(LinkedListSplitTest, T12_SplitAroundPivotThrowsOnSizeOne) {
    LinkedList<MemoryManager::FixedArena> list({99}, arena);
    EXPECT_THROW(split_around_pivot(list, 0), std::invalid_argument);
}

TEST_F(LinkedListSplitTest, T13_SplitAroundPivotAtZero) {
    LinkedList<MemoryManager::FixedArena> list({1, 2, 3}, arena);
    auto [left, pivot, right] = split_around_pivot(list, 0);
    test_linked_list_integrity(left, {});
    test_linked_list_integrity(pivot, {1});
    test_linked_list_integrity(right, {2, 3});
}

TEST_F(LinkedListSplitTest, T14_SplitAroundPivotAtLastIndex) {
    LinkedList<MemoryManager::FixedArena> list({4, 5, 6}, arena);
    auto [left, pivot, right] = split_around_pivot(list, 2);
    test_linked_list_integrity(left, {4, 5});
    test_linked_list_integrity(pivot, {6});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListSplitTest, T15_SplitAroundPivotMiddleEven) {
    LinkedList<MemoryManager::FixedArena> list({10, 20, 30, 40}, arena);
    auto [left, pivot, right] = split_around_pivot(list, 2);
    test_linked_list_integrity(left, {10, 20});
    test_linked_list_integrity(pivot, {30});
    test_linked_list_integrity(right, {40});
}

TEST_F(LinkedListSplitTest, T16_SplitAroundPivotMiddleOdd) {
    LinkedList<MemoryManager::FixedArena> list({1, 3, 5, 7, 9}, arena);
    auto [left, pivot, right] = split_around_pivot(list, 2);
    test_linked_list_integrity(left, {1, 3});
    test_linked_list_integrity(pivot, {5});
    test_linked_list_integrity(right, {7, 9});
}

TEST_F(LinkedListSplitTest, T17_SplitAroundPivotOutOfBoundsThrows) {
    LinkedList<MemoryManager::FixedArena> list({1, 2}, arena);
    EXPECT_THROW(split_around_pivot(list, 5), std::invalid_argument);
}

TEST_F(LinkedListSplitTest, T18_SplitAroundPivotThenConcatRestoresList) {
    LinkedList<MemoryManager::FixedArena> list({10, 20, 30, 40}, arena);
    auto [left, pivot, right] = split_around_pivot(list, 2);
    concat(left, pivot);
    concat(left, right);
    test_linked_list_integrity(left, {10, 20, 30, 40});
}

TEST_F(LinkedListSplitTest, T19_SplitAroundPivotThenMergeRestoresSortedList) {
    LinkedList<MemoryManager::FixedArena> list({1, 4, 6, 8}, arena);
    auto [left, pivot, right] = split_around_pivot(list, 2);
    merge(left, pivot);
    merge(left, right);
    test_linked_list_integrity(left, {1, 4, 6, 8});
}

#endif