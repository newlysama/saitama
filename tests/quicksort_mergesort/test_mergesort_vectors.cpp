#include "test_config.hh"

using ScalableVector = std::vector<size_t, tbb::scalable_allocator<size_t>>;

#ifdef VECTORS
#ifdef MERGESORT

class VectorsMergeSortTest : public ::testing::Test {};

TEST_F(VectorsMergeSortTest, T01_EmptyList) {
    ScalableVector list;
    auto res = merge_sort(list);

    ScalableVector expected;
    EXPECT_EQ(res, expected);
}

TEST_F(VectorsMergeSortTest, T02_SingleElement) {
    ScalableVector list({42});
    auto res = merge_sort(list);

    ScalableVector expected;
    expected = {42};
    EXPECT_EQ(res, expected);
}

TEST_F(VectorsMergeSortTest, T03_RandomValues) {
    ScalableVector list({5, 2, 1, 4, 3});
    auto res = merge_sort(list);

    ScalableVector expected;
    expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(res, expected);
}

TEST_F(VectorsMergeSortTest, T04_AlreadySorted) {
    ScalableVector list({1, 2, 3, 4, 5});
    auto res = merge_sort(list);

    ScalableVector expected;
    expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(res, expected);
}

TEST_F(VectorsMergeSortTest, T05_ReverseSorted) {
    ScalableVector list({5, 4, 3, 2, 1});
    auto res = merge_sort(list);

    ScalableVector expected;
    expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(res, expected);
}

#endif
#endif
