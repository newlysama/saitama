#include <gtest/gtest.h>

#include "test_selector.hh"
#include "tests/test_utils.hh"
#include "utils/linked_lists/linked_lists.hh"
#include "exos/quicksort_mergesort/quick_sort.hh"

class LinkedListQuickSortTest : public ::testing::Test {};

#ifdef QUICK_SORT_LOMUTO_LINKED_LISTS

/*
 * ======================== quick_sort_lomuto ========================
 */

TEST_F(LinkedListQuickSortTest, T01_Lomuto_EmptyList) {
    LinkedList list;
    quick_sort_lomuto(list);
    test_linked_list_integrity(list, {});
}

TEST_F(LinkedListQuickSortTest, T02_Lomuto_SingleElement) {
    LinkedList list({42});
    quick_sort_lomuto(list);
    test_linked_list_integrity(list, {42});
}

TEST_F(LinkedListQuickSortTest, T03_Lomuto_RandomValues) {
    LinkedList list({5, 2, 1, 4, 3});
    quick_sort_lomuto(list);
    test_linked_list_integrity(list, {1, 2, 3, 4, 5});
}

TEST_F(LinkedListQuickSortTest, T04_Lomuto_AlreadySorted) {
    LinkedList list({1, 2, 3, 4, 5});
    quick_sort_lomuto(list);
    test_linked_list_integrity(list, {1, 2, 3, 4, 5});
}

TEST_F(LinkedListQuickSortTest, T05_Lomuto_ReverseSorted) {
    LinkedList list({5, 4, 3, 2, 1});
    quick_sort_lomuto(list);
    test_linked_list_integrity(list, {1, 2, 3, 4, 5});
}

TEST_F(LinkedListQuickSortTest, T06_Lomuto_WithDuplicates) {
    LinkedList list({4, 2, 4, 1, 4});
    quick_sort_lomuto(list);
    test_linked_list_integrity(list, {1, 2, 4, 4, 4});
}

TEST_F(LinkedListQuickSortTest, T07_Lomuto_AllEqual) {
    LinkedList list({7, 7, 7, 7});
    quick_sort_lomuto(list);
    test_linked_list_integrity(list, {7, 7, 7, 7});
}

#endif

#ifdef QUICK_SORT_HOARE_LINKED_LISTS

/*
 * ======================== quick_sort_hoare ========================
 */

TEST_F(LinkedListQuickSortTest, T08_Hoare_EmptyList) {
    LinkedList list;
    quick_sort_hoare(list);
    test_linked_list_integrity(list, {});
}

TEST_F(LinkedListQuickSortTest, T09_Hoare_SingleElement) {
    LinkedList list({99});
    quick_sort_hoare(list);
    test_linked_list_integrity(list, {99});
}

TEST_F(LinkedListQuickSortTest, T10_Hoare_RandomValues) {
    LinkedList list({5, 2, 1, 4, 3});
    quick_sort_hoare(list);
    test_linked_list_integrity(list, {1, 2, 3, 4, 5});
}

TEST_F(LinkedListQuickSortTest, T11_Hoare_AlreadySorted) {
    LinkedList list({10, 20, 30, 40});
    quick_sort_hoare(list);
    test_linked_list_integrity(list, {10, 20, 30, 40});
}

TEST_F(LinkedListQuickSortTest, T12_Hoare_ReverseSorted) {
    LinkedList list({9, 7, 5, 3, 1});
    quick_sort_hoare(list);
    test_linked_list_integrity(list, {1, 3, 5, 7, 9});
}

TEST_F(LinkedListQuickSortTest, T13_Hoare_WithDuplicates) {
    LinkedList list({4, 2, 4, 1, 4});
    quick_sort_hoare(list);
    test_linked_list_integrity(list, {1, 2, 4, 4, 4});
}

TEST_F(LinkedListQuickSortTest, T14_Hoare_AllEqual) {
    LinkedList list({7, 7, 7, 7});
    quick_sort_hoare(list);
    test_linked_list_integrity(list, {7, 7, 7, 7});
}

#endif