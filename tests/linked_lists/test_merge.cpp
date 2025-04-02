#include <gtest/gtest.h>
#include <linked_lists/linked_lists.hh>
#include <linked_lists/linked_lists_algorithms.hh>
#include <test_utils.hh>

using namespace LinkedListAlgorithm;

class LinkedListMergeTest : public ::testing::Test {
protected:
    std::unique_ptr<LinkedList> list1;
    std::unique_ptr<LinkedList> list2;

    void SetUp() override {
        list1 = std::make_unique<LinkedList>();
        list2 = std::make_unique<LinkedList>();
    }
};

TEST_F(LinkedListMergeTest, T01_BothEmpty) {
    auto result = merge(std::move(list1), std::move(list2));
    test_linked_list_integrity(*result, {});
}

TEST_F(LinkedListMergeTest, T02_FirstEmpty) {
    list2 = std::make_unique<LinkedList>(std::vector<size_t>{1, 3, 5});
    auto result = merge(std::move(list1), std::move(list2));
    test_linked_list_integrity(*result, {1, 3, 5});
}

TEST_F(LinkedListMergeTest, T03_SecondEmpty) {
    list1 = std::make_unique<LinkedList>(std::vector<size_t>{2, 4});
    auto result = merge(std::move(list1), std::move(list2));
    test_linked_list_integrity(*result, {2, 4});
}

TEST_F(LinkedListMergeTest, T04_AlternatingElements) {
    list1 = std::make_unique<LinkedList>(std::vector<size_t>{1, 3, 5});
    list2 = std::make_unique<LinkedList>(std::vector<size_t>{2, 4, 6});
    auto result = merge(std::move(list1), std::move(list2));
    test_linked_list_integrity(*result, {1, 2, 3, 4, 5, 6});
}

TEST_F(LinkedListMergeTest, T05_List1BeforeList2) {
    list1 = std::make_unique<LinkedList>(std::vector<size_t>{1, 2});
    list2 = std::make_unique<LinkedList>(std::vector<size_t>{3, 4});
    auto result = merge(std::move(list1), std::move(list2));
    test_linked_list_integrity(*result, {1, 2, 3, 4});
}

TEST_F(LinkedListMergeTest, T06_List2BeforeList1) {
    list1 = std::make_unique<LinkedList>(std::vector<size_t>{5, 6});
    list2 = std::make_unique<LinkedList>(std::vector<size_t>{1, 2});
    auto result = merge(std::move(list1), std::move(list2));
    test_linked_list_integrity(*result, {1, 2, 5, 6});
}

TEST_F(LinkedListMergeTest, T07_WithDuplicates) {
    list1 = std::make_unique<LinkedList>(std::vector<size_t>{1, 2, 2});
    list2 = std::make_unique<LinkedList>(std::vector<size_t>{2, 3});
    auto result = merge(std::move(list1), std::move(list2));
    test_linked_list_integrity(*result, {1, 2, 2, 2, 3});
}

TEST_F(LinkedListMergeTest, T08_SingleElementEach) {
    list1 = std::make_unique<LinkedList>(std::vector<size_t>{2});
    list2 = std::make_unique<LinkedList>(std::vector<size_t>{1});
    auto result = merge(std::move(list1), std::move(list2));
    test_linked_list_integrity(*result, {1, 2});
}

TEST_F(LinkedListMergeTest, T09_SingleElementAndMultiple) {
    list1 = std::make_unique<LinkedList>(std::vector<size_t>{5});
    list2 = std::make_unique<LinkedList>(std::vector<size_t>{1, 2, 3});
    auto result = merge(std::move(list1), std::move(list2));
    test_linked_list_integrity(*result, {1, 2, 3, 5});
}

TEST_F(LinkedListMergeTest, T10_MixedLengthLists) {
    list1 = std::make_unique<LinkedList>(std::vector<size_t>{1});
    list2 = std::make_unique<LinkedList>(std::vector<size_t>{2, 3, 4, 5});
    auto result = merge(std::move(list1), std::move(list2));
    test_linked_list_integrity(*result, {1, 2, 3, 4, 5});
}

TEST_F(LinkedListMergeTest, T11_InterleavedEqualElements) {
    list1 = std::make_unique<LinkedList>(std::vector<size_t>{1, 3, 5});
    list2 = std::make_unique<LinkedList>(std::vector<size_t>{1, 3, 5});
    auto result = merge(std::move(list1), std::move(list2));
    test_linked_list_integrity(*result, {1, 1, 3, 3, 5, 5});
}

TEST_F(LinkedListMergeTest, T12_LargeLists) {
    std::vector<size_t> v1(500, 1);
    std::vector<size_t> v2(500, 2);
    list1 = std::make_unique<LinkedList>(v1);
    list2 = std::make_unique<LinkedList>(v2);
    auto result = merge(std::move(list1), std::move(list2));

    std::vector<size_t> expected(1000);
    std::fill(expected.begin(), expected.begin() + 500, 1);
    std::fill(expected.begin() + 500, expected.end(), 2);
    test_linked_list_integrity(*result, expected);
}