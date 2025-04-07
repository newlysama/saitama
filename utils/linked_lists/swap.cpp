#include "linked_lists.hh"

using namespace Checker;

/**
 * @brief Short function to check our swap indexes
 */
static void check_2_indexes(size_t size, size_t i, size_t j) {
    if (i >= size || j >= size) {
        std::ostringstream oss;
        oss << "LinkedList::swap_values() : required index is out of bounds.\n";
        oss << "i : " << i << " <==> " << "j : " << j;
        throw std::invalid_argument(oss.str());
    }
}

void LinkedList::swap_values(size_t i, size_t j) {
    // Check indexes
    check_2_indexes(this->size, i, j);
    if (i == j) return;

    // So we don't have to check and build 2 loops
    if (i > j) { std::swap(i, j); }

    // Don't use this.get() here since we want don't want to go through our list twice
    // So browse the list and store the two elements to swap
    std::size_t index = 0;
    Node *current = this->first;

    while (index < i) {
        check_access_nullptr(current, "LinkedList::swap_values()", index);

        current = current->next;
        index++;
    }

    // Save first element we want to swap
    Node* tmp = current;

    while (index < j) {
        check_access_nullptr(current, "LinkedList::swap_values()", index);

        current = current->next;
        index++;     
    }

    std::swap(tmp->value, current->value);
}