#include "linked_lists.hh"
#include "linked_lists_algorithms.hh"

using namespace Checker;

void LinkedListAlgorithm::concat(LinkedList& left, LinkedList& right) {
    // Doesn't check if both are empty, since it doesn't change anything
    if (left.empty()) {
        left = std::move(right);
        return;
    } else if (right.empty()) {
        return;
    }

    // Assert that left.last is not nullptr, since we'll need to access its ->next
    check_access_nullptr(left.last, "LinkedListAlgorithm::concat()");

    // Plug left and right
    right.first->prev = left.last;
    left.last->next = right.first;

    // Set new last
    left.last = right.last;

    left.size += right.size;

    right.clear();
}