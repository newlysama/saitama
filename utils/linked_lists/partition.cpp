#include <random>

#include "linked_lists.hh"

// Chose which pivot strategy to use, maccros are defined in exo/quicksort_mergesort/pivot.hh
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

size_t LinkedList::partition_lomuto(size_t low, size_t high) {
    if (low >= high || high >= this->size) {
        std::ostringstream oss;
        oss << "LinkedList::partition_lomuto() : invalid indices.";
        oss << "Got low : " << low << " || " << "high : " << high;
        throw std::invalid_argument(oss.str());
    }

    // Get the pivot and swap it's place with high element
    // since lomuto's partition works with pivot at high place
    auto pivot_index = chose_pivot(low, high);
    auto pivot_node = this->get(pivot_index);
    auto high_node = this->get(high);
    
    std::swap(pivot_node->value, high_node->value);
    
    size_t pivot_value = high_node->value; 

    size_t i = low;
    size_t j;

    // Defined those and use them as we browse the list, so that we don't have to make infinite gets
    // for value checking and node swaping
    auto node_i = this->get(low);
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

size_t LinkedList::partition_hoare(size_t low, size_t high) {
    if (low >= high || high >= this->size) {
        std::ostringstream oss;
        oss << "LinkedList::partition_hoare() : invalid indices.";
        oss << "Got low : " << low << " || high : " << high;
        throw std::invalid_argument(oss.str());
    }

    // Swap chosen pivot value into low position
    auto pivot_index = chose_pivot(low, high);
    auto pivot_node = this->get(pivot_index);
    auto low_node = this->get(low);
    
    std::swap(pivot_node->value, low_node->value);

    size_t pivot_value = low_node->value; 

    auto node_i = this->get(low);
    auto node_j = this->get(high);

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
