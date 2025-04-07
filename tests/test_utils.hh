#pragma once

#include <vector>
#include <gtest/gtest.h>

#include "utils/linked_lists/linked_lists.hh"

/**
 * @brief Namespace implementing utilities functions four our tests
 */
namespace TestUtils {
    /**
     * @brief Test a linked list's integrity
     * @details Asserts that the values, the size, last and first are what we expect.
     *          Also checks the ->next and ->prev connections
     * @param list the list to test
     * @param expected_values the witness vector (reference)
     */
    void test_linked_list_integrity(LinkedList& list, const std::vector<size_t>& expected_values);
}
