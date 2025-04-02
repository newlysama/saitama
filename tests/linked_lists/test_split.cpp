#include <gtest/gtest.h>
#include <linked_lists/linked_lists.hh>
#include <linked_lists/linked_lists_algorithms.hh>
#include <test_utils.hh>

using namespace LinkedListAlgorithm;

class LinkedListSplitTest : public ::testing::Test {};

/* ======================= SPLIT ======================= */

TEST_F(LinkedListSplitTest, T01_SplitThrowsOnEmptyList) {
    auto list = std::make_unique<LinkedList>();
    EXPECT_THROW(split(std::move(list)), std::invalid_argument);
}

TEST_F(LinkedListSplitTest, T02_SplitThrowsOnSizeOneList) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{42});
    EXPECT_THROW(split(std::move(list)), std::invalid_argument);
}

TEST_F(LinkedListSplitTest, T03_SplitAtIndexZero) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{1, 2, 3});
    auto [left, right] = split(std::move(list), 0);
    test_linked_list_integrity(*left, {1});
    test_linked_list_integrity(*right, {2, 3});
}

TEST_F(LinkedListSplitTest, T04_SplitAtEnd) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{4, 5, 6});
    auto [left, right] = split(std::move(list), 2);
    test_linked_list_integrity(*left, {4, 5});
    test_linked_list_integrity(*right, {6});
}

TEST_F(LinkedListSplitTest, T05_SplitEvenLength) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{10, 20, 30, 40});
    auto [left, right] = split(std::move(list));
    test_linked_list_integrity(*left, {10, 20});
    test_linked_list_integrity(*right, {30, 40});
}

TEST_F(LinkedListSplitTest, T06_SplitOddLength) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{1, 2, 3, 4, 5});
    auto [left, right] = split(std::move(list));
    test_linked_list_integrity(*left, {1, 2});
    test_linked_list_integrity(*right, {3, 4, 5});
}

TEST_F(LinkedListSplitTest, T07_SplitAtCustomIndex) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{1, 3, 5, 7, 9});
    auto [left, right] = split(std::move(list), 3);
    test_linked_list_integrity(*left, {1, 3, 5});
    test_linked_list_integrity(*right, {7, 9});
}

TEST_F(LinkedListSplitTest, T08_SplitOutOfBoundsThrows) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{1, 2});
    EXPECT_THROW(split(std::move(list), 5), std::invalid_argument);
}

/* ========== SPLIT + CONCAT / MERGE (ROUNDTRIP VALIDATION) ========== */

TEST_F(LinkedListSplitTest, T16_SplitThenConcatRestoresList) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{1, 2, 3, 4});
    auto [left, right] = split(std::move(list));
    concat(left, right);
    test_linked_list_integrity(*left, {1, 2, 3, 4});
}

TEST_F(LinkedListSplitTest, T17_SplitThenMergeRestoresSortedList) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{1, 3, 5, 7});
    auto [left, right] = split(std::move(list));
    auto result = merge(std::move(left), std::move(right));
    test_linked_list_integrity(*result, {1, 3, 5, 7});
}

/* ================= SPLIT AROUND PIVOT ================= */

TEST_F(LinkedListSplitTest, T09_SplitAroundPivotThrowsOnEmpty) {
    auto list = std::make_unique<LinkedList>();
    EXPECT_THROW(split_around_pivot(std::move(list), 0), std::invalid_argument);
}

TEST_F(LinkedListSplitTest, T10_SplitAroundPivotThrowsOnSizeOne) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{99});
    EXPECT_THROW(split_around_pivot(std::move(list), 0), std::invalid_argument);
}

TEST_F(LinkedListSplitTest, T11_SplitAroundPivotAtZero) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{1, 2, 3});
    auto [left, pivot, right] = split_around_pivot(std::move(list), 0);
    test_linked_list_integrity(*left, {});
    test_linked_list_integrity(*pivot, {1});
    test_linked_list_integrity(*right, {2, 3});
}

TEST_F(LinkedListSplitTest, T12_SplitAroundPivotAtLastIndex) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{4, 5, 6});
    auto [left, pivot, right] = split_around_pivot(std::move(list), 2);
    test_linked_list_integrity(*left, {4, 5});
    test_linked_list_integrity(*pivot, {6});
    test_linked_list_integrity(*right, {});
}

TEST_F(LinkedListSplitTest, T13_SplitAroundPivotMiddleEven) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{10, 20, 30, 40});
    auto [left, pivot, right] = split_around_pivot(std::move(list), 2);
    test_linked_list_integrity(*left, {10, 20});
    test_linked_list_integrity(*pivot, {30});
    test_linked_list_integrity(*right, {40});
}

TEST_F(LinkedListSplitTest, T14_SplitAroundPivotMiddleOdd) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{1, 3, 5, 7, 9});
    auto [left, pivot, right] = split_around_pivot(std::move(list), 2);
    test_linked_list_integrity(*left, {1, 3});
    test_linked_list_integrity(*pivot, {5});
    test_linked_list_integrity(*right, {7, 9});
}

TEST_F(LinkedListSplitTest, T15_SplitAroundPivotOutOfBoundsThrows) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{1, 2});
    EXPECT_THROW(split_around_pivot(std::move(list), 5), std::invalid_argument);
}

/* ========== SPLIT_AROUND_PIVOT + CONCAT / MERGE (ROUNDTRIP VALIDATION) ========== */

TEST_F(LinkedListSplitTest, T18_SplitAroundPivotThenConcatRestoresList) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{10, 20, 30, 40});
    auto [left, pivot, right] = split_around_pivot(std::move(list), 2);
    concat(left, pivot);
    concat(left, right);
    test_linked_list_integrity(*left, {10, 20, 30, 40});
}

TEST_F(LinkedListSplitTest, T19_SplitAroundPivotThenMergeRestoresSortedList) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{1, 4, 6, 8});
    auto [left, pivot, right] = split_around_pivot(std::move(list), 2);
    auto result = merge(merge(std::move(left), std::move(pivot)), std::move(right));
    test_linked_list_integrity(*result, {1, 4, 6, 8});
}
