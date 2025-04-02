#include <gtest/gtest.h>
#include <linked_lists/linked_lists.hh>
#include <linked_lists/linked_lists_algorithms.hh>
#include <test_utils.hh>

using namespace LinkedListAlgorithm;

class LinkedListConcatTest : public ::testing::Test {
protected:
    std::unique_ptr<LinkedList> right;

    void SetUp() override {
        right = std::make_unique<LinkedList>();
    }
};

TEST_F(LinkedListConcatTest, T01_TwoNonEmptyLists) {
    LinkedList left({1, 3});
    right = std::make_unique<LinkedList>(std::vector<size_t>{2, 4});
    concat(left, std::move(right));

    test_linked_list_integrity(left, {1, 3, 2, 4});
}

TEST_F(LinkedListConcatTest, T02_FirstListEmpty) {
    auto left = LinkedList();
    right = std::make_unique<LinkedList>(std::vector<size_t>{5, 6});
    concat(left, std::move(right));

    test_linked_list_integrity(left, {5, 6});
}

TEST_F(LinkedListConcatTest, T03_SecondListEmpty) {
    LinkedList left({7, 8});
    right = std::make_unique<LinkedList>();
    concat(left, std::move(right));

    test_linked_list_integrity(left, {7, 8});
}

TEST_F(LinkedListConcatTest, T04_BothListsEmpty) {
    auto left = LinkedList();
    concat(left, std::move(right));
    test_linked_list_integrity(left, {});
}

TEST_F(LinkedListConcatTest, T05_ConcatMultipleTimes) {
    LinkedList l1({1, 2});
    auto l2 = std::make_unique<LinkedList>(std::vector<size_t>{3, 4});
    auto l3 = std::make_unique<LinkedList>(std::vector<size_t>{5, 6});

    concat(l1, std::move(l2));
    concat(l1, std::move(l3));

    test_linked_list_integrity(l1, {1, 2, 3, 4, 5, 6});
}

TEST_F(LinkedListConcatTest, T06_ForceCorruption) {
    LinkedList left({1, 3});
    right = std::make_unique<LinkedList>(std::vector<size_t>{2, 4});
    left.last = nullptr; // Force corruption

    EXPECT_THROW({
        concat(left, std::move(right));
    }, std::logic_error);
}
