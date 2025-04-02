#include "linked_lists.hh"
#include "linked_lists_algorithms.hh"

void LinkedListAlgorithm::concat(std::unique_ptr<LinkedList>& left, std::unique_ptr<LinkedList>& right) {
    // Doesn't check if both are empty, since it doesn't change anyithing
    if (left->empty()) {
        left = std::move(right);
        return;
    } else if (right->empty()) {
        return;
    }

    // Assert that left->last is not nullptr, since we'll need to access its ->next
    check_access_nullptr(left->last, "concat()");

    right->first->prev = left->last;
    left->last->next = std::move(right->first);
    left->last = right->last;
    left->size += right->size;
}