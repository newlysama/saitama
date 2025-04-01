#include <gtest/gtest.h>
#include <linked_lists/linked_lists.hh>
#include <test_utils.hh>

class InitTest : public ::testing::Test {};

TEST_F(InitTest, T_01_DefaultConstructorCreatesEmptyList) {
    LinkedList list;
    test_linked_list_integrity(list, {});
}

TEST_F(InitTest, T_02_InitFromEmptyVectorCreatesEmptyList) {
    std::vector<size_t> input = {};
    LinkedList list(input);
    test_linked_list_integrity(list, input);
}

TEST_F(InitTest, T_03_InitFromSingleElementVector) {
    std::vector<size_t> input = {42};
    LinkedList list(input);
    test_linked_list_integrity(list, input);
}

TEST_F(InitTest, T_04_InitFromMultipleElementsVector) {
    std::vector<size_t> input = {10, 20, 30, 40};
    LinkedList list(input);
    test_linked_list_integrity(list, input);
}
