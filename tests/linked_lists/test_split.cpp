#include <gtest/gtest.h>

#include "test_selector.hh"
#include "tests/test_utils.hh" 
#include "utils/linked_lists/linked_lists.hh"
#include "utils/linked_lists/linked_lists_algorithms.hh"

using namespace LinkedListAlgorithm;

class LinkedListSplitTest : public ::testing::Test {};

#ifdef SPLIT

/* ======================= SPLIT ======================= */

TEST_F(LinkedListSplitTest, T01_SplitThrowsOnEmptyList) {
    LinkedList list;
    EXPECT_THROW(split(list), std::invalid_argument);
}

TEST_F(LinkedListSplitTest, T02_SplitThrowsOnSizeOneList) {
    auto list = LinkedList({42});
    EXPECT_THROW(split(list), std::invalid_argument);
}

TEST_F(LinkedListSplitTest, T03_SplitAtIndexZero) {
    auto list = LinkedList({1, 2, 3});
    auto [left, right] = split(list, 0);
    test_linked_list_integrity(left, {1});
    test_linked_list_integrity(right, {2, 3});
}

TEST_F(LinkedListSplitTest, T04_SplitAtEnd) {
    auto list = LinkedList({4, 5, 6});
    auto [left, right] = split(list, 2);
    test_linked_list_integrity(left, {4, 5});
    test_linked_list_integrity(right, {6});
}

TEST_F(LinkedListSplitTest, T05_SplitEvenLength) {
    auto list = LinkedList({10, 20, 30, 40});
    auto [left, right] = split(list);
    test_linked_list_integrity(left, {10, 20});
    test_linked_list_integrity(right, {30, 40});
}

TEST_F(LinkedListSplitTest, T06_SplitOddLength) {
    auto list = LinkedList({1, 2, 3, 4, 5});
    auto [left, right] = split(list);
    test_linked_list_integrity(left, {1, 2});
    test_linked_list_integrity(right, {3, 4, 5});
}

TEST_F(LinkedListSplitTest, T07_SplitAtCustomIndex) {
    auto list = LinkedList({1, 3, 5, 7, 9});
    auto [left, right] = split(list, 3);
    test_linked_list_integrity(left, {1, 3, 5});
    test_linked_list_integrity(right, {7, 9});
}

TEST_F(LinkedListSplitTest, T08_SplitOutOfBoundsThrows) {
    auto list = LinkedList({1, 2});
    EXPECT_THROW(split(list, 5), std::invalid_argument);
}

/* ========== SPLIT + CONCAT / MERGE (ROUNDTRIP VALIDATION) ========== */

TEST_F(LinkedListSplitTest, T9_SplitThenConcatRestoresList) {
    auto list = LinkedList({1, 2, 3, 4});
    auto [left, right] = split(list);
    concat(left, right);
    test_linked_list_integrity(left, {1, 2, 3, 4});
}

TEST_F(LinkedListSplitTest, T10_SplitThenMergeRestoresSortedList) {
    auto list = LinkedList({1, 3, 5, 7});
    auto [left, right] = split(list);
    merge(left, right);
    test_linked_list_integrity(left, {1, 3, 5, 7});
}

#endif

#ifdef SPLIT_AROUND_PIVOT

/* ================= SPLIT AROUND PIVOT ================= */

TEST_F(LinkedListSplitTest, T11_SplitAroundPivotThrowsOnEmpty) {
    LinkedList list;
    EXPECT_THROW(split_around_pivot(list, 0), std::invalid_argument);
}

TEST_F(LinkedListSplitTest, T12_SplitAroundPivotThrowsOnSizeOne) {
    auto list = LinkedList({99});
    EXPECT_THROW(split_around_pivot(list, 0), std::invalid_argument);
}

TEST_F(LinkedListSplitTest, T13_SplitAroundPivotAtZero) {
    auto list = LinkedList({1, 2, 3});
    auto [left, pivot, right] = split_around_pivot(list, 0);
    test_linked_list_integrity(left, {});
    test_linked_list_integrity(pivot, {1});
    test_linked_list_integrity(right, {2, 3});
}

TEST_F(LinkedListSplitTest, T14_SplitAroundPivotAtLastIndex) {
    auto list = LinkedList({4, 5, 6});
    auto [left, pivot, right] = split_around_pivot(list, 2);
    test_linked_list_integrity(left, {4, 5});
    test_linked_list_integrity(pivot, {6});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListSplitTest, T15_SplitAroundPivotMiddleEven) {
    auto list = LinkedList({10, 20, 30, 40});
    auto [left, pivot, right] = split_around_pivot(list, 2);
    test_linked_list_integrity(left, {10, 20});
    test_linked_list_integrity(pivot, {30});
    test_linked_list_integrity(right, {40});
}

TEST_F(LinkedListSplitTest, T16_SplitAroundPivotMiddleOdd) {
    auto list = LinkedList({1, 3, 5, 7, 9});
    auto [left, pivot, right] = split_around_pivot(list, 2);
    test_linked_list_integrity(left, {1, 3});
    test_linked_list_integrity(pivot, {5});
    test_linked_list_integrity(right, {7, 9});
}

TEST_F(LinkedListSplitTest, T17_SplitAroundPivotOutOfBoundsThrows) {
    auto list = LinkedList({1, 2});
    EXPECT_THROW(split_around_pivot(list, 5), std::invalid_argument);
}

/* ========== SPLIT_AROUND_PIVOT + CONCAT / MERGE (ROUNDTRIP VALIDATION) ========== */

TEST_F(LinkedListSplitTest, T18_SplitAroundPivotThenConcatRestoresList) {
    auto list = LinkedList({10, 20, 30, 40});
    auto [left, pivot, right] = split_around_pivot(list, 2);
    concat(left, pivot);
    concat(left, right);
    test_linked_list_integrity(left, {10, 20, 30, 40});
}

TEST_F(LinkedListSplitTest, T19_SplitAroundPivotThenMergeRestoresSortedList) {
    auto list = LinkedList({1, 4, 6, 8});
    auto [left, pivot, right] = split_around_pivot(list, 2);
    merge(left, pivot);
    merge(left, right);
    test_linked_list_integrity(left, {1, 4, 6, 8});
}

#endif