#include "linked_lists.hh"

void LinkedList::swap_values(size_t i, size_t j) {
    if (i >= this->size || j >= this->size) {
        std::ostringstream oss;
        oss << "LinkedList::swap_values() : required index is out of bounds.\n";
        oss << "i : " << i << " <==> " << "j : " << j;
        throw std::invalid_argument(oss.str());
    } else if (i == j) return;

    // So we don't have to check and build 2 loops...
    if (i > j) { std::swap(i, j); }

    // Don't use this->get() here since we want don't want to go through our list twice
    std::size_t index = 0;
    Node *current = this->first.get();

    while (index < i) {
        check_access_nullptr(current, "LinkedList::swap_values()", index);

        current = current->next.get();
        index++;
    }

    // Save first element we want to swap
    Node* tmp = current;

    while (index < j) {
        check_access_nullptr(current, "LinkedList::swap_values()", index);

        current = current->next.get();
        index++;     
    }

    std::swap(tmp->value, current->value);
}