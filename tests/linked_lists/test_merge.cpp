#include <gtest/gtest.h>
#include <linked_lists/linked_lists.hh>
#include <test_utils.hh>

class MergeTest : public ::testing::Test {
protected:
    std::unique_ptr<LinkedList> list1;
    std::unique_ptr<LinkedList> list2;

    void SetUp() override {
        list1 = std::make_unique<LinkedList>();
        list2 = std::make_unique<LinkedList>();
    }
};

TEST_F(MergeTest, T01_BothEmpty) {
    auto result = LinkedList::merge(std::move(list1), std::move(list2));
    test_linked_list_integrity(*result, {});
}

TEST_F(MergeTest, T02_FirstEmpty) {
    list2 = std::make_unique<LinkedList>(std::vector<size_t>{1, 3, 5});
    auto result = LinkedList::merge(std::move(list1), std::move(list2));
    test_linked_list_integrity(*result, {1, 3, 5});
}

TEST_F(MergeTest, T03_SecondEmpty) {
    list1 = std::make_unique<LinkedList>(std::vector<size_t>{2, 4});
    auto result = LinkedList::merge(std::move(list1), std::move(list2));
    test_linked_list_integrity(*result, {2, 4});
}

TEST_F(MergeTest, T04_AlternatingElements) {
    list1 = std::make_unique<LinkedList>(std::vector<size_t>{1, 3, 5});
    list2 = std::make_unique<LinkedList>(std::vector<size_t>{2, 4, 6});
    auto result = LinkedList::merge(std::move(list1), std::move(list2));
    test_linked_list_integrity(*result, {1, 2, 3, 4, 5, 6});
}

TEST_F(MergeTest, T05_List1BeforeList2) {
    list1 = std::make_unique<LinkedList>(std::vector<size_t>{1, 2});
    list2 = std::make_unique<LinkedList>(std::vector<size_t>{3, 4});
    auto result = LinkedList::merge(std::move(list1), std::move(list2));
    test_linked_list_integrity(*result, {1, 2, 3, 4});
}

TEST_F(MergeTest, T06_List2BeforeList1) {
    list1 = std::make_unique<LinkedList>(std::vector<size_t>{5, 6});
    list2 = std::make_unique<LinkedList>(std::vector<size_t>{1, 2});
    auto result = LinkedList::merge(std::move(list1), std::move(list2));
    test_linked_list_integrity(*result, {1, 2, 5, 6});
}

TEST_F(MergeTest, T07_WithDuplicates) {
    list1 = std::make_unique<LinkedList>(std::vector<size_t>{1, 2, 2});
    list2 = std::make_unique<LinkedList>(std::vector<size_t>{2, 3});
    auto result = LinkedList::merge(std::move(list1), std::move(list2));
    test_linked_list_integrity(*result, {1, 2, 2, 2, 3});
}

TEST_F(MergeTest, T08_SingleElementEach) {
    list1 = std::make_unique<LinkedList>(std::vector<size_t>{2});
    list2 = std::make_unique<LinkedList>(std::vector<size_t>{1});
    auto result = LinkedList::merge(std::move(list1), std::move(list2));
    test_linked_list_integrity(*result, {1, 2});
}

TEST_F(MergeTest, T09_SingleElementAndMultiple) {
    list1 = std::make_unique<LinkedList>(std::vector<size_t>{5});
    list2 = std::make_unique<LinkedList>(std::vector<size_t>{1, 2, 3});
    auto result = LinkedList::merge(std::move(list1), std::move(list2));
    test_linked_list_integrity(*result, {1, 2, 3, 5});
}
