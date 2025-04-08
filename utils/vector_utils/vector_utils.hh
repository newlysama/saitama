#pragma once

#include <vector>
#include <sstream>
#include <cuchar>
#include <exception>
#include <numeric>
#include <iostream>
#include <tuple>

#include "utils/memory_manager/memory_manager.hh"

/**
* @brief Namespace implementing various vector algorithms
*/
namespace VectorUtils {
    /**
    * @brief Print a vector
    * @see tools.cpp
    * @param vector the vector to print
    */
    void print(std::pmr::vector<size_t> vector);
    
    /**
    * @brief Split a vector in two equal (if even length of course) parts
    * @see split.cpp
    * @param vector the vector we want to split
    * @return tuple containing the 2 resulting vectors
    */
    std::tuple<std::pmr::vector<size_t>, std::pmr::vector<size_t>> split(std::pmr::vector<size_t> vector);
    
    /**
    * @brief Merge two sorted vectors into one.
    * @see merge.cpp
    * @details Can't make this one in-place, since it would require to use std::vector::insert(), which is O(n) complexity
    * @param left the first sorted vector
    * @param right the second sorted vector
    * @return the resulting vector
    */
    std::pmr::vector<size_t> merge(std::pmr::vector<size_t> left, std::pmr::vector<size_t> right);
    
    /**
    * @brief Lomuto's partition scheme applied to vectors
    * @see partition.cpp
    * @param vector the vector to partition
    * @param low low bound for the algorithm to perform
    * @param high high bound
    * @return the new pivot index
    */
    size_t partition_lomuto(std::pmr::vector<size_t>& vector, size_t low, size_t high);
    
    /**
    * @brief Hoare's partition scheme applied to vectors
    * @see partition.cpp
    * @param vector the vector to partition
    * @param low low bound for the algorithm to perform
    * @param high high bound
    * @return the new pivot index
    */
    size_t partition_hoare(std::pmr::vector<size_t>& vector, size_t low, size_t high);
};