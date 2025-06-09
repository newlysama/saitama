#include "test_config.hh"

using ScalableVector = std::vector<size_t, tbb::scalable_allocator<size_t>>;

#ifdef VECTORS

class VectorsQuickSortTest : public ::testing::Test {};

#ifdef QUICKSORT_LOMUTO

/*
 * ======================== quick_sort_lomuto ========================
 */

TEST_F(VectorsQuickSortTest, T01_Lomuto_EmptyList) {
    ScalableVector list;
    quick_sort_lomuto(list);
    ScalableVector expected;
    EXPECT_EQ(list, expected);
}

TEST_F(VectorsQuickSortTest, T02_Lomuto_SingleElement) {
    ScalableVector list({42});
    quick_sort_lomuto(list);
    ScalableVector expected;
    expected = {42};
    EXPECT_EQ(list, expected);
}

TEST_F(VectorsQuickSortTest, T03_Lomuto_RandomValues) {
    ScalableVector list({5, 2, 1, 4, 3});
    quick_sort_lomuto(list);
    ScalableVector expected;
    expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(list, expected);
}

TEST_F(VectorsQuickSortTest, T04_Lomuto_AlreadySorted) {
    ScalableVector list({1, 2, 3, 4, 5});
    quick_sort_lomuto(list);
    ScalableVector expected;
    expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(list, expected);
}

TEST_F(VectorsQuickSortTest, T05_Lomuto_ReverseSorted) {
    ScalableVector list({5, 4, 3, 2, 1});
    quick_sort_lomuto(list);
    ScalableVector expected;
    expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(list, expected);
}

#endif // QUICKSORT_LOMUTO

#ifdef QUICKSORT_HOARE

/*
 * ======================== quick_sort_hoare ========================
 */

TEST_F(VectorsQuickSortTest, T06_Hoare_EmptyList) {
    ScalableVector list;
    quick_sort_hoare(list);
    ScalableVector expected;
    EXPECT_EQ(list, expected);
}

TEST_F(VectorsQuickSortTest, T07_Hoare_SingleElement) {
    ScalableVector list({99});
    quick_sort_hoare(list);
    ScalableVector expected;
    expected = {99};
    EXPECT_EQ(list, expected);
}

TEST_F(VectorsQuickSortTest, T08_Hoare_RandomValues) {
    ScalableVector list({5, 2, 1, 4, 3});
    quick_sort_hoare(list);
    ScalableVector expected;
    expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(list, expected);
}

TEST_F(VectorsQuickSortTest, T09_Hoare_AlreadySorted) {
    ScalableVector list({10, 20, 30, 40});
    quick_sort_hoare(list);
    ScalableVector expected;
    expected = {10, 20, 30, 40};
    EXPECT_EQ(list, expected);
}

TEST_F(VectorsQuickSortTest, T10_Hoare_ReverseSorted) {
    ScalableVector list({9, 7, 5, 3, 1});
    quick_sort_hoare(list);
    ScalableVector expected;
    expected = {1, 3, 5, 7, 9};
    EXPECT_EQ(list, expected);
}

#endif // QUICKSORT_HOARE

#endif // VECTORS
