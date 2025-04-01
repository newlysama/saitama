#include <gtest/gtest.h>
#include <linked_lists/linked_lists.hh>
#include <test_utils.hh>

class PushTest : public ::testing::Test {
protected:
    std::unique_ptr<LinkedList> list;

    void SetUp() override {
        list = std::make_unique<LinkedList>();
    }
};

// ============================== push_front ==============================

TEST_F(PushTest, T01_PushFrontOnEmptyList) {
    list->push_front(42);

    test_linked_list_integrity(*list, {42});
}

TEST_F(PushTest, T02_PushFrontMultipleElements) {
    list->push_front(1);
    list->push_front(2);
    list->push_front(3);

    test_linked_list_integrity(*list, {3, 2, 1});
}

// ============================== push_back(size_t) ==============================

TEST_F(PushTest, T03_PushBackOnEmptyList) {
    list->push_back(7);

    test_linked_list_integrity(*list, {7});
}

TEST_F(PushTest, T04_PushBackMultipleElements) {
    list->push_back(10);
    list->push_back(20);
    list->push_back(30);

    test_linked_list_integrity(*list, {10, 20, 30});
}

// ============================== push_back(unique_ptr<Node>) ==============================

TEST_F(PushTest, T05_PushBackNodeOnEmptyList) {
    std::unique_ptr<Node> node = std::make_unique<Node>(99, nullptr, nullptr);
    list->push_back(std::move(node));

    test_linked_list_integrity(*list, {99});
}

TEST_F(PushTest, T06_PushBackMultipleUniqueNodes) {
    list->push_back(std::make_unique<Node>(1, nullptr, nullptr));
    list->push_back(std::make_unique<Node>(2, nullptr, nullptr));
    list->push_back(std::make_unique<Node>(3, nullptr, nullptr));

    test_linked_list_integrity(*list, {1, 2, 3});
}

TEST_F(PushTest, T06_PushBackUniquePtrThrowsOnNullptr) {
    std::unique_ptr<Node> null_node = nullptr;

    EXPECT_THROW(list->push_back(std::move(null_node)), std::invalid_argument);
}