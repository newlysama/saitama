#pragma once

/**
 * @brief Implements our quick sort and merge sort algorithms benchmarking.
 * You can chose the list sizes you want and the max value to use for the benchmark.
 * For benchmark selecting, just comment/uncomment the relevent maccros.
 */

#include <benchmark/benchmark.h>

#include "utils/linked_lists/linked_lists.hh"
#include "utils/linked_lists/linked_lists_algorithms.hh"
#include "utils/logger/logger.hh"
#include "utils/tools/generator.hh"
#include "exos/quicksort_mergesort/quick_sort.hh"
#include "exos/quicksort_mergesort/merge_sort.hh"

using namespace Generator;

constexpr size_t SIZE = 10'000;
constexpr size_t MAX_VAL = 1'000'000;
 

// Tested list cases 

#define RANDOM_LISTS
#define SORTED_LISTS
#define REVERSED_LISTS


// Tested data structures

#define LINKED_LISTS
#define VECTORS


// Tested sorting algorithm

#define QUICK_SORT
#define MERGE_SORT