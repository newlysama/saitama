#include "linked_lists.hh"

void LinkedList::swap_values(size_t i, size_t j) {
    if (i >= this->size || j >= this->size) {
        throw std::invalid_argument("Swap() required index is out of bounds.");
    } else if (i == j) {
        return;
    }

    // So we don't have to check and build 2 loops...
    if (i > j) { std::swap(i, j); }

    // Don't use this->get() here since we want don't want to go through our list twice
    std::size_t index = 0;
    Node *current = this->first.get();
    while (index < i) {
        current = current->next.get();
        index++;
    }
    Node* tmp = current;

    while (index < j) {
        current = current->next.get();
        index++;     
    }

    // Only swap values since we don't care about the node itself here
    std::swap(tmp->value, current->value);
}