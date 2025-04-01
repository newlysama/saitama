#include <gtest/gtest.h>
#include <linked_lists/linked_lists.hh>
#include <test_utils.hh>

class SplitTest : public ::testing::Test {};

/* ======================= SPLIT ======================= */

TEST_F(SplitTest, T01_SplitThrowsOnEmptyList) {
    auto list = std::make_unique<LinkedList>();
    EXPECT_THROW(LinkedList::split(std::move(list)), std::invalid_argument);
}

TEST_F(SplitTest, T02_SplitThrowsOnSizeOneList) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{42});
    EXPECT_THROW(LinkedList::split(std::move(list)), std::invalid_argument);
}

TEST_F(SplitTest, T03_SplitAtIndexZero) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{1, 2, 3});
    auto [left, right] = LinkedList::split(std::move(list), 0);
    test_linked_list_integrity(*left, {1});
    test_linked_list_integrity(*right, {2, 3});
}

TEST_F(SplitTest, T04_SplitAtEnd) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{4, 5, 6});
    auto [left, right] = LinkedList::split(std::move(list), 2);
    test_linked_list_integrity(*left, {4, 5});
    test_linked_list_integrity(*right, {6});
}

TEST_F(SplitTest, T05_SplitEvenLength) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{10, 20, 30, 40});
    auto [left, right] = LinkedList::split(std::move(list));
    test_linked_list_integrity(*left, {10, 20});
    test_linked_list_integrity(*right, {30, 40});
}

TEST_F(SplitTest, T06_SplitOddLength) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{1, 2, 3, 4, 5});
    auto [left, right] = LinkedList::split(std::move(list));
    test_linked_list_integrity(*left, {1, 2});
    test_linked_list_integrity(*right, {3, 4, 5});
}

TEST_F(SplitTest, T07_SplitAtCustomIndex) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{1, 3, 5, 7, 9});
    auto [left, right] = LinkedList::split(std::move(list), 3);
    test_linked_list_integrity(*left, {1, 3, 5});
    test_linked_list_integrity(*right, {7, 9});
}

TEST_F(SplitTest, T08_SplitOutOfBoundsThrows) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{1, 2});
    EXPECT_THROW(LinkedList::split(std::move(list), 5), std::invalid_argument);
}

/* ================= SPLIT AROUND PIVOT ================= */

TEST_F(SplitTest, T09_SplitAroundPivotThrowsOnEmpty) {
    auto list = std::make_unique<LinkedList>();
    EXPECT_THROW(LinkedList::split_around_pivot(std::move(list), 0), std::invalid_argument);
}

TEST_F(SplitTest, T10_SplitAroundPivotThrowsOnSizeOne) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{99});
    EXPECT_THROW(LinkedList::split_around_pivot(std::move(list), 0), std::invalid_argument);
}

TEST_F(SplitTest, T11_SplitAroundPivotAtZero) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{1, 2, 3});
    auto [left, pivot, right] = LinkedList::split_around_pivot(std::move(list), 0);
    test_linked_list_integrity(*left, {});
    test_linked_list_integrity(*pivot, {1});
    test_linked_list_integrity(*right, {2, 3});
}

TEST_F(SplitTest, T12_SplitAroundPivotAtLastIndex) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{4, 5, 6});
    auto [left, pivot, right] = LinkedList::split_around_pivot(std::move(list), 2);
    test_linked_list_integrity(*left, {4, 5});
    test_linked_list_integrity(*pivot, {6});
    test_linked_list_integrity(*right, {});
}

TEST_F(SplitTest, T13_SplitAroundPivotMiddleEven) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{10, 20, 30, 40});
    auto [left, pivot, right] = LinkedList::split_around_pivot(std::move(list), 2);
    test_linked_list_integrity(*left, {10, 20});
    test_linked_list_integrity(*pivot, {30});
    test_linked_list_integrity(*right, {40});
}

TEST_F(SplitTest, T14_SplitAroundPivotMiddleOdd) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{1, 3, 5, 7, 9});
    auto [left, pivot, right] = LinkedList::split_around_pivot(std::move(list), 2);
    test_linked_list_integrity(*left, {1, 3});
    test_linked_list_integrity(*pivot, {5});
    test_linked_list_integrity(*right, {7, 9});
}

TEST_F(SplitTest, T15_SplitAroundPivotOutOfBoundsThrows) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{1, 2});
    EXPECT_THROW(LinkedList::split_around_pivot(std::move(list), 5), std::invalid_argument);
}
