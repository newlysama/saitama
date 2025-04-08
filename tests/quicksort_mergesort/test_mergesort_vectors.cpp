#include "test_config.hh"

#ifdef MERGE_SORT_VECTORS

class VectorsMergeSortTest : public ::testing::Test {
protected:
    std::shared_ptr<std::pmr::memory_resource> arena;

    void SetUp() override {
        arena = MemoryManager::instance().create_arena(1024 * 64);
    }

    void TearDown() override {
        MemoryManager::instance().release_arena(arena.get());
    }
};

TEST_F(VectorsMergeSortTest, T01_EmptyList) {
    std::pmr::vector<size_t> list(arena.get());
    auto res = merge_sort(list);

    std::pmr::vector<size_t> expected(arena.get());
    EXPECT_EQ(res, expected);
}

TEST_F(VectorsMergeSortTest, T02_SingleElement) {
    std::pmr::vector<size_t> list({42}, arena.get());
    auto res = merge_sort(list);

    std::pmr::vector<size_t> expected(arena.get());
    expected = {42};
    EXPECT_EQ(res, expected);
}

TEST_F(VectorsMergeSortTest, T03_RandomValues) {
    std::pmr::vector<size_t> list({5, 2, 1, 4, 3}, arena.get());
    auto res = merge_sort(list);

    std::pmr::vector<size_t> expected(arena.get());
    expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(res, expected);
}

TEST_F(VectorsMergeSortTest, T04_AlreadySorted) {
    std::pmr::vector<size_t> list({1, 2, 3, 4, 5}, arena.get());
    auto res = merge_sort(list);

    std::pmr::vector<size_t> expected(arena.get());
    expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(res, expected);
}

TEST_F(VectorsMergeSortTest, T05_ReverseSorted) {
    std::pmr::vector<size_t> list({5, 4, 3, 2, 1}, arena.get());
    auto res = merge_sort(list);

    std::pmr::vector<size_t> expected(arena.get());
    expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(res, expected);
}

#endif
