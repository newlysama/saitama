#pragma once

#include <gtest/gtest.h>
#include "utils/vector_utils/vector_utils.hh"
#include "exos/quicksort_mergesort/pivot.hh"

/**
 * @brief Select which test you want to launch
 *        Simply comment/uncomment the maccros 
 */

#define SPLIT
#define MERGE
#define PARTITION_LOMUTO
#define PARTITION_HOARE