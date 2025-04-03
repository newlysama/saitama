#pragma once

#include <vector>
#include <sstream>
#include <cuchar>
#include <exception>
#include <numeric>

/**
 * @brief Class implementing various vector algorithms
 */
class VectorUtils {
    public:
        /**
         * @brief Split a vector in two equal (if even length of course) parts
         * @param list the vector we want to split
         * @return tuple containing the 2 resulting vectors
         */
        static std::tuple<std::vector<std::size_t>, std::vector<std::size_t>> split(std::vector<std::size_t> list);

        /**
         * @brief Merge two sorted vectors into one.
         * @param list1 the first sorted vector
         * @param list2 the second sorted vector
         * @return the resulting vector
         */
        static std::vector<std::size_t> merge(std::vector<std::size_t> list1, std::vector<std::size_t> list2);

        /**
         * @brief Lomuto's partition scheme applied to vectors
         * @param list the list to partition
         * @param low low bound for the algorithm to perform
         * @param high high bound
         * @return the new pivot index
         */
        static size_t partition_lomuto(std::vector<size_t>& list, size_t low, size_t high);

        /**
         * @brief Hoare's partition scheme applied to vectors
         * @param list the list to partition
         * @param low low bound for the algorithm to perform
         * @param high high bound
         * @return the new pivot index
         */
        static size_t partition_hoare(std::vector<size_t>& list, size_t low, size_t high);
};