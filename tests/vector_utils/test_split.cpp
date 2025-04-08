#include "test_config.hh"

#include "utils/vector_utils/vector_utils.hh"

using namespace VectorUtils;

#ifdef SPLIT

class VectorSplitTest : public ::testing::Test {
protected:
    std::shared_ptr<std::pmr::memory_resource> arena;

    void SetUp() override {
        arena = MemoryManager::instance().create_arena(1024 * 64);
    }

    void TearDown() override {
        MemoryManager::instance().release_arena(arena.get());
    }
};

TEST_F(VectorSplitTest, T01_SplitThrowsOnEmptyVector) {
    std::pmr::vector<size_t> vec(arena.get());
    EXPECT_THROW(split(vec), std::invalid_argument);
}

TEST_F(VectorSplitTest, T02_SplitThrowsOnSizeOneVector) {
    std::pmr::vector<size_t> vec({42}, arena.get());
    EXPECT_THROW(split(vec), std::invalid_argument);
}

TEST_F(VectorSplitTest, T03_SplitEvenLength) {
    std::pmr::vector<size_t> vec({10, 20, 30, 40}, arena.get());
    auto [left, right] = split(vec);

    std::pmr::vector<size_t> expected_left(arena.get());
    expected_left = {10, 20};
    std::pmr::vector<size_t> expected_right(arena.get());
    expected_right = {30, 40};

    EXPECT_EQ(left, expected_left);
    EXPECT_EQ(right, expected_right);
}

TEST_F(VectorSplitTest, T04_SplitOddLength) {
    std::pmr::vector<size_t> vec({1, 2, 3, 4, 5}, arena.get());
    auto [left, right] = split(vec);

    std::pmr::vector<size_t> expected_left(arena.get());
    expected_left = {1, 2};
    std::pmr::vector<size_t> expected_right(arena.get());
    expected_right = {3, 4, 5};

    EXPECT_EQ(left, expected_left);
    EXPECT_EQ(right, expected_right);
}

#endif
