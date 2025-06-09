#pragma once

#include <random>

#include "linked_lists.hh"
#include "linked_lists_algorithms.hh"
#include "exos/quicksort_mergesort/pivot.hh"

using namespace Checker;

/**
 * @brief Chose which pivot strategy to use, depending on the defined maccros in 'exos/quicksort_mergesort/pivot.hh'
 * @param low 
 * @param high 
 * @return size_t 
 */
inline size_t chose_pivot(size_t low, size_t high) {
    #if PIVOT == RANDOM
        return low + rand() % (high - low + 1);
    #elif PIVOT == FIRST
        (void)high;
        return low;
    #elif PIVOT == LAST
        (void)low;
        return high;
    #elif PIVOT == MID
        return (low + high) / 2;
    #else
        throw std::invalid_argument("Unknown pivot strategy for quicksort.");
    #endif
}

template <typename ArenaType>
size_t LinkedListAlgorithm::partition_lomuto(LinkedList<ArenaType>& list) {
    // Get the pivot and swap its place with list[high]
    // since lomuto's partition works with pivot at high place
    auto pivot_index = chose_pivot(0, list.size - 1);
    auto pivot_node = list.get(pivot_index);
    auto high_node = list.get(list.size - 1);
    std::swap(pivot_node->value, high_node->value);

    size_t pivot_value = high_node->value;

    size_t i = 0;
    size_t j;

    // Defined those and use them as we browse the list,
    // so that we don't have to make infinite gets for value checking and node swapping
    auto node_i = list.first;
    auto node_j = list.first;

    for (j = 0; j < list.size - 1; ++j) {
        check_access_nullptr(node_j, "LinkedListAlgorithm::partition_lomuto()", j);
    
        if (node_j->value < pivot_value) {
            check_access_nullptr(node_i, "LinkedListAlgorithm::partition_lomuto()", i);
            std::swap(node_i->value, node_j->value);
    
            node_i = node_i->next;
            ++i;
        }
    
        node_j = node_j->next;
    }

    check_access_nullptr(node_i, "LinkedListAlgorithm::partition_lomuto()", i);

    std::swap(node_i->value, node_j->value);
    return i;
}

template <typename ArenaType>
size_t LinkedListAlgorithm::partition_hoare(LinkedList<ArenaType>& list) {
    // Swap chosen pivot value into low position
    auto pivot_index = chose_pivot(0, list.size - 1);
    auto pivot_node = list.get(pivot_index);
    auto low_node = list.first;

    std::swap(pivot_node->value, low_node->value);
    size_t pivot_value = low_node->value;

    size_t i = 0;
    size_t j = list.size - 1;

    // Defined those and use them as we browse the list,
    // so that we don't have to make infinite gets for value checking and node swapping
    auto node_i = list.first;
    auto node_j = list.last;

    while (true) {
        // node_i/node_j can reach nullptr if pivot is min/max of list
        while (node_i && node_i->value < pivot_value) {
            node_i = node_i->next;
            i++;
        }

        while (node_j && node_j->value > pivot_value) {
            node_j = node_j->prev;
            j--;
        }

        if (i >= j) return j;

        check_access_nullptr(node_i, "LinkedListAlgorithm::partition_hoare()", i);
        check_access_nullptr(node_j, "LinkedListAlgorithm::partition_hoare()", j);

        std::swap(node_i->value, node_j->value);

        node_i = node_i->next;
        node_j = node_j->prev;
        i++;
        j--;
    }
}