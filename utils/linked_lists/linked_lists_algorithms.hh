#include "linked_lists.hh"

/**
 * @brief Class implemeting various list algorithm, applied to our linked lists
 * @details Theese implementations are all in-place, we don't need to use unique pointers
 *          of LinkedList since that as soon as we move list->first, list is deleted.
 */
namespace LinkedListAlgorithm {

        /**
         * @brief Split a list in 2
         * @see split.cpp
         * @param list the list we want to split
         * @param split_index Optional index to split the list at. If not provided, the list is split in half
         * @return a tuple of the 2 resulting lists
         * @todo implement backward split, impoving performance when index > list->size / 2
         */
        std::tuple<LinkedList, LinkedList> split(LinkedList& list, std::optional<size_t> split_index = std::nullopt);

        /**
         * @brief Split the list around pivot_index in 3 parts
         * @details constructs 3 lists (left side of the pivot, the pivot itself (list of 1 element) and right side of the pivot)
         *          so we can concat the pivot after (used in quicksort)
         * @see split.cpp
         * @param list the list we want to split
         * @param pivot_index the required pivot index
         * @return a tuple of the 3 resulting lists
         * @todo implement backward split, impoving performance when pivot_index > list->size / 2
         */
        std::tuple<LinkedList, LinkedList, LinkedList> split_around_pivot(LinkedList& list, size_t pivot_index);

        /**
         * @brief Merge right list into left, keeping the result sorted
         * @see merge.cpp
         * @param left the first sorted list
         * @param right the second sorted list
         */
        void merge(LinkedList& left, LinkedList& right);

        /**
         * @brief Concat two linked lists in-place
         * @see concat.cpp
         * @param left list that will 'receive' the other
         * @param right list to concat to left (is deleted)
         */
        void concat(LinkedList& left, LinkedList& right);

        /**
         * @brief Lomuto's partition scheme applied to linked lists
         * @see partition.cpp
         * @return the new pivot index
         */
        size_t partition_hoare(LinkedList& list);

        /**
         * @brief Hoare's partition scheme applied to linked lists
         * @see partition.cpp
         * @return the new pivot index
         */
        size_t partition_lomuto(LinkedList& list);
}