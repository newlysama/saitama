#include "linked_lists.hh"
#include "linked_lists_algorithms.hh"

void LinkedListAlgorithm::merge(LinkedList& left, LinkedList& right) {
    if (left.empty()) {
        left.first = std::move(right.first);
        left.last = right.last;
        left.size = right.size;
        return;
    } else if (right.empty()) {
        return;
    }

    Node* current = left.first.get();

    while (!right.empty() && current != nullptr) {
        if (current->value > right.first->value) {
            auto first = right.pop_front();

            // Special case: insert at head
            if (current == left.first.get()) {
                left.push_front(std::move(first));
                current = left.first.get()->next.get();
            } else {
                first->prev = current->prev;
                first->next = std::move(current->prev->next);
                current->prev->next = std::move(first);
                current->prev = current->prev->next.get();
                ++left.size;
            }
        } else {
            current = current->next.get();
        }
    }

    // Append remaining elements from right to the end of left
    while (!right.empty()) {
        auto node = right.pop_front();
        left.push_back(std::move(node));
    }
}
