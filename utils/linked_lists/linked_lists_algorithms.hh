#include "linked_lists.hh"

namespace LinkedListAlgorithm {

        /**
         * @brief Split a list in 2
         * @details Use unique ptrs here since we want to delete list after split
         * @see split.cpp
         * @param list the list we want to split
         * @param split_index Optional index to split the list at. If not provided, the list is split in half
         * @return a tuple of the 2 resulting lists
         * @todo implement backward split, impoving performance when index > list->size / 2
         */
        std::tuple<std::unique_ptr<LinkedList>, std::unique_ptr<LinkedList>>
        split(std::unique_ptr<LinkedList> list, std::optional<size_t> split_index = std::nullopt);

        /**
         * @brief Split the list around pivot_index in 3 parts
         * @details Use unique ptrs here since we want to delete list after split
         * @see split.cpp
         * @details constructs 3 lists (left side of the pivot, the pivot itself (list of 1 element) and right side of the pivot)
         *          so we can concat the pivot after (used in quicksort)
         * @param list the list we want to split
         * @param pivot_index the required pivot index
         * @return a tuple of the 3 resulting lists
         * @todo implement backward split, impoving performance when pivot_index > list->size / 2
         */
        std::tuple<std::unique_ptr<LinkedList>, std::unique_ptr<LinkedList>, std::unique_ptr<LinkedList>>
        split_around_pivot(std::unique_ptr<LinkedList> list, size_t pivot_index);

        /**
         * @brief Merge two sorted lists into one, keeping the result sorted
         * @details Use unique ptrs here since we want to delete left and right after merge
         * @see merge.cpp
         * @param left the first sorted list
         * @param right the second sorted list
         * @return the resulting merged sorted list
         * @todo Implement in-place merge, with left as reference and returning void 
         */
        std::unique_ptr<LinkedList> merge(std::unique_ptr<LinkedList> left, std::unique_ptr<LinkedList> right);

        /**
         * @brief Concat two linked lists in-place
         * @details Use unique ptr right here since we want to delete it after concat
         * @see concat.cpp
         * @param left list that will 'receive' the other
         * @param right list to concat
         */
        void concat(LinkedList& left, std::unique_ptr<LinkedList> right);

        /**
         * @brief Lomuto's partition scheme applied to linked lists
         * @see partition.cpp
         * @param low lower boundary index to apply algorithm
         * @param high higher boundary index to apply algorithm
         * @return the new pivot index
         */
        size_t partition_hoare(LinkedList& list, size_t low, size_t high);

        /**
         * @brief Hoare's partition scheme applied to linked lists
         * @see partition.cpp
         * @param low lower boundary index to apply algorithm
         * @param high higher boundary index to apply algorithm
         * @return the new pivot index
         */
        size_t partition_lomuto(LinkedList& list, size_t low, size_t high);
}