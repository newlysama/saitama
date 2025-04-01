#include <gtest/gtest.h>
#include <vector_utils/vector_utils.hh>
#include <quicksort_mergesort/quick_sort.hh>
#include <test_utils.hh>

class VectorsQuickSortTest : public ::testing::Test {};

/*
 * ======================== quick_sort_lomuto ========================
 */

TEST_F(VectorsQuickSortTest, T01_Lomuto_EmptyList) {
    std::vector<size_t> list = {};
    quick_sort_lomuto(list);
    EXPECT_EQ(list, std::vector<size_t>({}));
}

TEST_F(VectorsQuickSortTest, T02_Lomuto_SingleElement) {
    std::vector<size_t> list = {42};
    quick_sort_lomuto(list);
    EXPECT_EQ(list, std::vector<size_t>({42}));
}

TEST_F(VectorsQuickSortTest, T03_Lomuto_RandomValues) {
    std::vector<size_t> list = {5, 2, 1, 4, 3};
    quick_sort_lomuto(list);
    EXPECT_EQ(list, std::vector<size_t>({1, 2, 3, 4, 5}));
}


TEST_F(VectorsQuickSortTest, T04_Lomuto_AlreadySorted) {
    std::vector<size_t> list = {1, 2, 3, 4, 5};
    quick_sort_lomuto(list);
    EXPECT_EQ(list, std::vector<size_t>({1, 2, 3, 4, 5}));
}

TEST_F(VectorsQuickSortTest, T05_Lomuto_ReverseSorted) {
    std::vector<size_t> list = {5, 4, 3, 2, 1};
    quick_sort_lomuto(list);
    EXPECT_EQ(list, std::vector<size_t>({1, 2, 3, 4, 5}));
}

/*
 * ======================== quick_sort_hoare ========================
 */

TEST_F(VectorsQuickSortTest, T06_Hoare_EmptyList) {
    std::vector<size_t> list = {};
    quick_sort_hoare(list);
    EXPECT_EQ(list, std::vector<size_t>({}));
}

TEST_F(VectorsQuickSortTest, T07_Hoare_SingleElement) {
    std::vector<size_t> list = {99};
    quick_sort_hoare(list);
    EXPECT_EQ(list, std::vector<size_t>({99}));
}

TEST_F(VectorsQuickSortTest, T08_Hoare_RandomValues) {
    std::vector<size_t> list = {5, 2, 1, 4, 3};
    quick_sort_hoare(list);
    EXPECT_EQ(list, std::vector<size_t>({1, 2, 3, 4, 5}));
}


TEST_F(VectorsQuickSortTest, T09_Hoare_AlreadySorted) {
    std::vector<size_t> list = {10, 20, 30, 40};
    quick_sort_hoare(list);
    EXPECT_EQ(list, std::vector<size_t>({10, 20, 30, 40}));
}

TEST_F(VectorsQuickSortTest, T10_Hoare_ReverseSorted) {
    std::vector<size_t> list = {9, 7, 5, 3, 1};
    quick_sort_hoare(list);
    EXPECT_EQ(list, std::vector<size_t>({1, 3, 5, 7, 9}));
}
