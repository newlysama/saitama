#pragma once

#include <gtest/gtest.h>
#include "tests/test_utils.hh"
#include "utils/linked_lists/linked_lists.hh"
#include "utils/memory_manager/memory_manager.hh"
#include "exos/quicksort_mergesort/merge_sort.hh"
#include "exos/quicksort_mergesort/quick_sort.hh"

/**
 * @brief Select which test you want to launch
 *        Simply comment/uncomment the maccros 
 */

// Structures
#define LINKED_LISTS
#define VECTORS

// Algorithm
#define QUICKSORT_LOMUTO
#define QUICKSORT_HOARE
#define MERGESORT