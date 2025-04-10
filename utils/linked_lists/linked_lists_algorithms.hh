#pragma once

#include "linked_lists.hh"

/**
 * @brief Namespace implemeting various list algorithms applied to our linked lists
 */
namespace LinkedListAlgorithm {

        /**
         * @brief Split a list in 2
         * @see split.impl.hpp
         * @param list the list we want to split
         * @param split_index Optional index to split the list at. If not provided, the list is split in half
         * @return a tuple of the 2 resulting lists
         * @todo implement backward split, impoving performance when index > list->size / 2
         */
        template <typename ArenaType>
        std::tuple<LinkedList<ArenaType>, LinkedList<ArenaType>>
        split(LinkedList<ArenaType>& list, std::optional<size_t> split_index = std::nullopt);

        /**
         * @brief Split the list around pivot_index in 3 parts
         * @details constructs 3 lists (left side of the pivot, the pivot itself (list of 1 element) and right side of the pivot)
         *          so we can concat the pivot after (used in quicksort)
         * @see split.impl.hpp
         * @param list the list we want to split
         * @param pivot_index the required pivot index
         * @return a tuple of the 3 resulting lists
         * @todo implement backward split, impoving performance when pivot_index > list->size / 2
         */
        template <typename ArenaType>
        std::tuple<LinkedList<ArenaType>, LinkedList<ArenaType>, LinkedList<ArenaType>>
        split_around_pivot(LinkedList<ArenaType>& list, size_t pivot_index);

        /**
         * @brief Merge right list into left, keeping the result sorted
         * @see merge.impl.hpp
         * @param left the first sorted list
         * @param right the second sorted list
         */
        template <typename ArenaType>
        void merge(LinkedList<ArenaType>& left, LinkedList<ArenaType>& right);

        /**
         * @brief Concat two linked lists in-place
         * @see concat.impl.hpp
         * @param left list that will 'receive' the other
         * @param right list to concat to left
         */
        template <typename ArenaType>
        void concat(LinkedList<ArenaType>& left, LinkedList<ArenaType>& right);

        /**
         * @brief Lomuto's partition scheme applied to linked lists
         * @see partition.impl.hpp
         * @return the new pivot index
         */
        template <typename ArenaType>
        size_t partition_hoare(LinkedList<ArenaType>& list);

        /**
         * @brief Hoare's partition scheme applied to linked lists
         * @see partition.impl.hpp
         * @return the new pivot index
         */
        template <typename ArenaType>
        size_t partition_lomuto(LinkedList<ArenaType>& list);
}

#include "concat.impl.hpp"
#include "merge.impl.hpp"
#include "partition.impl.hpp"
#include "split.impl.hpp"