#include "test_config.hh"

using namespace TestUtils;
using namespace LinkedListAlgorithm;

#ifdef CONCAT

class LinkedListConcatTest : public ::testing::Test {
    protected:
        std::shared_ptr<std::pmr::memory_resource> arena;

        void SetUp() override {
            arena = MemoryManager::instance().create_arena(1024 * 10);
        }
        
        void TearDown() override {
            MemoryManager::instance().release_arena(arena.get());
        }
};

TEST_F(LinkedListConcatTest, T01_TwoNonEmptyLists) {
    LinkedList left({1, 3}, arena.get());
    LinkedList right({2, 4}, arena.get());
    concat(left, right);

    test_linked_list_integrity(left, {1, 3, 2, 4});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListConcatTest, T02_FirstListEmpty) {
    LinkedList left(arena.get());
    LinkedList right({5, 6}, arena.get());
    concat(left, right);

    test_linked_list_integrity(left, {5, 6});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListConcatTest, T03_SecondListEmpty) {
    LinkedList left({7, 8}, arena.get());
    LinkedList right(arena.get());
    concat(left, right);

    test_linked_list_integrity(left, {7, 8});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListConcatTest, T04_BothListsEmpty) {
    LinkedList left(arena.get());
    LinkedList right(arena.get());
    concat(left, right);
    test_linked_list_integrity(left, {});
    test_linked_list_integrity(right, {});
}

TEST_F(LinkedListConcatTest, T05_ConcatMultipleTimes) {
    LinkedList l1({1, 2}, arena.get());
    auto l2 = LinkedList({3, 4}, arena.get());
    auto l3 = LinkedList({5, 6}, arena.get());

    concat(l1, l2);
    concat(l1, l3);

    test_linked_list_integrity(l1, {1, 2, 3, 4, 5, 6});
    test_linked_list_integrity(l2, {});
    test_linked_list_integrity(l3, {});
}

TEST_F(LinkedListConcatTest, T06_ForceCorruption) {
    LinkedList left({1, 3}, arena.get());
    LinkedList right({2, 4}, arena.get());
    left.last = nullptr; // Force corruption

    EXPECT_THROW({
        concat(left, right);
    }, std::logic_error);
}


#endif