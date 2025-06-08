#pragma once

/**
 * @brief Implements our quick sort and merge sort algorithms benchmarking.
 * You can chose the list sizes you want and the max value to use for the benchmark.
 * For benchmark selecting, just comment/uncomment the relevent maccros.
 * You also can chose if you want to use the custom format output.
 * 
 *   [NOTE] :
 * 
 * When using the custom format output, the default unit for time is second, but not for
 * default output format. So if you want to use default and get second as unit, make sure
 * to run the benchmark with run-benchmark rule, as it forces the unit type to second.
 */

#include <benchmark/benchmark.h>

#include "utils/linked_lists/linked_lists.hh"
#include "utils/linked_lists/linked_lists_algorithms.hh"
#include "utils/logger/logger.hh"
#include "utils/generator/generator.hh"
#include "exos/quicksort_mergesort/quick_sort.hh"
#include "exos/quicksort_mergesort/merge_sort.hh"

using ScalableVector = std::vector<size_t, tbb::scalable_allocator<size_t>>;

constexpr size_t SIZE = 2'000'000;
constexpr size_t MAX_VAL = 1'000'000;

// Declare arena for our linked lists
extern std::shared_ptr<MemoryManager::FixedArena> arena;

// Declare vector
extern ScalableVector vector;

// Custom reporter
#define USE_CUSTOM_REPORTER

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