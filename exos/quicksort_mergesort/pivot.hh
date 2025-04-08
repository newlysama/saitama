#pragma once

/**
 * @brief Chose which pivot strategy to use for quicksort
 * 
 */

 #define RANDOM 1
 #define FIRST  2
 #define LAST   3
 #define MID    4
 
#ifndef PIVOT
#define PIVOT MID
#endif