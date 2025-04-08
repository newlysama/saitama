#include "test_config.hh"

class VectorsQuickSortTest : public ::testing::Test {
protected:
    std::shared_ptr<std::pmr::memory_resource> arena;

    void SetUp() override {
        arena = MemoryManager::instance().create_arena(1024 * 64);
    }

    void TearDown() override {
        MemoryManager::instance().release_arena(arena.get());
    }
};

#ifdef QUICK_SORT_LOMUTO_VECTORS

/*
 * ======================== quick_sort_lomuto ========================
 */

TEST_F(VectorsQuickSortTest, T01_Lomuto_EmptyList) {
    std::pmr::vector<size_t> list(arena.get());
    quick_sort_lomuto(list);
    std::pmr::vector<size_t> expected(arena.get());
    EXPECT_EQ(list, expected);
}

TEST_F(VectorsQuickSortTest, T02_Lomuto_SingleElement) {
    std::pmr::vector<size_t> list({42}, arena.get());
    quick_sort_lomuto(list);
    std::pmr::vector<size_t> expected(arena.get());
    expected = {42};
    EXPECT_EQ(list, expected);
}

TEST_F(VectorsQuickSortTest, T03_Lomuto_RandomValues) {
    std::pmr::vector<size_t> list({5, 2, 1, 4, 3}, arena.get());
    quick_sort_lomuto(list);
    std::pmr::vector<size_t> expected(arena.get());
    expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(list, expected);
}

TEST_F(VectorsQuickSortTest, T04_Lomuto_AlreadySorted) {
    std::pmr::vector<size_t> list({1, 2, 3, 4, 5}, arena.get());
    quick_sort_lomuto(list);
    std::pmr::vector<size_t> expected(arena.get());
    expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(list, expected);
}

TEST_F(VectorsQuickSortTest, T05_Lomuto_ReverseSorted) {
    std::pmr::vector<size_t> list({5, 4, 3, 2, 1}, arena.get());
    quick_sort_lomuto(list);
    std::pmr::vector<size_t> expected(arena.get());
    expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(list, expected);
}

#endif

#ifdef QUICK_SORT_HOARE_VECTORS

/*
 * ======================== quick_sort_hoare ========================
 */

TEST_F(VectorsQuickSortTest, T06_Hoare_EmptyList) {
    std::pmr::vector<size_t> list(arena.get());
    quick_sort_hoare(list);
    std::pmr::vector<size_t> expected(arena.get());
    EXPECT_EQ(list, expected);
}

TEST_F(VectorsQuickSortTest, T07_Hoare_SingleElement) {
    std::pmr::vector<size_t> list({99}, arena.get());
    quick_sort_hoare(list);
    std::pmr::vector<size_t> expected(arena.get());
    expected = {99};
    EXPECT_EQ(list, expected);
}

TEST_F(VectorsQuickSortTest, T08_Hoare_RandomValues) {
    std::pmr::vector<size_t> list({5, 2, 1, 4, 3}, arena.get());
    quick_sort_hoare(list);
    std::pmr::vector<size_t> expected(arena.get());
    expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(list, expected);
}

TEST_F(VectorsQuickSortTest, T09_Hoare_AlreadySorted) {
    std::pmr::vector<size_t> list({10, 20, 30, 40}, arena.get());
    quick_sort_hoare(list);
    std::pmr::vector<size_t> expected(arena.get());
    expected = {10, 20, 30, 40};
    EXPECT_EQ(list, expected);
}

TEST_F(VectorsQuickSortTest, T10_Hoare_ReverseSorted) {
    std::pmr::vector<size_t> list({9, 7, 5, 3, 1}, arena.get());
    quick_sort_hoare(list);
    std::pmr::vector<size_t> expected(arena.get());
    expected = {1, 3, 5, 7, 9};
    EXPECT_EQ(list, expected);
}

#endif
