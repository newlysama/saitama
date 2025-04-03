#include <gtest/gtest.h>
#include <linked_lists/linked_lists.hh>
#include <test_utils.hh>
#include "test_selector.hh" 

#ifdef SWAP

class LinkedListSwapValuesTest : public ::testing::Test {};

TEST_F(LinkedListSwapValuesTest, T01_SwapTwoElementsAtBeginning) {
    LinkedList list({1, 2});
    list.swap_values(0, 1);

    test_linked_list_integrity(list, {2, 1});
}

TEST_F(LinkedListSwapValuesTest, T02_SwapTwoMiddleElements) {
    LinkedList list({1, 2, 3, 4});
    list.swap_values(1, 2);

    test_linked_list_integrity(list, {1, 3, 2, 4});
}

TEST_F(LinkedListSwapValuesTest, T03_SwapFirstAndLast) {
    LinkedList list({1, 2, 3, 4});
    list.swap_values(0, 3);

    test_linked_list_integrity(list, {4, 2, 3, 1});
}

TEST_F(LinkedListSwapValuesTest, T04_SameIndexShouldDoNothing) {
    LinkedList list({5, 6, 7});
    list.swap_values(1, 1);

    test_linked_list_integrity(list, {5, 6, 7});
}

TEST_F(LinkedListSwapValuesTest, T05_SwapReverseIndexOrder) {
    LinkedList list({10, 20, 30});
    list.swap_values(2, 0);

    test_linked_list_integrity(list, {30, 20, 10});
}

TEST_F(LinkedListSwapValuesTest, T06_IndexIOutOfBounds) {
    LinkedList list({1, 2});

    EXPECT_THROW(list.swap_values(5, 1), std::invalid_argument);
}

TEST_F(LinkedListSwapValuesTest, T07_IndexJOutOfBounds) {
    LinkedList list({1, 2});

    EXPECT_THROW(list.swap_values(0, 10), std::invalid_argument);
}

TEST_F(LinkedListSwapValuesTest, T08_EmptyListShouldThrow) {
    LinkedList list;

    EXPECT_THROW(list.swap_values(0, 1), std::invalid_argument);
}

TEST_F(LinkedListSwapValuesTest, T09_SwapTwiceRestoresList) {
    LinkedList list({7, 8, 9});
    list.swap_values(0, 2);
    list.swap_values(2, 0);
    test_linked_list_integrity(list, {7, 8, 9});
}

#endif