#include "test_config.hh"

using namespace VectorUtils;

#ifdef MERGE

class VectorMergeTest : public ::testing::Test {
protected:
    std::shared_ptr<std::pmr::memory_resource> arena;

    void SetUp() override {
        arena = MemoryManager::instance().create_arena(1024 * 64);
    }

    void TearDown() override {
        MemoryManager::instance().release_arena(arena.get());
    }
};

TEST_F(VectorMergeTest, T01_BothEmpty) {
    std::pmr::vector<size_t> list1(arena.get());
    std::pmr::vector<size_t> list2(arena.get());
    auto result = merge(list1, list2);

    std::pmr::vector<size_t> expected(arena.get());
    expected = {};

    EXPECT_EQ(result, expected);
}

TEST_F(VectorMergeTest, T02_FirstEmpty) {
    std::pmr::vector<size_t> list1(arena.get());
    std::pmr::vector<size_t> list2({1, 3, 5}, arena.get());

    auto result = merge(list1, list2);

    std::pmr::vector<size_t> expected(arena.get());
    expected = {1, 3, 5};

    EXPECT_EQ(result, expected);
}

TEST_F(VectorMergeTest, T03_SecondEmpty) {
    std::pmr::vector<size_t> list1({2, 4}, arena.get());
    std::pmr::vector<size_t> list2(arena.get());

    auto result = merge(list1, list2);

    std::pmr::vector<size_t> expected(arena.get());
    expected = {2, 4};

    EXPECT_EQ(result, expected);
}

TEST_F(VectorMergeTest, T04_AlternatingElements) {
    std::pmr::vector<size_t> list1({1, 3, 5}, arena.get());
    std::pmr::vector<size_t> list2({2, 4, 6}, arena.get());

    auto result = merge(list1, list2);

    std::pmr::vector<size_t> expected(arena.get());
    expected = {1, 2, 3, 4, 5, 6};

    EXPECT_EQ(result, expected);
}

TEST_F(VectorMergeTest, T05_List1BeforeList2) {
    std::pmr::vector<size_t> list1({1, 2}, arena.get());
    std::pmr::vector<size_t> list2({3, 4}, arena.get());

    auto result = merge(list1, list2);

    std::pmr::vector<size_t> expected(arena.get());
    expected = {1, 2, 3, 4};

    EXPECT_EQ(result, expected);
}

TEST_F(VectorMergeTest, T06_List2BeforeList1) {
    std::pmr::vector<size_t> list1({5, 6}, arena.get());
    std::pmr::vector<size_t> list2({1, 2}, arena.get());

    auto result = merge(list1, list2);

    std::pmr::vector<size_t> expected(arena.get());
    expected = {1, 2, 5, 6};

    EXPECT_EQ(result, expected);
}

TEST_F(VectorMergeTest, T07_WithDuplicates) {
    std::pmr::vector<size_t> list1({1, 2, 2}, arena.get());
    std::pmr::vector<size_t> list2({2, 3}, arena.get());

    auto result = merge(list1, list2);

    std::pmr::vector<size_t> expected(arena.get());
    expected = {1, 2, 2, 2, 3};

    EXPECT_EQ(result, expected);
}

TEST_F(VectorMergeTest, T08_SingleElementEach) {
    std::pmr::vector<size_t> list1({2}, arena.get());
    std::pmr::vector<size_t> list2({1}, arena.get());

    auto result = merge(list1, list2);

    std::pmr::vector<size_t> expected(arena.get());
    expected = {1, 2};

    EXPECT_EQ(result, expected);
}

TEST_F(VectorMergeTest, T09_SingleElementAndMultiple) {
    std::pmr::vector<size_t> list1({5}, arena.get());
    std::pmr::vector<size_t> list2({1, 2, 3}, arena.get());

    auto result = merge(list1, list2);

    std::pmr::vector<size_t> expected(arena.get());
    expected = {1, 2, 3, 5};

    EXPECT_EQ(result, expected);
}

#endif
