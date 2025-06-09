#include "test_config.hh"

using namespace VectorUtils;
using ScalableVector = std::vector<size_t, tbb::scalable_allocator<size_t>>;

#if PIVOT != RANDOM // since random pivot gives unpredictable result

class VectorPartitionTest : public ::testing::Test {
protected:

    ScalableVector expected_unsorted_lomuto;
    ScalableVector expected_reversed_lomuto;
    ScalableVector expected_unsorted_hoare;
    ScalableVector expected_reversed_hoare;

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

#ifdef PARTITION_LOMUTO

TEST_F(VectorPartitionTest, T01_Lomuto_SortedList) {
    ScalableVector vec({1, 2, 3, 4, 5});
    partition_lomuto(vec, 0, vec.size() - 1);

    ScalableVector expected;
    expected = {1, 2, 3, 4, 5};

    EXPECT_EQ(vec, expected);
}

TEST_F(VectorPartitionTest, T02_Lomuto_UnsortedList) {
    ScalableVector vec({1, 3, 5, 4, 2});
    partition_lomuto(vec, 0, vec.size() - 1);
    EXPECT_EQ(vec, expected_unsorted_lomuto);
}

TEST_F(VectorPartitionTest, T03_Lomuto_ReversedList) {
    ScalableVector vec({5, 4, 3, 2, 1});
    partition_lomuto(vec, 0, vec.size() - 1);
    EXPECT_EQ(vec, expected_reversed_lomuto);
}

TEST_F(VectorPartitionTest, T04_Lomuto_Duplicates) {
    ScalableVector vec({3, 3, 3, 3, 3});
    partition_lomuto(vec, 0, vec.size() - 1);

    ScalableVector expected;
    expected = {3, 3, 3, 3, 3};

    EXPECT_EQ(vec, expected);
}

TEST_F(VectorPartitionTest, T05_Lomuto_TwoElementsSorted) {
    ScalableVector vec({1, 2});
    partition_lomuto(vec, 0, vec.size() - 1);

    ScalableVector expected;
    expected = {1, 2};

    EXPECT_EQ(vec, expected);
}

TEST_F(VectorPartitionTest, T06_Lomuto_TwoElementsUnsorted) {
    ScalableVector vec({2, 1});
    partition_lomuto(vec, 0, vec.size() - 1);

    ScalableVector expected;
    expected = {1, 2};

    EXPECT_EQ(vec, expected);
}

TEST_F(VectorPartitionTest, T07_Lomuto_InvalidLowHigh) {
    ScalableVector vec({1, 2, 3});
    EXPECT_THROW(partition_lomuto(vec, 2, 2), std::invalid_argument);
}

TEST_F(VectorPartitionTest, T08_Lomuto_HighOutOfBounds) {
    ScalableVector vec({1, 2, 3});
    EXPECT_THROW(partition_lomuto(vec, 0, 5), std::invalid_argument);
}

#endif

#ifdef PARTITION_HOARE

TEST_F(VectorPartitionTest, T09_Hoare_SortedList) {
    ScalableVector vec({1, 2, 3, 4, 5});
    partition_hoare(vec, 0, vec.size() - 1);

    ScalableVector expected;
    expected = {1, 2, 3, 4, 5};

    EXPECT_EQ(vec, expected);
}

TEST_F(VectorPartitionTest, T10_Hoare_UnsortedList) {
    ScalableVector vec({1, 3, 5, 4, 2});
    partition_hoare(vec, 0, vec.size() - 1);
    EXPECT_EQ(vec, expected_unsorted_hoare);
}

TEST_F(VectorPartitionTest, T11_Hoare_ReversedList) {
    ScalableVector vec({5, 4, 3, 2, 1});
    partition_hoare(vec, 0, vec.size() - 1);
    EXPECT_EQ(vec, expected_reversed_hoare);
}

TEST_F(VectorPartitionTest, T12_Hoare_Duplicates) {
    ScalableVector vec({3, 3, 3, 3, 3});
    partition_hoare(vec, 0, vec.size() - 1);

    ScalableVector expected;
    expected = {3, 3, 3, 3, 3};

    EXPECT_EQ(vec, expected);
}

TEST_F(VectorPartitionTest, T13_Hoare_TwoElementsSorted) {
    ScalableVector vec({1, 2});
    partition_hoare(vec, 0, vec.size() - 1);

    ScalableVector expected;
    expected = {1, 2};

    EXPECT_EQ(vec, expected);
}

TEST_F(VectorPartitionTest, T14_Hoare_TwoElementsUnsorted) {
    ScalableVector vec({2, 1});
    partition_hoare(vec, 0, vec.size() - 1);

    ScalableVector expected;
    expected = {1, 2};

    EXPECT_EQ(vec, expected);
}

TEST_F(VectorPartitionTest, T15_Hoare_InvalidLowHigh) {
    ScalableVector vec({1, 2, 3});
    EXPECT_THROW(partition_hoare(vec, 3, 2), std::invalid_argument);
}

TEST_F(VectorPartitionTest, T16_Hoare_HighOutOfBounds) {
    ScalableVector vec({1, 2, 3});
    EXPECT_THROW(partition_hoare(vec, 0, 5), std::invalid_argument);
}

#endif

#endif // PIVOT != RANDOM
