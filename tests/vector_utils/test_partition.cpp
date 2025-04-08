#include "test_config.hh"

using namespace VectorUtils;

#if PIVOT != RANDOM // since random pivot gives unpredictable result

class VectorPartitionTest : public ::testing::Test {
protected:
    std::shared_ptr<std::pmr::memory_resource> arena;

    std::pmr::vector<size_t> expected_unsorted_lomuto;
    std::pmr::vector<size_t> expected_reversed_lomuto;
    std::pmr::vector<size_t> expected_unsorted_hoare;
    std::pmr::vector<size_t> expected_reversed_hoare;

    void SetUp() override {
        arena = MemoryManager::instance().create_arena(1024 * 64);

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

    void TearDown() override {
        MemoryManager::instance().release_arena(arena.get());
    }
};

#ifdef PARTITION_LOMUTO

TEST_F(VectorPartitionTest, T01_Lomuto_SortedList) {
    std::pmr::vector<size_t> vec({1, 2, 3, 4, 5}, arena.get());
    partition_lomuto(vec, 0, vec.size() - 1);

    std::pmr::vector<size_t> expected(arena.get());
    expected = {1, 2, 3, 4, 5};

    EXPECT_EQ(vec, expected);
}

TEST_F(VectorPartitionTest, T02_Lomuto_UnsortedList) {
    std::pmr::vector<size_t> vec({1, 3, 5, 4, 2}, arena.get());
    partition_lomuto(vec, 0, vec.size() - 1);
    EXPECT_EQ(vec, expected_unsorted_lomuto);
}

TEST_F(VectorPartitionTest, T03_Lomuto_ReversedList) {
    std::pmr::vector<size_t> vec({5, 4, 3, 2, 1}, arena.get());
    partition_lomuto(vec, 0, vec.size() - 1);
    EXPECT_EQ(vec, expected_reversed_lomuto);
}

TEST_F(VectorPartitionTest, T04_Lomuto_Duplicates) {
    std::pmr::vector<size_t> vec({3, 3, 3, 3, 3}, arena.get());
    partition_lomuto(vec, 0, vec.size() - 1);

    std::pmr::vector<size_t> expected(arena.get());
    expected = {3, 3, 3, 3, 3};

    EXPECT_EQ(vec, expected);
}

TEST_F(VectorPartitionTest, T05_Lomuto_TwoElementsSorted) {
    std::pmr::vector<size_t> vec({1, 2}, arena.get());
    partition_lomuto(vec, 0, vec.size() - 1);

    std::pmr::vector<size_t> expected(arena.get());
    expected = {1, 2};

    EXPECT_EQ(vec, expected);
}

TEST_F(VectorPartitionTest, T06_Lomuto_TwoElementsUnsorted) {
    std::pmr::vector<size_t> vec({2, 1}, arena.get());
    partition_lomuto(vec, 0, vec.size() - 1);

    std::pmr::vector<size_t> expected(arena.get());
    expected = {1, 2};

    EXPECT_EQ(vec, expected);
}

TEST_F(VectorPartitionTest, T07_Lomuto_InvalidLowHigh) {
    std::pmr::vector<size_t> vec({1, 2, 3}, arena.get());
    EXPECT_THROW(partition_lomuto(vec, 2, 2), std::invalid_argument);
}

TEST_F(VectorPartitionTest, T08_Lomuto_HighOutOfBounds) {
    std::pmr::vector<size_t> vec({1, 2, 3}, arena.get());
    EXPECT_THROW(partition_lomuto(vec, 0, 5), std::invalid_argument);
}

#endif

#ifdef PARTITION_HOARE

TEST_F(VectorPartitionTest, T09_Hoare_SortedList) {
    std::pmr::vector<size_t> vec({1, 2, 3, 4, 5}, arena.get());
    partition_hoare(vec, 0, vec.size() - 1);

    std::pmr::vector<size_t> expected(arena.get());
    expected = {1, 2, 3, 4, 5};

    EXPECT_EQ(vec, expected);
}

TEST_F(VectorPartitionTest, T10_Hoare_UnsortedList) {
    std::pmr::vector<size_t> vec({1, 3, 5, 4, 2}, arena.get());
    partition_hoare(vec, 0, vec.size() - 1);
    EXPECT_EQ(vec, expected_unsorted_hoare);
}

TEST_F(VectorPartitionTest, T11_Hoare_ReversedList) {
    std::pmr::vector<size_t> vec({5, 4, 3, 2, 1}, arena.get());
    partition_hoare(vec, 0, vec.size() - 1);
    EXPECT_EQ(vec, expected_reversed_hoare);
}

TEST_F(VectorPartitionTest, T12_Hoare_Duplicates) {
    std::pmr::vector<size_t> vec({3, 3, 3, 3, 3}, arena.get());
    partition_hoare(vec, 0, vec.size() - 1);

    std::pmr::vector<size_t> expected(arena.get());
    expected = {3, 3, 3, 3, 3};

    EXPECT_EQ(vec, expected);
}

TEST_F(VectorPartitionTest, T13_Hoare_TwoElementsSorted) {
    std::pmr::vector<size_t> vec({1, 2}, arena.get());
    partition_hoare(vec, 0, vec.size() - 1);

    std::pmr::vector<size_t> expected(arena.get());
    expected = {1, 2};

    EXPECT_EQ(vec, expected);
}

TEST_F(VectorPartitionTest, T14_Hoare_TwoElementsUnsorted) {
    std::pmr::vector<size_t> vec({2, 1}, arena.get());
    partition_hoare(vec, 0, vec.size() - 1);

    std::pmr::vector<size_t> expected(arena.get());
    expected = {1, 2};

    EXPECT_EQ(vec, expected);
}

TEST_F(VectorPartitionTest, T15_Hoare_InvalidLowHigh) {
    std::pmr::vector<size_t> vec({1, 2, 3}, arena.get());
    EXPECT_THROW(partition_hoare(vec, 3, 2), std::invalid_argument);
}

TEST_F(VectorPartitionTest, T16_Hoare_HighOutOfBounds) {
    std::pmr::vector<size_t> vec({1, 2, 3}, arena.get());
    EXPECT_THROW(partition_hoare(vec, 0, 5), std::invalid_argument);
}

#endif

#endif // PIVOT != RANDOM
