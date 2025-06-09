#pragma once

#include <exception>

#include "utils/linked_lists/linked_lists.hh"
#include "utils/linked_lists/linked_lists_algorithms.hh"
#include "utils/vector_utils/vector_utils.hh"

using ScalableVector = std::vector<size_t, tbb::scalable_allocator<size_t>>;

/**
 * @brief Merge sort algorithm applied to linked lists
 * @param list the list we want to sort
 */
void merge_sort(LinkedList<MemoryManager::FixedArena>& list);

/**
 * @brief Merge sort algorithm applied to vectors
 * @details Can't make this one in-place, since VectorUtils::merge() is not (see details on this function)
 * @param vector the vector we want to sort
 * @return the new sorted vector
 * @todo Implement merge_sort in-place
 */
ScalableVector merge_sort(ScalableVector vector);