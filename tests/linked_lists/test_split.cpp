#include "test_config.hh"

using namespace TestUtils;
using namespace LinkedListAlgorithm;

class LinkedListSplitTest : public ::testing::Test {
protected:
    std::shared_ptr<std::pmr::memory_resource> arena;

    void SetUp() override {
        arena = MemoryManager::instance().create_arena(1024 * 16);
    }

    void TearDown() override {
        MemoryManager::instance().release_arena(arena.get());
    }
};


#ifdef SPLIT

/* ======================= SPLIT ======================= */

TEST_F(LinkedListSplitTest, T01_SplitThrowsOnEmptyList) {
    LinkedList list(arena.get());
    EXPECT_THROW(split(list), std::invalid_argument);
}

TEST_F(LinkedListSplitTest, T02_SplitThrowsOnSizeOneList) {
    LinkedList list({42}, arena.get());
    EXPECT_THROW(split(list), std::invalid_argument);
}

TEST_F(LinkedListSplitTest, T03_SplitAtIndexZero) {
    LinkedList list({1, 2, 3}, arena.get());
    auto [left, right] = split(list, 0);
    test_linked_list_integrity(left, {1});
    test_linked_list_integrity(right, {2, 3});
}

TEST_F(LinkedListSplitTest, T04_SplitAtEnd) {
    LinkedList list({4, 5, 6}, arena.get());
    auto [left, right] = split(list, 2);
    test_linked_list_integrity(left, {4, 5});
    test_linked_list_integrity(right, {6});
}

TEST_F(LinkedListSplitTest, T05_SplitEvenLength) {
    LinkedList list({10, 20, 30, 40}, arena.get());
    auto [left, right] = split(list);
    test_linked_list_integrity(left, {10, 20});
    test_linked_list_integrity(right, {30, 40});
}

TEST_F(LinkedListSplitTest, T06_SplitOddLength) {
    LinkedList list({1, 2, 3, 4, 5}, arena.get());
    auto [left, right] = split(list);
    test_linked_list_integrity(left, {1, 2});
    test_linked_list_integrity(right, {3, 4, 5});
}

TEST_F(LinkedListSplitTest, T07_SplitAtCustomIndex) {
    LinkedList list({1, 3, 5, 7, 9}, arena.get());
    auto [left, right] = split(list, 3);
    test_linked_list_integrity(left, {1, 3, 5});
    test_linked_list_integrity(right, {7, 9});
}

TEST_F(LinkedListSplitTest, T08_SplitOutOfBoundsThrows) {
    LinkedList list({1, 2}, arena.get());
    EXPECT_THROW(split(list, 5), std::invalid_argument);
}

TEST_F(LinkedListSplitTest, T09_SplitThenConcatRestoresList) {
    LinkedList list({1, 2, 3, 4}, arena.get());
    auto [left, right] = split(list);
    concat(left, right);
    test_linked_list_integrity(left, {1, 2, 3, 4});
}

TEST_F(LinkedListSplitTest, T10_SplitThenMergeRestoresSortedList) {
    LinkedList list({1, 3, 5, 7}, arena.get());
    auto [left, right] = split(list);
    merge(left, right);
    test_linked_list_integrity(left, {1, 3, 5, 7});
}


#endif

#ifdef SPLIT_AROUND_PIVOT

/* ================= SPLIT AROUND PIVOT ================= */


TEST_F(LinkedListSplitTest, T11_SplitAroundPivotThrowsOnEmpty) {
    LinkedList list(arena.get());
    EXPECT_THROW(split_around_pivot(list, 0), std::invalid_argument);
}

TEST_F(LinkedListSplitTest, T12_SplitAroundPivotThrowsOnSizeOne) {
    LinkedList list({99}, arena.get());
    EXPECT_THROW(split_around_pivot(list, 0), std::invalid_argument);
}

TEST_F(LinkedListSplitTest, T13_SplitAroundPivotAtZero) {
    LinkedList list({1, 2, 3}, arena.get());
    auto [left, pivot, right] = split_around_pivot(list, 0);
    test_linked_list_integrity(left, {});
    test_linked_list_integrity(pivot, {1});
    test_linked_list_integrity(right, {2, 3});
}

TEST_F(LinkedListSplitTest, T14_SplitAroundPivotAtLastIndex) {
    LinkedList list({4, 5, 6}, arena.get());
    auto [left, pivot, right] = split_around_pivot(list, 2);
    test_linked_list_integrity(left, {4, 5});
    test_linked_list_integrity(pivot, {6});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListSplitTest, T15_SplitAroundPivotMiddleEven) {
    LinkedList list({10, 20, 30, 40}, arena.get());
    auto [left, pivot, right] = split_around_pivot(list, 2);
    test_linked_list_integrity(left, {10, 20});
    test_linked_list_integrity(pivot, {30});
    test_linked_list_integrity(right, {40});
}

TEST_F(LinkedListSplitTest, T16_SplitAroundPivotMiddleOdd) {
    LinkedList list({1, 3, 5, 7, 9}, arena.get());
    auto [left, pivot, right] = split_around_pivot(list, 2);
    test_linked_list_integrity(left, {1, 3});
    test_linked_list_integrity(pivot, {5});
    test_linked_list_integrity(right, {7, 9});
}

TEST_F(LinkedListSplitTest, T17_SplitAroundPivotOutOfBoundsThrows) {
    LinkedList list({1, 2}, arena.get());
    EXPECT_THROW(split_around_pivot(list, 5), std::invalid_argument);
}

TEST_F(LinkedListSplitTest, T18_SplitAroundPivotThenConcatRestoresList) {
    LinkedList list({10, 20, 30, 40}, arena.get());
    auto [left, pivot, right] = split_around_pivot(list, 2);
    concat(left, pivot);
    concat(left, right);
    test_linked_list_integrity(left, {10, 20, 30, 40});
}

TEST_F(LinkedListSplitTest, T19_SplitAroundPivotThenMergeRestoresSortedList) {
    LinkedList list({1, 4, 6, 8}, arena.get());
    auto [left, pivot, right] = split_around_pivot(list, 2);
    merge(left, pivot);
    merge(left, right);
    test_linked_list_integrity(left, {1, 4, 6, 8});
}

#endif