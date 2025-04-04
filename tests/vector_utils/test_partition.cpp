#include <gtest/gtest.h>

#include "utils/vector_utils/vector_utils.hh"

using namespace VectorUtils;

class VectorPartition : public ::testing::Test {};

/*
 * ======================== partition_lomuto ========================
 */

TEST_F(VectorPartition, T01_Lomuto_SortedList) {
    std::vector<size_t> vec = {1, 2, 3, 4, 5};
    size_t pivot = partition_lomuto(vec, 0, 4);
    EXPECT_EQ(pivot, 4);
    EXPECT_EQ(vec, (std::vector<size_t>{1, 2, 3, 4, 5}));
}

TEST_F(VectorPartition, T02_Lomuto_ReversedList) {
    std::vector<size_t> vec = {5, 4, 3, 2, 1};
    size_t pivot = partition_lomuto(vec, 0, 4);
    EXPECT_EQ(pivot, 0);
    EXPECT_EQ(vec, (std::vector<size_t>{1, 4, 3, 2, 5}));
}

TEST_F(VectorPartition, T03_Lomuto_Duplicates) {
    std::vector<size_t> vec = {3, 3, 3, 3, 3};
    size_t pivot = partition_lomuto(vec, 0, 4);
    EXPECT_EQ(pivot, 4);
    EXPECT_EQ(vec, (std::vector<size_t>{3, 3, 3, 3, 3}));
}

TEST_F(VectorPartition, T04_Lomuto_AlreadyPartitioned) {
    std::vector<size_t> vec = {1, 4, 3, 2, 5};
    size_t pivot = partition_lomuto(vec, 0, 4);
    EXPECT_EQ(pivot, 4);
    EXPECT_EQ(vec, (std::vector<size_t>{1, 4, 3, 2, 5}));
}

TEST_F(VectorPartition, T05_Lomuto_TwoElementsSorted) {
    std::vector<size_t> vec = {1, 2};
    size_t pivot = partition_lomuto(vec, 0, 1);
    EXPECT_EQ(pivot, 1);
    EXPECT_EQ(vec, (std::vector<size_t>{1, 2}));
}

TEST_F(VectorPartition, T06_Lomuto_TwoElementsUnsorted) {
    std::vector<size_t> vec = {2, 1};
    size_t pivot = partition_lomuto(vec, 0, 1);
    EXPECT_EQ(pivot, 0);
    EXPECT_EQ(vec, (std::vector<size_t>{1, 2}));
}

TEST_F(VectorPartition, T07_Lomuto_InvalidLowHigh) {
    std::vector<size_t> vec = {1, 2, 3};
    EXPECT_THROW(partition_lomuto(vec, 2, 2), std::invalid_argument);
}

TEST_F(VectorPartition, T08_Lomuto_HighOutOfBounds) {
    std::vector<size_t> vec = {1, 2, 3};
    EXPECT_THROW(partition_lomuto(vec, 0, 5), std::invalid_argument);
}

/*
 * ======================== partition_hoare ========================
 */

TEST_F(VectorPartition, T09_Hoare_SortedList) {
    std::vector<size_t> vec = {1, 2, 3, 4, 5};
    size_t pivot = partition_hoare(vec, 0, 4);
    EXPECT_TRUE(pivot < 4);
    EXPECT_EQ(vec, (std::vector<size_t>{1, 2, 3, 4, 5}));
}

TEST_F(VectorPartition, T10_Hoare_ReversedList) {
    std::vector<size_t> vec = {5, 4, 3, 2, 1};
    size_t pivot = partition_hoare(vec, 0, 4);
    EXPECT_TRUE(pivot < 4);
    EXPECT_EQ(vec, (std::vector<size_t>{1, 4, 3, 2, 5}));
}

TEST_F(VectorPartition, T11_Hoare_Duplicates) {
    std::vector<size_t> vec = {4, 1, 4, 4, 3, 4};
    size_t pivot = partition_hoare(vec, 0, 5);
    EXPECT_TRUE(pivot <= 5);
    EXPECT_EQ(vec, (std::vector<size_t>{4, 1, 3, 4, 4, 4}));
}

TEST_F(VectorPartition, T12_Hoare_InvalidLowHigh) {
    std::vector<size_t> vec = {1, 2, 3};
    EXPECT_THROW(partition_hoare(vec, 3, 2), std::invalid_argument);
}

TEST_F(VectorPartition, T13_Hoare_HighOutOfBounds) {
    std::vector<size_t> vec = {1, 2, 3};
    EXPECT_THROW(partition_hoare(vec, 0, 5), std::invalid_argument);
}
