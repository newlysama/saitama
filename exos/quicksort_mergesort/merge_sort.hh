#pragma once

#include <exception>

#include <linked_lists/linked_lists.hh>
#include <vector_utils/vector_utils.hh>

// Merge sort on linked lists
std::unique_ptr<LinkedList> merge_sort(std::unique_ptr<LinkedList> list);

// Merge sort on vectors
std::vector<std::size_t> merge_sort(std::vector<size_t> list);