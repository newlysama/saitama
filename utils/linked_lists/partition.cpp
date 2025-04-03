#include <random>

#include "linked_lists.hh"
#include "linked_lists_algorithms.hh"

/**
 * @brief Chose which pivot strategy to use, depending on the defined maccros in 'exos/quicksort_mergesort/pivot.hh'
 * @param low 
 * @param high 
 * @return size_t 
 */
size_t chose_pivot(size_t low, size_t high) {
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

size_t LinkedListAlgorithm::partition_lomuto(LinkedList& list) {
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
    auto node_i = list.first.get();
    auto node_j = list.first.get();

    for (j = 0; j < list.size - 1; ++j) {
        check_access_nullptr(node_j, "partition_lomuto()", j);

        if (node_j->value < pivot_value) {
            check_access_nullptr(node_i, "partition_lomuto()", i);
            std::swap(node_i->value, node_j->value);

            node_i = node_i->next.get();
            ++i;
        }

        check_access_nullptr(node_j, "partition_lomuto()", j);
        node_j = node_j->next.get();
    }

    check_access_nullptr(node_i, "partition_lomuto()", i);

    std::swap(node_i->value, node_j->value);
    return i;
}

size_t LinkedListAlgorithm::partition_hoare(LinkedList& list) {
    // Swap chosen pivot value into low position
    auto pivot_index = chose_pivot(0, list.size - 1);
    auto pivot_node = list.get(pivot_index);
    auto low_node = list.first.get();

    std::swap(pivot_node->value, low_node->value);
    size_t pivot_value = low_node->value;

    size_t i = 0;
    size_t j = list.size - 1;

    // Defined those and use them as we browse the list,
    // so that we don't have to make infinite gets for value checking and node swapping
    auto node_i = list.first.get();
    auto node_j = list.last;

    while (true) {
        // add node_i and node_j checks because if they are holding the greatest value of the list
        // they will end up being nullptr's, resulting in a crash
        while (node_i && node_i->value < pivot_value) {
            node_i = node_i->next.get();
            i++;
        }

        while (node_j && node_j->value > pivot_value) {
            node_j = node_j->prev;
            j--;
        }

        if (i >= j) return j;

        check_access_nullptr(node_i, "partition_hoare()", i);
        check_access_nullptr(node_j, "partition_hoare()", j);

        std::swap(node_i->value, node_j->value);

        node_i = node_i->next.get();
        node_j = node_j->prev;
        i++;
        j--;
    }
}