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

#define QUICK_SORT_LOMUTO_LINKED_LISTS
#define QUICK_SORT_HOARE_LINKED_LISTS
#define QUICK_SORT_LOMUTO_VECTORS
#define QUICK_SORT_HOARE_VECTORS

#define MERGE_SORT_LINKED_LISTS
#define MERGE_SORT_VECTORS