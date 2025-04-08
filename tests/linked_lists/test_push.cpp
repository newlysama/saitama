#include "test_config.hh"

using namespace TestUtils;

#ifdef PUSH

class LinkedListPushTest : public ::testing::Test {
protected:
    std::shared_ptr<std::pmr::memory_resource> arena;

    void SetUp() override {
        arena = MemoryManager::instance().create_arena(1024 * 16);
    }

    void TearDown() override {
        MemoryManager::instance().release_arena(arena.get());
    }
};

// ============================== push_front(size_t) ==============================

TEST_F(LinkedListPushTest, T01_PushFrontOnEmptyList) {
    LinkedList list(arena.get());
    list.push_front(42);

    test_linked_list_integrity(list, {42});
}

TEST_F(LinkedListPushTest, T02_PushFrontMultipleElements) {
    LinkedList list(arena.get());
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    test_linked_list_integrity(list, {3, 2, 1});
}

// ============================== push_front(Node*) ==============================

TEST_F(LinkedListPushTest, T03_PushFrontNodeOnEmptyList) {
    LinkedList list(arena.get());
    Node* node = Node::create(arena.get(), 42);

    list.push_front(node);

    test_linked_list_integrity(list, {42});
}

TEST_F(LinkedListPushTest, T04_PushFrontNodeMultipleElements) {
    LinkedList list(arena.get());
    std::pmr::polymorphic_allocator<Node> alloc(arena.get());

    Node* node1 = Node::create(arena.get(), 1);
    Node* node2 = Node::create(arena.get(), 2);
    Node* node3 = Node::create(arena.get(), 3);

    list.push_front(node1);
    list.push_front(node2);
    list.push_front(node3);

    test_linked_list_integrity(list, {3, 2, 1});
}

TEST_F(LinkedListPushTest, T05_PushFrontThrowsOnNullptr) {
    LinkedList list(arena.get());
    EXPECT_THROW(list.push_front(static_cast<Node*>(nullptr)), std::invalid_argument);
}

// ============================== push_back(size_t) ==============================

TEST_F(LinkedListPushTest, T06_PushBackOnEmptyList) {
    LinkedList list(arena.get());
    list.push_back(7);

    test_linked_list_integrity(list, {7});
}

TEST_F(LinkedListPushTest, T07_PushBackMultipleElements) {
    LinkedList list(arena.get());
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    test_linked_list_integrity(list, {10, 20, 30});
}

// ============================== push_back(Node*) ==============================

TEST_F(LinkedListPushTest, T08_PushBackNodeOnEmptyList) {
    LinkedList list(arena.get());
    Node* node = Node::create(arena.get(), 99);
    list.push_back(node);

    test_linked_list_integrity(list, {99});
}

TEST_F(LinkedListPushTest, T09_PushBackMultipleNodes) {
    LinkedList list(arena.get());
    std::pmr::polymorphic_allocator<Node> alloc(arena.get());

    Node* node1 = Node::create(arena.get(), 1);
    Node* node2 = Node::create(arena.get(), 2);
    Node* node3 = Node::create(arena.get(), 3);

    list.push_back(node1);
    list.push_back(node2);
    list.push_back(node3);

    test_linked_list_integrity(list, {1, 2, 3});
}

TEST_F(LinkedListPushTest, T10_PushBackThrowsOnNullptr) {
    LinkedList list(arena.get());
    EXPECT_THROW(list.push_back(static_cast<Node*>(nullptr)), std::invalid_argument);
}

#endif
