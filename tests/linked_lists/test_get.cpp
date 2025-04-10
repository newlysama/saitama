#include "test_config.hh"

using namespace TestUtils;

#ifdef GET

class LinkedListGetTest : public ::testing::Test {
    protected:
        std::shared_ptr<MemoryManager::FixedArena> arena;
    
        void SetUp() override {
            arena = MemoryManager::instance().create_fixed_arena(1024 * 10);
        }
};
    
TEST_F(LinkedListGetTest, T01_GetFirstElement) {
    LinkedList<MemoryManager::FixedArena> list({10, 20, 30, 40, 50}, arena);
    Node* node = list.get(0);
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->value, 10);
    EXPECT_EQ(node->prev, nullptr);
}

TEST_F(LinkedListGetTest, T02_GetMiddleElement_FirstHalf) {
    LinkedList<MemoryManager::FixedArena> list({10, 20, 30, 40, 50}, arena);
    Node* node = list.get(2);
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->value, 30);
    EXPECT_EQ(node->prev->value, 20);
}

TEST_F(LinkedListGetTest, T03_GetMiddleElement_SecondHalf) {
    LinkedList<MemoryManager::FixedArena> list({10, 20, 30, 40, 50}, arena);
    Node* node = list.get(3);
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->value, 40);
    EXPECT_EQ(node->prev->value, 30);
}

TEST_F(LinkedListGetTest, T04_GetLastElement) {
    LinkedList<MemoryManager::FixedArena> list({10, 20, 30, 40, 50}, arena);
    Node* node = list.get(4);
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->value, 50);
    EXPECT_EQ(node->next, nullptr);
    EXPECT_EQ(node->prev->value, 40);
}

TEST_F(LinkedListGetTest, T05_IndexEqualToSizeThrows) {
    LinkedList<MemoryManager::FixedArena> list({10, 20, 30, 40, 50}, arena);
    EXPECT_THROW({
        list.get(5);
    }, std::invalid_argument);
}

TEST_F(LinkedListGetTest, T06_IndexMuchGreaterThanSizeThrows) {
    LinkedList<MemoryManager::FixedArena> list({10, 20, 30, 40, 50}, arena);
    EXPECT_THROW({
        list.get(999);
    }, std::invalid_argument);
}

TEST_F(LinkedListGetTest, T07_GetFromEmptyListThrows) {
    LinkedList<MemoryManager::FixedArena> empty_list(arena);
    EXPECT_THROW({
        empty_list.get(0);
    }, std::invalid_argument);
}

TEST_F(LinkedListGetTest, T08_InternalNullTraversalThrowsLogicError) {
    LinkedList<MemoryManager::FixedArena> corrupted({1, 2, 3, 4, 5}, arena);
    corrupted.first->next = nullptr; // Force corruption
    EXPECT_THROW({
        corrupted.get(2);
    }, std::logic_error);
}

TEST_F(LinkedListGetTest, T09_TooBigIndexSizeTMaxThrows) {
    LinkedList<MemoryManager::FixedArena> list({10, 20, 30, 40, 50}, arena);
    EXPECT_THROW({
        list.get(std::numeric_limits<size_t>::max());
    }, std::invalid_argument);
}

TEST_F(LinkedListGetTest, T10_GetOnSingleElementList) {
    LinkedList<MemoryManager::FixedArena> list({42}, arena);
    Node* node = list.get(0);
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->value, 42);
    EXPECT_EQ(node->next, nullptr);
    EXPECT_EQ(node->prev, nullptr);
}
#endif