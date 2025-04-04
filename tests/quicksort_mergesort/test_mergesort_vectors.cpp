#include <gtest/gtest.h>

#include "test_selector.hh"
#include "utils/vector_utils/vector_utils.hh"
#include "exos/quicksort_mergesort/merge_sort.hh"

#ifdef MERGE_SORT_VECTORS

class VectorsMergeSortTest : public ::testing::Test {};

TEST_F(VectorsMergeSortTest, T01_EmptyList) {
    std::vector<size_t> list = {};
    auto res = merge_sort(list);
    EXPECT_EQ(res, std::vector<size_t>({}));
}

TEST_F(VectorsMergeSortTest, T02_SingleElement) {
    std::vector<size_t> list = {42};
    auto res = merge_sort(list);
    EXPECT_EQ(res, std::vector<size_t>({42}));
}

TEST_F(VectorsMergeSortTest, T03_RandomValues) {
    std::vector<size_t> list = {5, 2, 1, 4, 3};
    auto res = merge_sort(list);
    EXPECT_EQ(res, std::vector<size_t>({1, 2, 3, 4, 5}));
}


TEST_F(VectorsMergeSortTest, T04_AlreadySorted) {
    std::vector<size_t> list = {1, 2, 3, 4, 5};
    auto res = merge_sort(list);
    EXPECT_EQ(res, std::vector<size_t>({1, 2, 3, 4, 5}));
}

TEST_F(VectorsMergeSortTest, T05_ReverseSorted) {
    std::vector<size_t> list = {5, 4, 3, 2, 1};
    auto res = merge_sort(list);
    EXPECT_EQ(res, std::vector<size_t>({1, 2, 3, 4, 5}));
}

#endif