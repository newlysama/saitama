#include "test_config.hh"

using namespace VectorUtils;
using ScalableVector = std::vector<size_t, tbb::scalable_allocator<size_t>>;

#ifdef SPLIT

class VectorSplitTest : public ::testing::Test {};

TEST_F(VectorSplitTest, T01_SplitThrowsOnEmptyVector) {
    ScalableVector vec;
    EXPECT_THROW(split(vec), std::invalid_argument);
}

TEST_F(VectorSplitTest, T02_SplitThrowsOnSizeOneVector) {
    ScalableVector vec({42});
    EXPECT_THROW(split(vec), std::invalid_argument);
}

TEST_F(VectorSplitTest, T03_SplitEvenLength) {
    ScalableVector vec({10, 20, 30, 40});
    auto [left, right] = split(vec);

    ScalableVector expected_left;
    expected_left = {10, 20};
    ScalableVector expected_right;
    expected_right = {30, 40};

    EXPECT_EQ(left, expected_left);
    EXPECT_EQ(right, expected_right);
}

TEST_F(VectorSplitTest, T04_SplitOddLength) {
    ScalableVector vec({1, 2, 3, 4, 5});
    auto [left, right] = split(vec);

    ScalableVector expected_left;
    expected_left = {1, 2};
    ScalableVector expected_right;
    expected_right = {3, 4, 5};

    EXPECT_EQ(left, expected_left);
    EXPECT_EQ(right, expected_right);
}

#endif
