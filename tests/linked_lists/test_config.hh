#pragma once

#include <gtest/gtest.h>
#include "tests/test_utils.hh" 
#include "utils/linked_lists/linked_lists.hh"
#include "utils/linked_lists/linked_lists_algorithms.hh"
#include "utils/memory_manager/memory_manager.hh"
#include "exos/quicksort_mergesort/pivot.hh"

/**
 * @brief Select which test you want to launch
 *        Simply comment/uncomment the maccros 
 */

#define INIT
#define GET
#define SWAP
#define PUSH
#define POP

#define SPLIT
#define SPLIT_AROUND_PIVOT
#define MERGE
#define CONCAT
#define PARTITION_LOMUTO
#define PARTITION_HOARE