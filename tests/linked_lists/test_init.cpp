#include <gtest/gtest.h>
#include <linked_lists/linked_lists.hh>
#include <test_utils.hh>
#include "test_selector.hh" 

#ifdef INIT

class LinkedListInitTest : public ::testing::Test {};

TEST_F(LinkedListInitTest, T_01_DefaultConstructorCreatesEmptyList) {
    LinkedList list;
    test_linked_list_integrity(list, {});
}

TEST_F(LinkedListInitTest, T_02_InitFromEmptyVectorCreatesEmptyList) {
    std::vector<size_t> input = {};
    LinkedList list(input);
    test_linked_list_integrity(list, input);
}

TEST_F(LinkedListInitTest, T_03_InitFromSingleElementVector) {
    std::vector<size_t> input = {42};
    LinkedList list(input);
    test_linked_list_integrity(list, input);
}

TEST_F(LinkedListInitTest, T_04_InitFromMultipleElementsVector) {
    std::vector<size_t> input = {10, 20, 30, 40};
    LinkedList list(input);
    test_linked_list_integrity(list, input);
}

TEST_F(LinkedListInitTest, T_05_MoveConstructor) {
    LinkedList original({1, 2, 3});
    LinkedList moved(std::move(original));

    test_linked_list_integrity(moved, {1, 2, 3});

    EXPECT_TRUE(original.empty());
    EXPECT_EQ(original.size, 0);
    EXPECT_EQ(original.first, nullptr);
    EXPECT_EQ(original.last, nullptr);
}

TEST_F(LinkedListInitTest, T_06_MoveAssignmentOperator) {
    LinkedList original({4, 5, 6});
    LinkedList moved;

    moved = std::move(original);
    test_linked_list_integrity(moved, {4, 5, 6});

    EXPECT_TRUE(original.empty());
    EXPECT_EQ(original.size, 0);
    EXPECT_EQ(original.first, nullptr);
    EXPECT_EQ(original.last, nullptr);
}

TEST_F(LinkedListInitTest, T_07_SelfMoveAssignmentDoesNothing) {
    LinkedList list({7, 8, 9});
    LinkedList& ref = list;

    list = std::move(ref);  // simulate self-move
    test_linked_list_integrity(list, {7, 8, 9}); // should remain unchanged
}

#endif