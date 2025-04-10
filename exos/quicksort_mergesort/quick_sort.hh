#pragma once

/**
 * @brief In linked list quicksort algorithms, we prefer split the lists before
 * recurisve call, as this gives direct access to low and high indexes, used in partition algorithms.
 * This version is not more memory consuming, since that we have a pre-allocated buffer.
 */

#include <exception>

#include "utils/linked_lists/linked_lists.hh"
#include "utils/linked_lists/linked_lists_algorithms.hh"
#include "utils/vector_utils/vector_utils.hh"

using ScalableVector = std::vector<size_t, tbb::scalable_allocator<size_t>>;

/**
 * @brief Quick sort algorithm applied to linked lists using lomuto's partition scheme
 * @param list the list we want to sort
 */
void quick_sort_lomuto(LinkedList<MemoryManager::FixedArena>& list);

/**
 * @brief Quick sort algorithm applied to linked lists using hoare's partition scheme
 * @param list the list we want to sort
 */
void quick_sort_hoare(LinkedList<MemoryManager::FixedArena>& list);

/**
 * @brief Quick sort algorithm applied to vectors using lomuto's partition scheme
 * @param vector the vector we want to sort
 */
void quick_sort_lomuto(ScalableVector& vector);

/**
 * @brief Quick sort algorithm applied to vectors using hoare's partition scheme
 * @param vector the vector we want to sort
 */
void quick_sort_hoare(ScalableVector& vector);