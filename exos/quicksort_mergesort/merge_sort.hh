#pragma once

#include <exception>

#include "utils/linked_lists/linked_lists.hh"
#include "utils/linked_lists/linked_lists_algorithms.hh"
#include "utils/vector_utils/vector_utils.hh"

/**
 * @brief Merge sort algorithm applied to linked lists
 * @param list the list we want to sort
 */
void merge_sort(LinkedList& list);

/**
 * @brief Merge sort algorithm applied to vectors
 * @details Can't make this one in-place, since VectorUtils::merge() is not (see details on this function)
 * @param list the list we want to sort
 * @return the new sorted list
 * @todo Implement merge_sort in-place
 */
std::pmr::vector<std::size_t> merge_sort(std::pmr::vector<size_t> list);