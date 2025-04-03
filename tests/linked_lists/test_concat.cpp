#include <gtest/gtest.h>
#include <linked_lists/linked_lists.hh>
#include <linked_lists/linked_lists_algorithms.hh>
#include <test_utils.hh>

using namespace LinkedListAlgorithm;

class LinkedListConcatTest : public ::testing::Test {};

TEST_F(LinkedListConcatTest, T01_TwoNonEmptyLists) {
    LinkedList left({1, 3});
    LinkedList right({2, 4});
    concat(left, right);

    test_linked_list_integrity(left, {1, 3, 2, 4});
}

TEST_F(LinkedListConcatTest, T02_FirstListEmpty) {
    LinkedList left;
    LinkedList right({5, 6});
    concat(left, right);

    test_linked_list_integrity(left, {5, 6});
}

TEST_F(LinkedListConcatTest, T03_SecondListEmpty) {
    LinkedList left({7, 8});
    LinkedList right;
    concat(left, right);

    test_linked_list_integrity(left, {7, 8});
}

TEST_F(LinkedListConcatTest, T04_BothListsEmpty) {
    LinkedList left;
    LinkedList right;
    concat(left, right);
    test_linked_list_integrity(left, {});
}

TEST_F(LinkedListConcatTest, T05_ConcatMultipleTimes) {
    LinkedList l1({1, 2});
    auto l2 = LinkedList({3, 4});
    auto l3 = LinkedList({5, 6});

    concat(l1, l2);
    concat(l1, l3);

    test_linked_list_integrity(l1, {1, 2, 3, 4, 5, 6});
}

TEST_F(LinkedListConcatTest, T06_ForceCorruption) {
    LinkedList left({1, 3});
    LinkedList right({2, 4});
    left.last = nullptr; // Force corruption

    EXPECT_THROW({
        concat(left, right);
    }, std::logic_error);
}
