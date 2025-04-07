#include "test_config.hh"

using namespace TestUtils;

#ifdef MERGE_SORT_LINKED_LISTS

class LinkedListMergeSortTest : public ::testing::Test {
    protected:
        std::shared_ptr<std::pmr::memory_resource> arena;

        void SetUp() override {
            arena = MemoryManager::instance().create_arena(1024 * 10);
        }
        
        void TearDown() override {
            MemoryManager::instance().release_arena(arena.get());
        }
};


TEST_F(LinkedListMergeSortTest, T01_EmptyList) {
    LinkedList list(arena);
    merge_sort(list);
    test_linked_list_integrity(list, {});
}

TEST_F(LinkedListMergeSortTest, T02_SingleElement) {
    LinkedList list({42}, arena);
    merge_sort(list);
    test_linked_list_integrity(list, {42});
}

TEST_F(LinkedListMergeSortTest, T03_RandomValues) {
    LinkedList list({5, 2, 1, 4, 3}, arena);
    merge_sort(list);
    test_linked_list_integrity(list, {1, 2, 3, 4, 5});
}


TEST_F(LinkedListMergeSortTest, T04_AlreadySorted) {
    LinkedList list({1, 2, 3, 4, 5}, arena);
    merge_sort(list);
    test_linked_list_integrity(list, {1, 2, 3, 4, 5});
}

TEST_F(LinkedListMergeSortTest, T05_ReverseSorted) {
    LinkedList list({5, 4, 3, 2, 1}, arena);
    merge_sort(list);
    test_linked_list_integrity(list, {1, 2, 3, 4, 5});
}

#endif