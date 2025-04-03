/**
 * @brief In linked list algorithms, we prefer split the split the lists before
 * recurisve call, as this gives direct access to low and high values, used in partition algorithms.
 */

#pragma once

#include <linked_lists/linked_lists.hh>
#include <linked_lists/linked_lists_algorithms.hh>
#include <vector_utils/vector_utils.hh>
#include <logger/logger.hh>

/**
 * @brief Quick sort algorithm applied to linked lists using lomuto's partition scheme
 * @param list the list we want to sort
 */
void quick_sort_lomuto(LinkedList& list);

/**
 * @brief Quick sort algorithm applied to linked lists using hoare's partition scheme
 * @param list the list we want to sort
 */
void quick_sort_hoare(LinkedList& list);

/**
 * @brief Quick sort algorithm applied to vectors using lomuto's partition scheme
 * @param list the list we want to sort
 */
void quick_sort_lomuto(std::vector<size_t>& list);

/**
 * @brief Quick sort algorithm applied to vectors using hoare's partition scheme
 * @param list the list we want to sort
 */
void quick_sort_hoare(std::vector<size_t>& list);