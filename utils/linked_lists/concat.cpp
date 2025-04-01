#include "linked_lists.hh"


void LinkedList::concat(std::unique_ptr<LinkedList>& left, std::unique_ptr<LinkedList>& right) {
    if (left->empty()) {
        left = std::move(right);
        return;
    } else if (right->empty()) {
        return;
    }

    check_access_nullptr(left->last, "concat()");

    right->first->prev = left->last;
    left->last->next = std::move(right->first);
    left->last = right->last;
    left->size += right->size;
}