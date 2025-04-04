#include <gtest/gtest.h>

#include "test_selector.hh"
#include "tests/test_utils.hh" 
#include "utils/linked_lists/linked_lists.hh"

#ifdef GET

class LinkedListGetTest : public ::testing::Test {
protected:
    std::unique_ptr<LinkedList> list;

    void SetUp() override {
        list = std::make_unique<LinkedList>(std::vector<size_t>{10, 20, 30, 40, 50});
    }
};

TEST_F(LinkedListGetTest, T01_GetFirstElement) {
    Node* node = list->get(0);
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->value, 10);
    EXPECT_EQ(node->prev, nullptr);
}

TEST_F(LinkedListGetTest, T02_GetMiddleElement_FirstHalf) {
    Node* node = list->get(2);
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->value, 30);
    EXPECT_EQ(node->prev->value, 20);
}

TEST_F(LinkedListGetTest, T03_GetMiddleElement_SecondHalf) {
    Node* node = list->get(3);
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->value, 40);
    EXPECT_EQ(node->prev->value, 30);
}

TEST_F(LinkedListGetTest, T04_GetLastElement) {
    Node* node = list->get(4);
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->value, 50);
    EXPECT_EQ(node->next, nullptr);
    EXPECT_EQ(node->prev->value, 40);
}

TEST_F(LinkedListGetTest, T05_IndexEqualToSizeThrows) {
    EXPECT_THROW({
        list->get(5);
    }, std::invalid_argument);
}

TEST_F(LinkedListGetTest, T06_IndexMuchGreaterThanSizeThrows) {
    EXPECT_THROW({
        list->get(999);
    }, std::invalid_argument);
}

TEST_F(LinkedListGetTest, T07_GetFromEmptyListThrows) {
    LinkedList empty_list;
    EXPECT_THROW({
        empty_list.get(0);
    }, std::invalid_argument);
}

TEST_F(LinkedListGetTest, T08_InternalNullTraversalThrowsLogicError) {
    list->first = nullptr;
    list->size = 5;
    EXPECT_THROW({
        list->get(0);
    }, std::logic_error);
}

TEST_F(LinkedListGetTest, T09_TooBigIndexSizeTMaxThrows) {
    EXPECT_THROW({
        list->get(std::numeric_limits<size_t>::max());
    }, std::invalid_argument);
}

TEST_F(LinkedListGetTest, T10_GetOnSingleElementList) {
    LinkedList list2 = LinkedList({42});
    Node* node = list2.get(0);
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->value, 42);
    EXPECT_EQ(node->next, nullptr);
    EXPECT_EQ(node->prev, nullptr);
}

#endif