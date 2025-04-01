#include <gtest/gtest.h>
#include <linked_lists/linked_lists.hh>
#include <test_utils.hh>

class ConcatTest : public ::testing::Test {
protected:
    std::unique_ptr<LinkedList> left;
    std::unique_ptr<LinkedList> right;

    void SetUp() override {
        left = std::make_unique<LinkedList>();
        right = std::make_unique<LinkedList>();
    }
};

TEST_F(ConcatTest, T01_TwoNonEmptyLists) {
    left = std::make_unique<LinkedList>(std::vector<size_t>{1, 3});
    right = std::make_unique<LinkedList>(std::vector<size_t>{2, 4});
    LinkedList::concat(left, right);

    test_linked_list_integrity(*left, {1, 3, 2, 4});
}

TEST_F(ConcatTest, T02_FirstListEmpty) {
    right = std::make_unique<LinkedList>(std::vector<size_t>{5, 6});
    LinkedList::concat(left, right);

    test_linked_list_integrity(*left, {5, 6});
}

TEST_F(ConcatTest, T03_SecondListEmpty) {
    left = std::make_unique<LinkedList>(std::vector<size_t>{7, 8});
    LinkedList::concat(left, right);

    test_linked_list_integrity(*left, {7, 8});
}

TEST_F(ConcatTest, T04_BothListsEmpty) {
    LinkedList::concat(left, right);
    test_linked_list_integrity(*left, {});
}
