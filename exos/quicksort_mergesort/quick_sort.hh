#pragma once

#include <linked_lists/linked_lists.hh>
#include <vector_utils/vector_utils.hh>

// Quick sort using Lomuto's partition algorithm
void quick_sort_lomuto(std::unique_ptr<LinkedList>& list);

// Quick sort using Hoare partition algorithm (in-place implementation this time because let's do both)
void quick_sort_hoare(std::unique_ptr<LinkedList>& list, size_t low, size_t high);


void quick_sort_lomuto(std::vector<size_t>& list, size_t low, size_t high);

void quick_sort_hoare(std::vector<size_t>& list, size_t low, size_t high);