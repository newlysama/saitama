#pragma once

#include <linked_lists/linked_lists.hh>
#include <linked_lists/linked_lists_algorithms.hh>
#include <vector_utils/vector_utils.hh>
#include <logger/logger.hh>

// Quick sort using Lomuto's partition algorithm
void quick_sort_lomuto(LinkedList& list);

// Quick sort using Hoare partition algorithm (in-place implementation this time because let's do both)
void quick_sort_hoare(LinkedList& list);

void quick_sort_lomuto(std::vector<size_t>& list);

void quick_sort_hoare(std::vector<size_t>& list);