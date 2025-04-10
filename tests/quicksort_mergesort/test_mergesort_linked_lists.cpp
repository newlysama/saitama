#include "test_config.hh"

using namespace TestUtils;

#ifdef LINKED_LISTS
#ifdef MERGESORT

class LinkedListMergeSortTest : public ::testing::Test {
    protected:
        std::shared_ptr<MemoryManager::FixedArena> arena;

        void SetUp() override {
            arena = MemoryManager::instance().create_fixed_arena(1024 * 10);
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
#endif