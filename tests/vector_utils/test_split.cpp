#include <gtest/gtest.h>

#include "utils/vector_utils/vector_utils.hh"

using namespace VectorUtils;

class VectorSplitTest : public ::testing::Test {};

/*
 * ======================== Vector Split ========================
 */

TEST_F(VectorSplitTest, T01_SplitThrowsOnEmptyVector) {
    std::vector<size_t> vec = {};
    EXPECT_THROW(split(vec), std::invalid_argument);
}

TEST_F(VectorSplitTest, T02_SplitThrowsOnSizeOneVector) {
    std::vector<size_t> vec = {42};
    EXPECT_THROW(split(vec), std::invalid_argument);
}

TEST_F(VectorSplitTest, T03_SplitEvenLength) {
    std::vector<size_t> vec = {10, 20, 30, 40};
    auto [left, right] = split(vec);
    EXPECT_EQ(left, (std::vector<size_t>{10, 20}));
    EXPECT_EQ(right, (std::vector<size_t>{30, 40}));
}

TEST_F(VectorSplitTest, T04_SplitOddLength) {
    std::vector<size_t> vec = {1, 2, 3, 4, 5};
    auto [left, right] = split(vec);
    EXPECT_EQ(left, (std::vector<size_t>{1, 2}));
    EXPECT_EQ(right, (std::vector<size_t>{3, 4, 5}));
}