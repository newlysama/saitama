#include "linked_lists.hh"
#include "linked_lists_algorithms.hh"

using namespace Checker;

void LinkedListAlgorithm::merge(LinkedList& left, LinkedList& right) {
    if (left.empty()) {
        left = std::move(right);
    } else if (right.empty()) {
        return;
    }

    Node* current = left.first;

    while (!right.empty() && current != nullptr) {
        if (current->value > right.first->value) {
            auto first = right.pop_front();

            // Special case: insert at head
            if (current == left.first) {
                left.push_front(first);
                current = left.first->next;
            } else {
                first->prev = current->prev;
                first->next = current;
                current->prev->next = first;
                current->prev = first;
                left.size++;
            }
        } else {
            current = current->next;
        }
    }

    // Append remaining elements from right to the end of left
    while (!right.empty()) {
        auto node = right.pop_front();
        left.push_back(node);
    }

    // Empty right (not needed in theroy, but we never know)
    right.clear();
}
