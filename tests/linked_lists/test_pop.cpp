#include <gtest/gtest.h>
#include <linked_lists/linked_lists.hh>
#include <test_utils.hh>

class PopTest : public ::testing::Test {};

/*
 * ======================== pop_front ========================
 */

TEST_F(PopTest, T_01_PopFrontThrowsOnEmptyList) {
    LinkedList list;
    EXPECT_THROW(list.pop_front(), std::invalid_argument);
}

TEST_F(PopTest, T_02_PopFrontOnSingleElementList) {
    LinkedList list({42});
    auto node = list.pop_front();

    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->value, 42);
    EXPECT_EQ(node->next, nullptr);
    EXPECT_EQ(node->prev, nullptr);

    test_linked_list_integrity(list, {});
}

TEST_F(PopTest, T_03_PopFrontOnMultipleElementList) {
    LinkedList list({10, 20, 30});
    auto node = list.pop_front();

    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->value, 10);
    EXPECT_EQ(node->next, nullptr);
    EXPECT_EQ(node->prev, nullptr);

    test_linked_list_integrity(list, {20, 30});
}

/*
 * ======================== pop_back ========================
 */

TEST_F(PopTest, T_04_PopBackThrowsOnEmptyList) {
    LinkedList list;
    EXPECT_THROW(list.pop_back(), std::invalid_argument);
}

TEST_F(PopTest, T_05_PopBackThrowsIfLastIsNull) {
    LinkedList list({1});
    list.last = nullptr;  // Simulate corrupted state
    EXPECT_THROW(list.pop_back(), std::logic_error);
}

TEST_F(PopTest, T_06_PopBackOnSingleElementList) {
    LinkedList list({99});
    auto node = list.pop_back();

    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->value, 99);
    EXPECT_EQ(node->next, nullptr);
    EXPECT_EQ(node->prev, nullptr);

    test_linked_list_integrity(list, {});
}

TEST_F(PopTest, T_07_PopBackOnMultipleElementList) {
    LinkedList list({5, 10, 15});
    auto node = list.pop_back();

    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->value, 15);
    EXPECT_EQ(node->prev, nullptr);
    EXPECT_EQ(node->next, nullptr);

    test_linked_list_integrity(list, {5, 10});
}
