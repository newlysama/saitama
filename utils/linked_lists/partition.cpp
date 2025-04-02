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

size_t LinkedListAlgorithm::partition_lomuto(std::unique_ptr<LinkedList>& list, size_t low, size_t high) {
    if (low >= high || high >= list->size) {
        std::ostringstream oss;
        oss << "LinkedList::partition_lomuto() : invalid indices.";
        oss << "Got low : " << low << " || " << "high : " << high;
        throw std::invalid_argument(oss.str());
    }

    // Get the pivot and swap it's place with list[high]
    // since lomuto's partition works with pivot at high place
    auto pivot_index = chose_pivot(low, high);
    auto pivot_node = list->get(pivot_index);
    auto high_node = list->get(high);
    
    std::swap(pivot_node->value, high_node->value);
    
    size_t pivot_value = high_node->value; 

    size_t i = low;
    size_t j;

    // Defined those and use them as we browse the list,
    // so that we don't have to make infinite gets for value checking and node swaping
    auto node_i = list->get(low);
    auto node_j = node_i;

    for (j = low; j < high; ++j) {
        if (node_j->value < pivot_value) {
            check_access_nullptr(node_i, "LinkedList::partition_lomuto()", i);
            std::swap(node_i->value, node_j->value);

            node_i = node_i->next.get();
            ++i;
        }

        check_access_nullptr(node_j, "LinkedList::partition_lomuto()", j);
        node_j = node_j->next.get();
    }

    check_access_nullptr(node_i, "LinkedList::partition_lomuto()", i);
    check_access_nullptr(node_j, "LinkedList::partition_lomuto()", j);

    std::swap(node_i->value, node_j->value);
    return i;
}


size_t LinkedListAlgorithm::partition_hoare(std::unique_ptr<LinkedList>& list, size_t low, size_t high) {
    if (low >= high || high >= list->size) {
        std::ostringstream oss;
        oss << "LinkedList::partition_hoare() : invalid indices.";
        oss << "Got low : " << low << " || high : " << high;
        throw std::invalid_argument(oss.str());
    }

    // Swap chosen pivot value into low position
    auto pivot_index = chose_pivot(low, high);
    auto pivot_node = list->get(pivot_index);
    auto low_node = list->get(low);
    
    std::swap(pivot_node->value, low_node->value);

    size_t pivot_value = low_node->value; 

    // Defined those and use them as we browse the list,
    // so that we don't have to make infinite gets for value checking and node swaping
    auto node_i = list->get(low);
    auto node_j = list->get(high);

    while (true) {
        while (node_i->value < pivot_value) {
            check_access_nullptr(node_i, "LinkedList::partition_hoare()", low);
            node_i = node_i->next.get();
            ++low;
        }

        while (node_j->value > pivot_value) {
            check_access_nullptr(node_j, "LinkedList::partition_hoare()", high);
            node_j = node_j->prev;
            --high;
        }

        if (low >= high) return high;

        check_access_nullptr(node_i, "LinkedList::partition_hoare()", low);
        check_access_nullptr(node_j, "LinkedList::partition_hoare()", high);

        std::swap(node_i->value, node_j->value);

        node_i = node_i->next.get();
        node_j = node_j->prev;
        ++low;
        --high;
    }
}
