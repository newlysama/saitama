#include <gtest/gtest.h>
#include <linked_lists/linked_lists.hh>
#include <linked_lists/linked_lists_algorithms.hh>
#include <test_utils.hh>
#include "test_selector.hh" 

using namespace LinkedListAlgorithm;

#ifdef MERGE

class LinkedListMergeTest : public ::testing::Test {
protected:
    void SetUp() override {}
};

TEST_F(LinkedListMergeTest, T01_BothEmpty) {
    LinkedList left;
    LinkedList right;
    merge(left, right);
    test_linked_list_integrity(left, {});
}

TEST_F(LinkedListMergeTest, T02_FirstEmpty) {
    LinkedList left;
    LinkedList right({1, 3, 5});
    merge(left, right);
    test_linked_list_integrity(left, {1, 3, 5});
}

TEST_F(LinkedListMergeTest, T03_SecondEmpty) {
    LinkedList left({2, 4});
    LinkedList right;
    merge(left, right);
    test_linked_list_integrity(left, {2, 4});
}

TEST_F(LinkedListMergeTest, T04_AlternatingElements) {
    LinkedList left({1, 3, 5});
    LinkedList right({2, 4, 6});
    merge(left, right);
    test_linked_list_integrity(left, {1, 2, 3, 4, 5, 6});
}

TEST_F(LinkedListMergeTest, T05_List1BeforeList2) {
    LinkedList left({1, 2});
    LinkedList right({3, 4});
    merge(left, right);
    test_linked_list_integrity(left, {1, 2, 3, 4});
}

TEST_F(LinkedListMergeTest, T06_List2BeforeList1) {
    LinkedList left({5, 6});
    LinkedList right({1, 2});
    merge(right, left);
    test_linked_list_integrity(right, {1, 2, 5, 6});
}

TEST_F(LinkedListMergeTest, T07_WithDuplicates) {
    LinkedList left({1, 2, 2});
    LinkedList right({2, 3});
    merge(left, right);
    test_linked_list_integrity(left, {1, 2, 2, 2, 3});
}

TEST_F(LinkedListMergeTest, T08_SingleElementEach) {
    LinkedList left({2});
    LinkedList right({1});
    merge(left, right);
    left.print();
    test_linked_list_integrity(left, {1, 2});
}

TEST_F(LinkedListMergeTest, T09_SingleElementAndMultiple) {
    LinkedList left({5});
    LinkedList right({1, 2, 3});
    merge(left, right);
    test_linked_list_integrity(left, {1, 2, 3, 5});
}

TEST_F(LinkedListMergeTest, T10_MixedLengthLists) {
    LinkedList left({1});
    LinkedList right({2, 3, 4, 5});
    merge(left, right);
    test_linked_list_integrity(left, {1, 2, 3, 4, 5});
}

TEST_F(LinkedListMergeTest, T11_InterleavedEqualElements) {
    LinkedList left({1, 3, 5});
    LinkedList right({1, 3, 5});
    merge(left, right);
    test_linked_list_integrity(left, {1, 1, 3, 3, 5, 5});
}

TEST_F(LinkedListMergeTest, T12_LargeLists) {
    std::vector<size_t> v1(500, 1);
    std::vector<size_t> v2(500, 2);
    LinkedList left(v1);
    LinkedList right(v2);
    merge(left, right);

    std::vector<size_t> expected(1000);
    std::fill(expected.begin(), expected.begin() + 500, 1);
    std::fill(expected.begin() + 500, expected.end(), 2);
    test_linked_list_integrity(left, expected);
}

#endif