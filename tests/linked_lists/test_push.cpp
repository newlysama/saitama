#include <gtest/gtest.h>

#include "test_selector.hh"
#include "tests/test_utils.hh" 
#include "utils/linked_lists/linked_lists.hh"

#ifdef PUSH

class LinkedListPushTest : public ::testing::Test {};

// ============================== push_front(size_t) ==============================

TEST_F(LinkedListPushTest, T01_PushFrontOnEmptyList) {
    LinkedList list;
    list.push_front(42);

    test_linked_list_integrity(list, {42});
}

TEST_F(LinkedListPushTest, T02_PushFrontMultipleElements) {
    LinkedList list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    test_linked_list_integrity(list, {3, 2, 1});
}

// ============================== push_front(unique_ptr<Node>) ==============================

TEST_F(LinkedListPushTest, T03_PushFrontNodeOnEmptyList) {
    LinkedList list;
    std::unique_ptr<Node> node = std::make_unique<Node>(42);
    list.push_front(std::move(node));

    test_linked_list_integrity(list, {42});
}

TEST_F(LinkedListPushTest, T04_PushFrontNodeMultipleElements) {
    LinkedList list;
    std::unique_ptr<Node> node1 = std::make_unique<Node>(1);
    std::unique_ptr<Node> node2 = std::make_unique<Node>(2);
    std::unique_ptr<Node> node3 = std::make_unique<Node>(3);
    list.push_front(std::move(node1));
    list.push_front(std::move(node2));
    list.push_front(std::move(node3));

    test_linked_list_integrity(list, {3, 2, 1});
}

TEST_F(LinkedListPushTest, T05_PushFrontUniquePtrThrowsOnNullptr) {
    LinkedList list;
    std::unique_ptr<Node> null_node = nullptr;

    EXPECT_THROW(list.push_front(std::move(null_node)), std::invalid_argument);
}

// ============================== push_back(size_t) ==============================

TEST_F(LinkedListPushTest, T06_PushBackOnEmptyList) {
    LinkedList list;
    list.push_back(7);

    test_linked_list_integrity(list, {7});
}

TEST_F(LinkedListPushTest, T07_PushBackMultipleElements) {
    LinkedList list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    test_linked_list_integrity(list, {10, 20, 30});
}

// ============================== push_back(unique_ptr<Node>) ==============================

TEST_F(LinkedListPushTest, T08_PushBackNodeOnEmptyList) {
    LinkedList list;
    std::unique_ptr<Node> node = std::make_unique<Node>(99);
    list.push_back(std::move(node));

    test_linked_list_integrity(list, {99});
}

TEST_F(LinkedListPushTest, T09_PushBackMultipleUniqueNodes) {
    LinkedList list;
    list.push_back(std::make_unique<Node>(1));
    list.push_back(std::make_unique<Node>(2));
    list.push_back(std::make_unique<Node>(3));

    test_linked_list_integrity(list, {1, 2, 3});
}

TEST_F(LinkedListPushTest, T10_PushBackUniquePtrThrowsOnNullptr) {
    LinkedList list;
    std::unique_ptr<Node> null_node = nullptr;

    EXPECT_THROW(list.push_back(std::move(null_node)), std::invalid_argument);
}

#endif