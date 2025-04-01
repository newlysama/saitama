#pragma once

#include <vector>
#include <gtest/gtest.h>

#include <linked_lists/linked_lists.hh>

// Check weath a linked list is what we expect it is
// Test its values, size, first, last, nexts and prevs elements
void test_linked_list_integrity(LinkedList& list, const std::vector<size_t>& expected_values);