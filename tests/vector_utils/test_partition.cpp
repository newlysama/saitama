#include <gtest/gtest.h>

#include "utils/vector_utils/vector_utils.hh"
#include "exos/quicksort_mergesort/pivot.hh"

using namespace VectorUtils;

class VectorPartitionTest : public ::testing::Test {
protected:
    std::vector<size_t> expected_unsorted_lomuto;
    std::vector<size_t> expected_reversed_lomuto;

    std::vector<size_t> expected_unsorted_hoare;
    std::vector<size_t> expected_reversed_hoare;

    void SetUp() override {
        #if PIVOT == FIRST
            expected_unsorted_lomuto  = {1, 3, 5, 4, 2};
            expected_reversed_lomuto  = {1, 4, 3, 2, 5};
            expected_unsorted_hoare   = {1, 3, 5, 4, 2};
            expected_reversed_hoare   = {1, 4, 3, 2, 5};

        #elif PIVOT == LAST
            expected_unsorted_lomuto  = {1, 2, 5, 4, 3};
            expected_reversed_lomuto  = {1, 4, 3, 2, 5};
            expected_unsorted_hoare   = {1, 2, 5, 4, 3};
            expected_reversed_hoare   = {1, 4, 3, 2, 5};

        #elif PIVOT == MID
            expected_unsorted_lomuto  = {1, 3, 2, 4, 5};
            expected_reversed_lomuto  = {1, 2, 3, 4, 5};
            expected_unsorted_hoare   = {1, 3, 2, 4, 5};
            expected_reversed_hoare   = {3, 2, 1, 4, 5};
        #endif
    }
};

#if PIVOT != RANDOM // Since random pivot is unpredictable

/*
 * ======================== partition_lomuto ========================
 */

TEST_F(VectorPartitionTest, T01_Lomuto_SortedList) {
    std::vector<size_t> vec = {1, 2, 3, 4, 5};
    partition_lomuto(vec, 0, vec.size() - 1);
    EXPECT_EQ(vec, (std::vector<size_t>{1, 2, 3, 4, 5}));
}

TEST_F(VectorPartitionTest, T02_Lomuto_UnsortedList) {
    std::vector<size_t> vec = {1, 3, 5, 4, 2};
    partition_lomuto(vec, 0, vec.size() - 1);
    EXPECT_EQ(vec, expected_unsorted_lomuto);
}

TEST_F(VectorPartitionTest, T03_Lomuto_ReversedList) {
    std::vector<size_t> vec = {5, 4, 3, 2, 1};
    partition_lomuto(vec, 0, vec.size() - 1);
    EXPECT_EQ(vec, expected_reversed_lomuto);
}

TEST_F(VectorPartitionTest, T04_Lomuto_Duplicates) {
    std::vector<size_t> vec = {3, 3, 3, 3, 3};
    partition_lomuto(vec, 0, vec.size() - 1);
    EXPECT_EQ(vec, (std::vector<size_t>{3, 3, 3, 3, 3}));
}

TEST_F(VectorPartitionTest, T05_Lomuto_TwoElementsSorted) {
    std::vector<size_t> vec = {1, 2};
    partition_lomuto(vec, 0, vec.size() - 1);
    EXPECT_EQ(vec, (std::vector<size_t>{1, 2}));
}

TEST_F(VectorPartitionTest, T06_Lomuto_TwoElementsUnsorted) {
    std::vector<size_t> vec = {2, 1};
    partition_lomuto(vec, 0, vec.size() - 1);
    EXPECT_EQ(vec, (std::vector<size_t>{1, 2}));
}

TEST_F(VectorPartitionTest, T07_Lomuto_InvalidLowHigh) {
    std::vector<size_t> vec = {1, 2, 3};
    EXPECT_THROW(partition_lomuto(vec, 2, 2), std::invalid_argument);
}

TEST_F(VectorPartitionTest, T08_Lomuto_HighOutOfBounds) {
    std::vector<size_t> vec = {1, 2, 3};
    EXPECT_THROW(partition_lomuto(vec, 0, 5), std::invalid_argument);
}

/*
 * ======================== partition_lomuto ========================
 */

TEST_F(VectorPartitionTest, T09_Hoare_SortedList) {
    std::vector<size_t> vec = {1, 2, 3, 4, 5};
    partition_hoare(vec, 0, vec.size() - 1);
    EXPECT_EQ(vec, (std::vector<size_t>{1, 2, 3, 4, 5}));
}

TEST_F(VectorPartitionTest, T10_Hoare_UnsortedList) {
    std::vector<size_t> vec = {1, 3, 5, 4, 2};
    partition_hoare(vec, 0, vec.size() - 1);
    EXPECT_EQ(vec, expected_unsorted_hoare);
}

TEST_F(VectorPartitionTest, T11_Hoare_ReversedList) {
    std::vector<size_t> vec = {5, 4, 3, 2, 1};
    partition_hoare(vec, 0, vec.size() - 1);
    EXPECT_EQ(vec, expected_reversed_hoare);
}

TEST_F(VectorPartitionTest, T12_Hoare_Duplicates) {
    std::vector<size_t> vec = {3, 3, 3, 3, 3};
    partition_hoare(vec, 0, vec.size() - 1);
    EXPECT_EQ(vec, (std::vector<size_t>{3, 3, 3, 3, 3}));
}

TEST_F(VectorPartitionTest, T13_Hoare_TwoElementsSorted) {
    std::vector<size_t> vec = {1, 2};
    partition_hoare(vec, 0, vec.size() - 1);
    EXPECT_EQ(vec, (std::vector<size_t>{1, 2}));
}

TEST_F(VectorPartitionTest, T14_Hoare_TwoElementsUnsorted) {
    std::vector<size_t> vec = {2, 1};
    partition_hoare(vec, 0, vec.size() - 1);
    EXPECT_EQ(vec, (std::vector<size_t>{1, 2}));
}

TEST_F(VectorPartitionTest, T15_Hoare_InvalidLowHigh) {
    std::vector<size_t> vec = {1, 2, 3};
    EXPECT_THROW(partition_hoare(vec, 3, 2), std::invalid_argument);
}

TEST_F(VectorPartitionTest, T16_Hoare_HighOutOfBounds) {
    std::vector<size_t> vec = {1, 2, 3};
    EXPECT_THROW(partition_hoare(vec, 0, 5), std::invalid_argument);
}

#endif