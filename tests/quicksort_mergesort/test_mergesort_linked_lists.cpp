#include <gtest/gtest.h>

#include "test_selector.hh"
#include "tests/test_utils.hh"
#include "utils/linked_lists/linked_lists.hh"
#include "exos/quicksort_mergesort/merge_sort.hh"

#ifdef MERGE_SORT_LINKED_LISTS

class LinkedListMergeSortTest : public ::testing::Test {};


TEST_F(LinkedListMergeSortTest, T01_EmptyList) {
    LinkedList list;
    merge_sort(list);
    test_linked_list_integrity(list, {});
}

TEST_F(LinkedListMergeSortTest, T02_SingleElement) {
    LinkedList list({42});
    merge_sort(list);
    test_linked_list_integrity(list, {42});
}

TEST_F(LinkedListMergeSortTest, T03_RandomValues) {
    LinkedList list({5, 2, 1, 4, 3});
    merge_sort(list);
    test_linked_list_integrity(list, {1, 2, 3, 4, 5});
}


TEST_F(LinkedListMergeSortTest, T04_AlreadySorted) {
    LinkedList list({1, 2, 3, 4, 5});
    merge_sort(list);
    test_linked_list_integrity(list, {1, 2, 3, 4, 5});
}

TEST_F(LinkedListMergeSortTest, T05_ReverseSorted) {
    LinkedList list({5, 4, 3, 2, 1});
    merge_sort(list);
    test_linked_list_integrity(list, {1, 2, 3, 4, 5});
}

#endif