#include <gtest/gtest.h>
#include <linked_lists/linked_lists.hh>
#include <linked_lists/linked_lists_algorithms.hh>
#include <test_utils.hh>

using namespace LinkedListAlgorithm;

class LinkedListConcatTest : public ::testing::Test {
protected:
    std::unique_ptr<LinkedList> left;
    std::unique_ptr<LinkedList> right;

    void SetUp() override {
        left = std::make_unique<LinkedList>();
        right = std::make_unique<LinkedList>();
    }
};

TEST_F(LinkedListConcatTest, T01_TwoNonEmptyLists) {
    left = std::make_unique<LinkedList>(std::vector<size_t>{1, 3});
    right = std::make_unique<LinkedList>(std::vector<size_t>{2, 4});
    concat(left, right);

    test_linked_list_integrity(*left, {1, 3, 2, 4});
}

TEST_F(LinkedListConcatTest, T02_FirstListEmpty) {
    right = std::make_unique<LinkedList>(std::vector<size_t>{5, 6});
    concat(left, right);

    test_linked_list_integrity(*left, {5, 6});
}

TEST_F(LinkedListConcatTest, T03_SecondListEmpty) {
    left = std::make_unique<LinkedList>(std::vector<size_t>{7, 8});
    concat(left, right);

    test_linked_list_integrity(*left, {7, 8});
}

TEST_F(LinkedListConcatTest, T04_BothListsEmpty) {
    concat(left, right);
    test_linked_list_integrity(*left, {});
}

TEST_F(LinkedListConcatTest, T05_ConcatMultipleTimes) {
    auto l1 = std::make_unique<LinkedList>(std::vector<size_t>{1, 2});
    auto l2 = std::make_unique<LinkedList>(std::vector<size_t>{3, 4});
    auto l3 = std::make_unique<LinkedList>(std::vector<size_t>{5, 6});

    concat(l1, l2);
    concat(l1, l3);

    test_linked_list_integrity(*l1, {1, 2, 3, 4, 5, 6});
}

TEST_F(LinkedListConcatTest, T06_ForceCorruption) {
    left = std::make_unique<LinkedList>(std::vector<size_t>{1, 3});
    right = std::make_unique<LinkedList>(std::vector<size_t>{2, 4});
    left->last = nullptr; // Force curruption

    EXPECT_THROW({
        concat(left, right);
    }, std::logic_error);
}