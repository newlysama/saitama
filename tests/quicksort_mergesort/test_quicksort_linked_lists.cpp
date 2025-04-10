#include "test_config.hh"

using namespace TestUtils;

#ifdef LINKED_LISTS

class LinkedListQuickSortTest : public ::testing::Test {
    protected:
        std::shared_ptr<MemoryManager::FixedArena> arena;

        void SetUp() override {
            arena = MemoryManager::instance().create_fixed_arena(1024 * 10);
        }
};
/*
 * ======================== quick_sort_lomuto ========================
 */

#ifdef QUICKSORT_LOMUTO

TEST_F(LinkedListQuickSortTest, T01_Lomuto_EmptyList) {
    LinkedList<MemoryManager::FixedArena> list(arena);
    quick_sort_lomuto(list);
    test_linked_list_integrity(list, {});
}

TEST_F(LinkedListQuickSortTest, T02_Lomuto_SingleElement) {
    LinkedList<MemoryManager::FixedArena> list({42}, arena);
    quick_sort_lomuto(list);
    test_linked_list_integrity(list, {42});
}

TEST_F(LinkedListQuickSortTest, T03_Lomuto_RandomValues) {
    LinkedList<MemoryManager::FixedArena> list({5, 2, 1, 4, 3}, arena);
    quick_sort_lomuto(list);
    test_linked_list_integrity(list, {1, 2, 3, 4, 5});
}

TEST_F(LinkedListQuickSortTest, T04_Lomuto_AlreadySorted) {
    LinkedList<MemoryManager::FixedArena> list({1, 2, 3, 4, 5}, arena);
    quick_sort_lomuto(list);
    test_linked_list_integrity(list, {1, 2, 3, 4, 5});
}

TEST_F(LinkedListQuickSortTest, T05_Lomuto_ReverseSorted) {
    LinkedList<MemoryManager::FixedArena> list({5, 4, 3, 2, 1}, arena);
    quick_sort_lomuto(list);
    test_linked_list_integrity(list, {1, 2, 3, 4, 5});
}

TEST_F(LinkedListQuickSortTest, T06_Lomuto_WithDuplicates) {
    LinkedList<MemoryManager::FixedArena> list({4, 2, 4, 1, 4}, arena);
    quick_sort_lomuto(list);
    test_linked_list_integrity(list, {1, 2, 4, 4, 4});
}

TEST_F(LinkedListQuickSortTest, T07_Lomuto_AllEqual) {
    LinkedList<MemoryManager::FixedArena> list({7, 7, 7, 7}, arena);
    quick_sort_lomuto(list);
    test_linked_list_integrity(list, {7, 7, 7, 7});
}

#endif // QUICKSORT_LOMUTO

#ifdef QUICKSORT_HOARE

/*
 * ======================== quick_sort_hoare ========================
 */

TEST_F(LinkedListQuickSortTest, T08_Hoare_EmptyList) {
    LinkedList<MemoryManager::FixedArena> list(arena);
    quick_sort_hoare(list);
    test_linked_list_integrity(list, {});
}

TEST_F(LinkedListQuickSortTest, T09_Hoare_SingleElement) {
    LinkedList<MemoryManager::FixedArena> list({99}, arena);
    quick_sort_hoare(list);
    test_linked_list_integrity(list, {99});
}

TEST_F(LinkedListQuickSortTest, T10_Hoare_RandomValues) {
    LinkedList<MemoryManager::FixedArena> list({5, 2, 1, 4, 3}, arena);
    quick_sort_hoare(list);
    test_linked_list_integrity(list, {1, 2, 3, 4, 5});
}

TEST_F(LinkedListQuickSortTest, T11_Hoare_AlreadySorted) {
    LinkedList<MemoryManager::FixedArena> list({10, 20, 30, 40}, arena);
    quick_sort_hoare(list);
    test_linked_list_integrity(list, {10, 20, 30, 40});
}

TEST_F(LinkedListQuickSortTest, T12_Hoare_ReverseSorted) {
    LinkedList<MemoryManager::FixedArena> list({9, 7, 5, 3, 1}, arena);
    quick_sort_hoare(list);
    test_linked_list_integrity(list, {1, 3, 5, 7, 9});
}

TEST_F(LinkedListQuickSortTest, T13_Hoare_WithDuplicates) {
    LinkedList<MemoryManager::FixedArena> list({4, 2, 4, 1, 4}, arena);
    quick_sort_hoare(list);
    test_linked_list_integrity(list, {1, 2, 4, 4, 4});
}

TEST_F(LinkedListQuickSortTest, T14_Hoare_AllEqual) {
    LinkedList<MemoryManager::FixedArena> list({7, 7, 7, 7}, arena);
    quick_sort_hoare(list);
    test_linked_list_integrity(list, {7, 7, 7, 7});
}

#endif // QUICKSORT_HOARE

#endif // LINKED_LISTS