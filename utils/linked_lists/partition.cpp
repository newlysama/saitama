#include <random>

#include "linked_lists.hh"

size_t LinkedList::partition_lomuto(size_t low, size_t high) {
    if (low >= high || high >= this->size) {
        std::ostringstream oss;
        oss << "LinkedList::partition_lomuto() : invalid indices.";
        oss << "Got low : " << low << " || " << "high : " << high;
        throw std::invalid_argument(oss.str());
    }

    // Chose 1st/last element as pivot since we work with linked lists
    // Using mid/random element would be more stable, but leff efficient since this->get(index) has O(n) complexity
    size_t pivot_value = this->get(high)->value;
    size_t i = low;

    for (size_t j = low; j < high; ++j) {
        if (this->get(j)->value < pivot_value) {
            this->swap_values(i, j);
            ++i;
        }
    }

    this->swap_values(i, high);
    return i;
}

size_t LinkedList::partition_hoare(size_t low, size_t high) {
    if (low >= high || high >= this->size) {
        std::ostringstream oss;
        oss << "LinkedList::partition_hoare() : invalid indices.";
        oss << "Got low : " << low << " || " << "high : " << high;
        throw std::invalid_argument(oss.str());
    }

    size_t pivot_value = this->get(low)->value;

    // Convert to singed long so that if low = 0, low - 1 won't be max positive long
    std::ptrdiff_t i = static_cast<std::ptrdiff_t>(low) - 1;
    std::ptrdiff_t j = static_cast<std::ptrdiff_t>(high) + 1;

    while (true) {
        do { ++i; } while (this->get(i)->value < pivot_value);

        do { --j; } while (this->get(j)->value > pivot_value);

        if (i >= j) return j;

        this->swap_values(i, j);
    }
}