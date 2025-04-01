#include <gtest/gtest.h>
#include <linked_lists/linked_lists.hh>
#include <quicksort_mergesort/merge_sort.hh>
#include <test_utils.hh>

class LinkedListMergeSortTest : public ::testing::Test {};


TEST_F(LinkedListMergeSortTest, T01_EmptyList) {
    auto list = std::make_unique<LinkedList>();
    auto res = merge_sort(std::move(list));
    test_linked_list_integrity(*res, {});
}

TEST_F(LinkedListMergeSortTest, T02_SingleElement) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{42});
    auto res = merge_sort(std::move(list));
    test_linked_list_integrity(*res, {42});
}

TEST_F(LinkedListMergeSortTest, T03_RandomValues) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{5, 2, 1, 4, 3});
    auto res = merge_sort(std::move(list));
    test_linked_list_integrity(*res, {1, 2, 3, 4, 5});
}


TEST_F(LinkedListMergeSortTest, T04_AlreadySorted) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{1, 2, 3, 4, 5});
    auto res = merge_sort(std::move(list));
    test_linked_list_integrity(*res, {1, 2, 3, 4, 5});
}

TEST_F(LinkedListMergeSortTest, T05_ReverseSorted) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{5, 4, 3, 2, 1});
    auto res = merge_sort(std::move(list));
    test_linked_list_integrity(*res, {1, 2, 3, 4, 5});
}