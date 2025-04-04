#pragma once

#include <vector>
#include <sstream>
#include <cuchar>
#include <exception>
#include <numeric>
#include <iostream>
#include <tuple>

/**
* @brief Namespace implementing various vector algorithms
*/
namespace VectorUtils {
    /**
    * @brief Print a vector
    * @see tools.cpp
    * @param vector the vector to print
    */
    void print(std::vector<size_t> vector);
    
    /**
    * @brief Split a vector in two equal (if even length of course) parts
    * @see split.cpp
    * @param vector the vector we want to split
    * @return tuple containing the 2 resulting vectors
    */
    std::tuple<std::vector<std::size_t>, std::vector<std::size_t>> split(std::vector<std::size_t> vector);
    
    /**
    * @brief Merge two sorted vectors into one.
    * @see merge.cpp
    * @param left the first sorted vector
    * @param right the second sorted vector
    * @return the resulting vector
    */
    std::vector<std::size_t> merge(std::vector<std::size_t> left, std::vector<std::size_t> right);
    
    /**
    * @brief Lomuto's partition scheme applied to vectors
    * @see partition.cpp
    * @param vector the vector to partition
    * @param low low bound for the algorithm to perform
    * @param high high bound
    * @return the new pivot index
    */
    size_t partition_lomuto(std::vector<size_t>& vector, size_t low, size_t high);
    
    /**
    * @brief Hoare's partition scheme applied to vectors
    * @see partition.cpp
    * @param vector the vector to partition
    * @param low low bound for the algorithm to perform
    * @param high high bound
    * @return the new pivot index
    */
    size_t partition_hoare(std::vector<size_t>& vector, size_t low, size_t high);
};