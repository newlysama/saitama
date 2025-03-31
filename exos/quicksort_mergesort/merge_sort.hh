#pragma once

#include <exception>

#include <linked_lists/linked_lists.hh>

/*
 *  ============================= LINKED LISTS =============================
*/

// Merge sort on linked lists
std::unique_ptr<LinkedList> merge_sort(std::unique_ptr<LinkedList> list);

/*
 *  ============================= VECTORS =============================
*/

// Split two vectors (no shit)
std::tuple<std::vector<std::size_t>, std::vector<std::size_t>> split(std::vector<std::size_t> list);

// Merge two vectors
std::vector<std::size_t> merge(std::vector<std::size_t> list1, std::vector<std::size_t> list2);

// Merge sort on vectors
std::vector<std::size_t> merge_sort(std::vector<size_t> list);