#include <gtest/gtest.h>

#include "test_selector.hh"
#include "tests/test_utils.hh" 
#include "utils/linked_lists/linked_lists.hh"
#include "utils/linked_lists/linked_lists_algorithms.hh"
#include "exos/quicksort_mergesort/pivot.hh"

using namespace LinkedListAlgorithm;

// Define relevant expected results before, since they depend on PIVOT mod
// Don't test random pivot since result is, of course, random x)
class LinkedListPartitionTest : public ::testing::Test {
protected:
    std::vector<size_t> expected_unsorted_lomuto;
    std::vector<size_t> expected_reversed_lomuto;

    std::vector<size_t> expected_reversed_hoare;
    std::vector<size_t> expected_unsorted_hoare;

    void SetUp() override {    
        #if PIVOT == FIRST
            expected_unsorted_lomuto = {1, 3, 5, 4, 2};
            expected_reversed_lomuto = {1, 4, 3, 2, 5};

            expected_unsorted_hoare = {1, 3, 5, 4, 2};
            expected_reversed_hoare = {1, 4, 3, 2, 5};

        #elif PIVOT == LAST
            expected_unsorted_lomuto = {1, 2, 5, 4, 3};
            expected_reversed_lomuto = {1, 4, 3, 2, 5};

            expected_unsorted_hoare = {1, 3, 5, 4, 2};
            expected_reversed_hoare = {1, 4, 3, 2, 5};

        #elif PIVOT == MID
            expected_unsorted_lomuto = {1, 3, 2, 4, 5};
            expected_reversed_lomuto = {1, 2, 3, 4, 5};

            expected_unsorted_hoare = {2, 3, 1, 4, 5};
            expected_reversed_hoare = {1, 2, 5, 4, 3};

        #else
            throw std::invalid_argument("Unsupported pivot strategy for partition testing.");
        #endif
    }
};

#if PIVOT != RANDOM // Since random pivot is unpredictable

#ifdef PARTITION_LOMUTO

/*
 * ======================== partition_lomuto ========================
 */

 TEST_F(LinkedListPartitionTest, T01_Lomuto_SortedList) {
    LinkedList list({1, 2, 3, 4, 5});
    partition_lomuto(list);
    test_linked_list_integrity(list, {1, 2, 3, 4, 5});
}

TEST_F(LinkedListPartitionTest, T02_Lomuto_UnsortedList) {
    LinkedList list({1, 3, 5, 4, 2});
    partition_lomuto(list);
    test_linked_list_integrity(list, expected_unsorted_lomuto);
}

TEST_F(LinkedListPartitionTest, T03_Lomuto_ReversedList) {
    LinkedList list({5, 4, 3, 2, 1});
    partition_lomuto(list);
    test_linked_list_integrity(list, expected_reversed_lomuto);
}

TEST_F(LinkedListPartitionTest, T04_Lomuto_Duplicates) {
    LinkedList list({3, 3, 3, 3, 3});
    partition_lomuto(list);
    test_linked_list_integrity(list, {3, 3, 3, 3, 3});
}

TEST_F(LinkedListPartitionTest, T05_Lomuto_TwoElementsSorted) {
    LinkedList list({1, 2});
    partition_lomuto(list);
    test_linked_list_integrity(list, {1, 2});
}

TEST_F(LinkedListPartitionTest, T06_Lomuto_TwoElementsUnsorted) {
    LinkedList list({2, 1});
    partition_lomuto(list);
    test_linked_list_integrity(list, {1, 2});
}

#endif

#ifdef PARTITION_HOARE

/*
 * ======================== partition_hoare ========================
 */

TEST_F(LinkedListPartitionTest, T7_Hoare_SortedList) {
    LinkedList list({1, 2, 3, 4, 5});
    partition_hoare(list);
    test_linked_list_integrity(list, {1, 2, 3, 4, 5});
}

TEST_F(LinkedListPartitionTest, T8_Hoare_UnsortedList) {
    LinkedList list({1, 3, 5, 4, 2});
    partition_hoare(list);
    test_linked_list_integrity(list, expected_unsorted_hoare);
}

TEST_F(LinkedListPartitionTest, T9_Hoare_ReversedList) {
    LinkedList list({5, 4, 3, 2, 1});
    partition_hoare(list);
    test_linked_list_integrity(list, expected_reversed_hoare);
}

TEST_F(LinkedListPartitionTest, T10_Hoare_Duplicates) {
    LinkedList list({3, 3, 3, 3, 3});
    partition_hoare(list);
    test_linked_list_integrity(list, {3, 3, 3, 3, 3});
}

TEST_F(LinkedListPartitionTest, T11_Hoare_TwoElementsSorted) {
    LinkedList list({1, 2});
    partition_hoare(list);
    test_linked_list_integrity(list, {1, 2});
}

TEST_F(LinkedListPartitionTest, T12_Hoare_TwoElementsUnsorted) {
    LinkedList list({2, 1});
    partition_hoare(list);
    test_linked_list_integrity(list, {1, 2});
}

#endif

#endif