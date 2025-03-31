#pragma once

#include <linked_lists/linked_lists.hh>

/*
 *  ============================= LINKED LISTS =============================
*/

// Quick sort using Lomuto's partition algorithm
std::unique_ptr<LinkedList> quick_sort_lomuto(std::unique_ptr<LinkedList> list);

// Quick sort using Hoare partition algorithm (in-place implementation this time because let's do both)
void quick_sort_hoare(LinkedList& list, size_t low, size_t high);

/*
 *  ============================= VECTORS =============================
*/

// Lomuto's partition algorithm on vectors
size_t partition_lomuto(std::vector<size_t>& list, size_t low, size_t high);

// Hoare's partition algorithm
size_t partition_hoare(std::vector<size_t>& list, size_t low, size_t high) ;

// Guess x)
void quick_sort_lomuto(std::vector<size_t>& list, size_t low, size_t high);

void quick_sort_hoare(std::vector<size_t>& list, size_t low, size_t high);