#include "test_config.hh"

using namespace VectorUtils;
using ScalableVector = std::vector<size_t, tbb::scalable_allocator<size_t>>;

#ifdef MERGE

class VectorMergeTest : public ::testing::Test {};

TEST_F(VectorMergeTest, T01_BothEmpty) {
    ScalableVector vec1;
    ScalableVector vec2;
    auto result = merge(vec1, vec2);

    ScalableVector expected;
    expected = {};

    EXPECT_EQ(result, expected);
}

TEST_F(VectorMergeTest, T02_FirstEmpty) {
    ScalableVector vec1;
    ScalableVector vec2({1, 3, 5});

    auto result = merge(vec1, vec2);

    ScalableVector expected;
    expected = {1, 3, 5};

    EXPECT_EQ(result, expected);
}

TEST_F(VectorMergeTest, T03_SecondEmpty) {
    ScalableVector vec1({2, 4});
    ScalableVector vec2;

    auto result = merge(vec1, vec2);

    ScalableVector expected;
    expected = {2, 4};

    EXPECT_EQ(result, expected);
}

TEST_F(VectorMergeTest, T04_AlternatingElements) {
    ScalableVector vec1({1, 3, 5});
    ScalableVector vec2({2, 4, 6});

    auto result = merge(vec1, vec2);

    ScalableVector expected;
    expected = {1, 2, 3, 4, 5, 6};

    EXPECT_EQ(result, expected);
}

TEST_F(VectorMergeTest, T05_List1BeforeList2) {
    ScalableVector vec1({1, 2});
    ScalableVector vec2({3, 4});

    auto result = merge(vec1, vec2);

    ScalableVector expected;
    expected = {1, 2, 3, 4};

    EXPECT_EQ(result, expected);
}

TEST_F(VectorMergeTest, T06_List2BeforeList1) {
    ScalableVector vec1({5, 6});
    ScalableVector vec2({1, 2});

    auto result = merge(vec1, vec2);

    ScalableVector expected;
    expected = {1, 2, 5, 6};

    EXPECT_EQ(result, expected);
}

TEST_F(VectorMergeTest, T07_WithDuplicates) {
    ScalableVector vec1({1, 2, 2});
    ScalableVector vec2({2, 3});

    auto result = merge(vec1, vec2);

    ScalableVector expected;
    expected = {1, 2, 2, 2, 3};

    EXPECT_EQ(result, expected);
}

TEST_F(VectorMergeTest, T08_SingleElementEach) {
    ScalableVector vec1({2});
    ScalableVector vec2({1});

    auto result = merge(vec1, vec2);

    ScalableVector expected;
    expected = {1, 2};

    EXPECT_EQ(result, expected);
}

TEST_F(VectorMergeTest, T09_SingleElementAndMultiple) {
    ScalableVector vec1({5});
    ScalableVector vec2({1, 2, 3});

    auto result = merge(vec1, vec2);

    ScalableVector expected;
    expected = {1, 2, 3, 5};

    EXPECT_EQ(result, expected);
}

#endif
