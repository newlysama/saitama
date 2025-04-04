#include <gtest/gtest.h>

#include "utils/vector_utils/vector_utils.hh"

using namespace VectorUtils;

class VectorMergeTest : public ::testing::Test {};

/*
 * ======================== Vector Merge ========================
 */

TEST_F(VectorMergeTest, T01_BothEmpty) {
    std::vector<size_t> list1 = {};
    std::vector<size_t> list2 = {};
    auto result = merge(list1, list2);
    EXPECT_EQ(result, std::vector<size_t>({}));
}

TEST_F(VectorMergeTest, T02_FirstEmpty) {
    std::vector<size_t> list1 = {};
    std::vector<size_t> list2 = {1, 3, 5};
    auto result = merge(list1, list2);
    EXPECT_EQ(result, (std::vector<size_t>{1, 3, 5}));
}

TEST_F(VectorMergeTest, T03_SecondEmpty) {
    std::vector<size_t> list1 = {2, 4};
    std::vector<size_t> list2 = {};
    auto result = merge(list1, list2);
    EXPECT_EQ(result, (std::vector<size_t>{2, 4}));
}

TEST_F(VectorMergeTest, T04_AlternatingElements) {
    std::vector<size_t> list1 = {1, 3, 5};
    std::vector<size_t> list2 = {2, 4, 6};
    auto result = merge(list1, list2);
    EXPECT_EQ(result, (std::vector<size_t>{1, 2, 3, 4, 5, 6}));
}

TEST_F(VectorMergeTest, T05_List1BeforeList2) {
    std::vector<size_t> list1 = {1, 2};
    std::vector<size_t> list2 = {3, 4};
    auto result = merge(list1, list2);
    EXPECT_EQ(result, (std::vector<size_t>{1, 2, 3, 4}));
}

TEST_F(VectorMergeTest, T06_List2BeforeList1) {
    std::vector<size_t> list1 = {5, 6};
    std::vector<size_t> list2 = {1, 2};
    auto result = merge(list1, list2);
    EXPECT_EQ(result, (std::vector<size_t>{1, 2, 5, 6}));
}

TEST_F(VectorMergeTest, T07_WithDuplicates) {
    std::vector<size_t> list1 = {1, 2, 2};
    std::vector<size_t> list2 = {2, 3};
    auto result = merge(list1, list2);
    EXPECT_EQ(result, (std::vector<size_t>{1, 2, 2, 2, 3}));
}

TEST_F(VectorMergeTest, T08_SingleElementEach) {
    std::vector<size_t> list1 = {2};
    std::vector<size_t> list2 = {1};
    auto result = merge(list1, list2);
    EXPECT_EQ(result, (std::vector<size_t>{1, 2}));
}

TEST_F(VectorMergeTest, T09_SingleElementAndMultiple) {
    std::vector<size_t> list1 = {5};
    std::vector<size_t> list2 = {1, 2, 3};
    auto result = merge(list1, list2);
    EXPECT_EQ(result, (std::vector<size_t>{1, 2, 3, 5}));
}
