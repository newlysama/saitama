#pragma once

#include <exception>

#include <linked_lists/linked_lists.hh>
#include <linked_lists/linked_lists_algorithms.hh>
#include <vector_utils/vector_utils.hh>

/**
 * @brief merge sort algorithm applied to linked lists
 * @details This is an in-place version, avoiding to create multiple new lists
 *          as we split 'list'
 * @param list the list we want to sort
 */
void merge_sort(LinkedList& list);

/**
 * @brief Merge sort algorithm applied to vectors 
 * @param list the list we want to sort
 * @return the new sorted list
 * @todo Implement merge_sort as in-place
 */
std::vector<std::size_t> merge_sort(std::vector<size_t> list);