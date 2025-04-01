#include <gtest/gtest.h>
#include <linked_lists/linked_lists.hh>
#include <test_utils.hh>

class PartitionTest : public ::testing::Test {};

/*
 * ======================== partition_lomuto ========================
 */

TEST_F(PartitionTest, T01_Lomuto_SortedList) {
    LinkedList list({1, 2, 3, 4, 5});
    size_t pivot = list.partition_lomuto(0, 4);
    EXPECT_EQ(pivot, 4);
    test_linked_list_integrity(list, {1, 2, 3, 4, 5});
}

TEST_F(PartitionTest, T02_Lomuto_ReversedList) {
    LinkedList list({5, 4, 3, 2, 1});
    size_t pivot = list.partition_lomuto(0, 4);
    EXPECT_EQ(pivot, 0);
    test_linked_list_integrity(list, {1, 4, 3, 2, 5});
}

TEST_F(PartitionTest, T03_Lomuto_Duplicates) {
    LinkedList list({3, 3, 3, 3, 3});
    size_t pivot = list.partition_lomuto(0, 4);
    EXPECT_EQ(pivot, 0);
    test_linked_list_integrity(list, {3, 3, 3, 3, 3});
}

TEST_F(PartitionTest, T04_Lomuto_AlreadyPartitioned) {
    LinkedList list({1, 4, 3, 2, 5});
    size_t pivot = list.partition_lomuto(0, 4);
    EXPECT_EQ(pivot, 4);
    test_linked_list_integrity(list, {1, 4, 3, 2, 5});
}

TEST_F(PartitionTest, T05_Lomuto_TwoElementsSorted) {
    LinkedList list({1, 2});
    size_t pivot = list.partition_lomuto(0, 1);
    EXPECT_EQ(pivot, 1);
    test_linked_list_integrity(list, {1, 2});
}

TEST_F(PartitionTest, T06_Lomuto_TwoElementsUnsorted) {
    LinkedList list({2, 1});
    size_t pivot = list.partition_lomuto(0, 1);
    EXPECT_EQ(pivot, 0);
    test_linked_list_integrity(list, {1, 2});
}

TEST_F(PartitionTest, T07_Lomuto_InvalidLowHigh) {
    LinkedList list({1, 2, 3});
    EXPECT_THROW(list.partition_lomuto(2, 2), std::invalid_argument);
}

TEST_F(PartitionTest, T08_Lomuto_HighOutOfBounds) {
    LinkedList list({1, 2, 3});
    EXPECT_THROW(list.partition_lomuto(0, 5), std::invalid_argument);
}

/*
 * ======================== partition_hoare ========================
 */

 TEST_F(PartitionTest, T09_Hoare_SortedList) {
    LinkedList list({1, 2, 3, 4, 5});
    size_t pivot = list.partition_hoare(0, 4);
    EXPECT_TRUE(pivot < 4);
    test_linked_list_integrity(list, {1, 2, 3, 4, 5});
}

TEST_F(PartitionTest, T10_Hoare_ReversedList) {
    LinkedList list({5, 4, 3, 2, 1});
    size_t pivot = list.partition_hoare(0, 4);
    EXPECT_TRUE(pivot < 4);
    test_linked_list_integrity(list, {1, 4, 3, 2, 5});
}

TEST_F(PartitionTest, T11_Hoare_Duplicates) {
    LinkedList list({4, 1, 4, 4, 3, 4});
    size_t pivot = list.partition_hoare(0, 5);
    EXPECT_TRUE(pivot <= 5);
    test_linked_list_integrity(list, {4, 1, 3, 4, 4, 4});
}

TEST_F(PartitionTest, T12_Hoare_InvalidLowHigh) {
    LinkedList list({1, 2, 3});
    EXPECT_THROW(list.partition_hoare(3, 2), std::invalid_argument);
}

TEST_F(PartitionTest, T13_Hoare_HighOutOfBounds) {
    LinkedList list({1, 2, 3});
    EXPECT_THROW(list.partition_hoare(0, 5), std::invalid_argument);
}
