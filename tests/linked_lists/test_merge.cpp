#include "test_config.hh"

using namespace TestUtils;
using namespace LinkedListAlgorithm;

#ifdef MERGE

class LinkedListMergeTest : public ::testing::Test {
    protected:
        std::shared_ptr<MemoryManager::FixedArena> arena;
        
    void SetUp() override {
        arena = MemoryManager::instance().create_fixed_arena(1024 * 100);
    }
};
    

TEST_F(LinkedListMergeTest, T01_BothEmpty) {
    LinkedList<MemoryManager::FixedArena> left(arena);
    LinkedList<MemoryManager::FixedArena> right(arena);
    merge(left, right);
    test_linked_list_integrity(left, {});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListMergeTest, T02_FirstEmpty) {
    LinkedList<MemoryManager::FixedArena> left(arena);
    LinkedList<MemoryManager::FixedArena> right({1, 3, 5}, arena);
    merge(left, right);
    test_linked_list_integrity(left, {1, 3, 5});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListMergeTest, T03_SecondEmpty) {
    LinkedList<MemoryManager::FixedArena> left({2, 4}, arena);
    LinkedList<MemoryManager::FixedArena> right(arena);
    merge(left, right);
    test_linked_list_integrity(left, {2, 4});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListMergeTest, T04_AlternatingElements) {
    LinkedList<MemoryManager::FixedArena> left({1, 3, 5}, arena);
    LinkedList<MemoryManager::FixedArena> right({2, 4, 6}, arena);
    merge(left, right);
    test_linked_list_integrity(left, {1, 2, 3, 4, 5, 6});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListMergeTest, T05_List1BeforeList2) {
    LinkedList<MemoryManager::FixedArena> left({1, 2}, arena);
    LinkedList<MemoryManager::FixedArena> right({3, 4}, arena);
    merge(left, right);
    test_linked_list_integrity(left, {1, 2, 3, 4});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListMergeTest, T06_List2BeforeList1) {
    LinkedList<MemoryManager::FixedArena> left({5, 6}, arena);
    LinkedList<MemoryManager::FixedArena> right({1, 2}, arena);
    merge(right, left);
    test_linked_list_integrity(right, {1, 2, 5, 6});
    test_linked_list_integrity(left, {});
}

TEST_F(LinkedListMergeTest, T07_WithDuplicates) {
    LinkedList<MemoryManager::FixedArena> left({1, 2, 2}, arena);
    LinkedList<MemoryManager::FixedArena> right({2, 3}, arena);
    merge(left, right);
    test_linked_list_integrity(left, {1, 2, 2, 2, 3});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListMergeTest, T08_SingleElementEach) {
    LinkedList<MemoryManager::FixedArena> left({2}, arena);
    LinkedList<MemoryManager::FixedArena> right({1}, arena);
    merge(left, right);
    test_linked_list_integrity(left, {1, 2});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListMergeTest, T09_SingleElementAndMultiple) {
    LinkedList<MemoryManager::FixedArena> left({5}, arena);
    LinkedList<MemoryManager::FixedArena> right({1, 2, 3}, arena);
    merge(left, right);
    test_linked_list_integrity(left, {1, 2, 3, 5});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListMergeTest, T10_MixedLengthLists) {
    LinkedList<MemoryManager::FixedArena> left({1}, arena);
    LinkedList<MemoryManager::FixedArena> right({2, 3, 4, 5}, arena);
    merge(left, right);
    test_linked_list_integrity(left, {1, 2, 3, 4, 5});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListMergeTest, T11_InterleavedEqualElements) {
    LinkedList<MemoryManager::FixedArena> left({1, 3, 5}, arena);
    LinkedList<MemoryManager::FixedArena> right({1, 3, 5}, arena);
    merge(left, right);
    test_linked_list_integrity(left, {1, 1, 3, 3, 5, 5});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListMergeTest, T12_LargeLists) {
    std::vector<size_t> v1(500, 1);
    std::vector<size_t> v2(500, 2);

    LinkedList<MemoryManager::FixedArena> left(v1, arena);
    LinkedList<MemoryManager::FixedArena> right(v2, arena);

    merge(left, right);

    std::vector<size_t> expected(1000);
    std::fill(expected.begin(), expected.begin() + 500, 1);
    std::fill(expected.begin() + 500, expected.end(), 2);

    test_linked_list_integrity(left, expected);
    test_linked_list_integrity(right, {});
}
    

#endif