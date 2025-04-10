#include "test_config.hh"

using namespace TestUtils;
using namespace LinkedListAlgorithm;

#ifdef CONCAT

class LinkedListConcatTest : public ::testing::Test {
    protected:
        std::shared_ptr<MemoryManager::FixedArena> arena;

        void SetUp() override {
            arena = MemoryManager::instance().create_fixed_arena(1024 * 10);
        }
};

TEST_F(LinkedListConcatTest, T01_TwoNonEmptyLists) {
    LinkedList<MemoryManager::FixedArena> left({1, 3}, arena);
    LinkedList<MemoryManager::FixedArena> right({2, 4}, arena);
    concat(left, right);

    test_linked_list_integrity(left, {1, 3, 2, 4});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListConcatTest, T02_FirstListEmpty) {
    LinkedList<MemoryManager::FixedArena> left(arena);
    LinkedList<MemoryManager::FixedArena> right({5, 6}, arena);
    concat(left, right);

    test_linked_list_integrity(left, {5, 6});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListConcatTest, T03_SecondListEmpty) {
    LinkedList<MemoryManager::FixedArena> left({7, 8}, arena);
    LinkedList<MemoryManager::FixedArena> right(arena);
    concat(left, right);

    test_linked_list_integrity(left, {7, 8});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListConcatTest, T04_BothListsEmpty) {
    LinkedList<MemoryManager::FixedArena> left(arena);
    LinkedList<MemoryManager::FixedArena> right(arena);
    concat(left, right);
    test_linked_list_integrity(left, {});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListConcatTest, T05_ConcatMultipleTimes) {
    LinkedList<MemoryManager::FixedArena> l1({1, 2}, arena);
    LinkedList<MemoryManager::FixedArena> l2({3, 4}, arena);
    LinkedList<MemoryManager::FixedArena> l3({5, 6}, arena);

    concat(l1, l2);
    concat(l1, l3);

    test_linked_list_integrity(l1, {1, 2, 3, 4, 5, 6});
    test_linked_list_integrity(l2, {});
    test_linked_list_integrity(l3, {});
}

TEST_F(LinkedListConcatTest, T06_ForceCorruption) {
    LinkedList<MemoryManager::FixedArena> left({1, 3}, arena);
    LinkedList<MemoryManager::FixedArena> right({2, 4}, arena);
    left.last = nullptr; // Force corruption

    EXPECT_THROW({
        concat(left, right);
    }, std::logic_error);
}


#endif