#include <gtest/gtest.h>
#include <linked_lists/linked_lists.hh>
#include <linked_lists/linked_lists_algorithms.hh>
#include <quicksort_mergesort/pivot.hh>
#include <test_utils.hh>

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

/*
 * ======================== partition_lomuto ========================
 */

 TEST_F(LinkedListPartitionTest, T01_Lomuto_SortedList) {
    auto list = LinkedList(std::vector<size_t>{1, 2, 3, 4, 5});
    partition_lomuto(list, 0, 4);
    test_linked_list_integrity(list, {1, 2, 3, 4, 5});
}

TEST_F(LinkedListPartitionTest, T02_Lomuto_UnsortedList) {
    auto list = LinkedList(std::vector<size_t>{1, 3, 5, 4, 2});
    partition_lomuto(list, 0, 4);
    test_linked_list_integrity(list, expected_unsorted_lomuto);
}

TEST_F(LinkedListPartitionTest, T03_Lomuto_ReversedList) {
    auto list = LinkedList(std::vector<size_t>{5, 4, 3, 2, 1});
    partition_lomuto(list, 0, 4);
    test_linked_list_integrity(list, expected_reversed_lomuto);
}

TEST_F(LinkedListPartitionTest, T04_Lomuto_Duplicates) {
    auto list = LinkedList(std::vector<size_t>{3, 3, 3, 3, 3});
    partition_lomuto(list, 0, 4);
    test_linked_list_integrity(list, {3, 3, 3, 3, 3});
}

TEST_F(LinkedListPartitionTest, T06_Lomuto_TwoElementsSorted) {
    auto list = LinkedList(std::vector<size_t>{1, 2});
    partition_lomuto(list, 0, 1);
    test_linked_list_integrity(list, {1, 2});
}

TEST_F(LinkedListPartitionTest, T07_Lomuto_TwoElementsUnsorted) {
    auto list = LinkedList(std::vector<size_t>{2, 1});
    partition_lomuto(list, 0, 1);
    test_linked_list_integrity(list, {1, 2});
}

TEST_F(LinkedListPartitionTest, T08_Lomuto_InvalidLowHigh) {
    auto list = LinkedList(std::vector<size_t>{1, 2, 3});
    EXPECT_THROW(partition_lomuto(list, 2, 2), std::invalid_argument);
}

TEST_F(LinkedListPartitionTest, T09_Lomuto_HighOutOfBounds) {
    auto list = LinkedList(std::vector<size_t>{1, 2, 3});
    EXPECT_THROW(partition_lomuto(list, 0, 5), std::invalid_argument);
}

/*
 * ======================== partition_hoare ========================
 */

TEST_F(LinkedListPartitionTest, T10_Hoare_SortedList) {
    auto list = LinkedList(std::vector<size_t>{1, 2, 3, 4, 5});
    partition_hoare(list, 0, 4);
    test_linked_list_integrity(list, {1, 2, 3, 4, 5});
}

TEST_F(LinkedListPartitionTest, T11_Hoare_UnsortedList) {
    auto list = LinkedList(std::vector<size_t>{1, 3, 5, 4, 2});
    partition_hoare(list, 0, 4);
    test_linked_list_integrity(list, expected_unsorted_hoare);
}

TEST_F(LinkedListPartitionTest, T12_Hoare_ReversedList) {
    auto list = LinkedList(std::vector<size_t>{5, 4, 3, 2, 1});
    partition_hoare(list, 0, 4);
    test_linked_list_integrity(list, expected_reversed_hoare);
}

TEST_F(LinkedListPartitionTest, T13_Hoare_Duplicates) {
    auto list = LinkedList(std::vector<size_t>{3, 3, 3, 3, 3});
    partition_hoare(list, 0, 4);
    test_linked_list_integrity(list, {3, 3, 3, 3, 3});
}

TEST_F(LinkedListPartitionTest, T15_Hoare_TwoElementsSorted) {
    auto list = LinkedList(std::vector<size_t>{1, 2});
    partition_hoare(list, 0, 1);
    test_linked_list_integrity(list, {1, 2});
}

TEST_F(LinkedListPartitionTest, T16_Hoare_TwoElementsUnsorted) {
    auto list = LinkedList(std::vector<size_t>{2, 1});
    partition_hoare(list, 0, 1);
    test_linked_list_integrity(list, {1, 2});
}

TEST_F(LinkedListPartitionTest, T17_Hoare_InvalidLowHigh) {
    auto list = LinkedList(std::vector<size_t>{1, 2, 3});
    EXPECT_THROW(partition_hoare(list, 3, 2), std::invalid_argument);
}

TEST_F(LinkedListPartitionTest, T18_Hoare_HighOutOfBounds) {
    auto list = LinkedList(std::vector<size_t>{1, 2, 3});
    EXPECT_THROW(partition_hoare(list, 0, 5), std::invalid_argument);
}
