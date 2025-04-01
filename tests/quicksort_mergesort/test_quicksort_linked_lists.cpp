#include <gtest/gtest.h>
#include <linked_lists/linked_lists.hh>
#include <quicksort_mergesort/quick_sort.hh>
#include <test_utils.hh>

class LinkedListQuickSortTest : public ::testing::Test {};

/*
 * ======================== quick_sort_lomuto ========================
 */

TEST_F(LinkedListQuickSortTest, T01_Lomuto_EmptyList) {
    auto list = std::make_unique<LinkedList>();
    quick_sort_lomuto(list);
    test_linked_list_integrity(*list, {});
}

TEST_F(LinkedListQuickSortTest, T02_Lomuto_SingleElement) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{42});
    quick_sort_lomuto(list);
    test_linked_list_integrity(*list, {42});
}

TEST_F(LinkedListQuickSortTest, T03_Lomuto_RandomValues) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{5, 2, 1, 4, 3});
    quick_sort_lomuto(list);
    test_linked_list_integrity(*list, {1, 2, 3, 4, 5});
}


TEST_F(LinkedListQuickSortTest, T04_Lomuto_AlreadySorted) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{1, 2, 3, 4, 5});
    quick_sort_lomuto(list);
    test_linked_list_integrity(*list, {1, 2, 3, 4, 5});
}

TEST_F(LinkedListQuickSortTest, T05_Lomuto_ReverseSorted) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{5, 4, 3, 2, 1});
    quick_sort_lomuto(list);
    test_linked_list_integrity(*list, {1, 2, 3, 4, 5});
}

/*
 * ======================== quick_sort_hoare ========================
 */

TEST_F(LinkedListQuickSortTest, T06_Hoare_EmptyList) {
    auto list = std::make_unique<LinkedList>();
    quick_sort_hoare(list);
    test_linked_list_integrity(*list, {});
}

TEST_F(LinkedListQuickSortTest, T07_Hoare_SingleElement) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{99});
    quick_sort_hoare(list);
    test_linked_list_integrity(*list, {99});
}

TEST_F(LinkedListQuickSortTest, T08_Hoare_RandomValues) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{5, 2, 1, 4, 3});
    quick_sort_hoare(list);
    test_linked_list_integrity(*list, {1, 2, 3, 4, 5});
}


TEST_F(LinkedListQuickSortTest, T09_Hoare_AlreadySorted) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{10, 20, 30, 40});
    quick_sort_hoare(list);
    test_linked_list_integrity(*list, {10, 20, 30, 40});
}

TEST_F(LinkedListQuickSortTest, T10_Hoare_ReverseSorted) {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{9, 7, 5, 3, 1});
    quick_sort_hoare(list);
    test_linked_list_integrity(*list, {1, 3, 5, 7, 9});
}
