#include "test_config.hh"

using namespace TestUtils;
using namespace LinkedListAlgorithm;

#ifdef MERGE

class LinkedListMergeTest : public ::testing::Test {
    protected:
        std::shared_ptr<std::pmr::memory_resource> arena;
    
        void SetUp() override {
            arena = MemoryManager::instance().create_arena(1024 * 64);
        }
    
        void TearDown() override {
            MemoryManager::instance().release_arena(arena.get());
        }
};
    

TEST_F(LinkedListMergeTest, T01_BothEmpty) {
    LinkedList left(arena.get());
    LinkedList right(arena.get());
    merge(left, right);
    test_linked_list_integrity(left, {});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListMergeTest, T02_FirstEmpty) {
    LinkedList left(arena.get());
    LinkedList right({1, 3, 5}, arena.get());
    merge(left, right);
    test_linked_list_integrity(left, {1, 3, 5});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListMergeTest, T03_SecondEmpty) {
    LinkedList left({2, 4}, arena.get());
    LinkedList right(arena.get());
    merge(left, right);
    test_linked_list_integrity(left, {2, 4});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListMergeTest, T04_AlternatingElements) {
    LinkedList left({1, 3, 5}, arena.get());
    LinkedList right({2, 4, 6}, arena.get());
    merge(left, right);
    test_linked_list_integrity(left, {1, 2, 3, 4, 5, 6});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListMergeTest, T05_List1BeforeList2) {
    LinkedList left({1, 2}, arena.get());
    LinkedList right({3, 4}, arena.get());
    merge(left, right);
    test_linked_list_integrity(left, {1, 2, 3, 4});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListMergeTest, T06_List2BeforeList1) {
    LinkedList left({5, 6}, arena.get());
    LinkedList right({1, 2}, arena.get());
    merge(right, left);
    test_linked_list_integrity(right, {1, 2, 5, 6});
    test_linked_list_integrity(left, {});
}

TEST_F(LinkedListMergeTest, T07_WithDuplicates) {
    LinkedList left({1, 2, 2}, arena.get());
    LinkedList right({2, 3}, arena.get());
    merge(left, right);
    test_linked_list_integrity(left, {1, 2, 2, 2, 3});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListMergeTest, T08_SingleElementEach) {
    LinkedList left({2}, arena.get());
    LinkedList right({1}, arena.get());
    merge(left, right);
    test_linked_list_integrity(left, {1, 2});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListMergeTest, T09_SingleElementAndMultiple) {
    LinkedList left({5}, arena.get());
    LinkedList right({1, 2, 3}, arena.get());
    merge(left, right);
    test_linked_list_integrity(left, {1, 2, 3, 5});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListMergeTest, T10_MixedLengthLists) {
    LinkedList left({1}, arena.get());
    LinkedList right({2, 3, 4, 5}, arena.get());
    merge(left, right);
    test_linked_list_integrity(left, {1, 2, 3, 4, 5});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListMergeTest, T11_InterleavedEqualElements) {
    LinkedList left({1, 3, 5}, arena.get());
    LinkedList right({1, 3, 5}, arena.get());
    merge(left, right);
    test_linked_list_integrity(left, {1, 1, 3, 3, 5, 5});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListMergeTest, T12_LargeLists) {
    std::vector<size_t> v1(500, 1);
    std::vector<size_t> v2(500, 2);

    LinkedList left(v1, arena.get());
    LinkedList right(v2, arena.get());

    merge(left, right);

    std::vector<size_t> expected(1000);
    std::fill(expected.begin(), expected.begin() + 500, 1);
    std::fill(expected.begin() + 500, expected.end(), 2);

    test_linked_list_integrity(left, expected);
    test_linked_list_integrity(right, {});
}
    

#endif