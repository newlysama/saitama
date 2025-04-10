#pragma once

#include "linked_lists.hh"

template <typename ArenaType>
Node* LinkedList<ArenaType>::pop_front() {
    if (this->empty()) {
        throw std::invalid_argument("LinkedList::pop_front() : cannot pop on empty list.");
    }

    return pop_node(this->first);
}

template <typename ArenaType>
Node* LinkedList<ArenaType>::pop_back() {
    if (this->empty()) {
        throw std::invalid_argument("LinkedList::pop_back() : cannot pop on empty list.");
    }

    if (!this->last) {
        throw std::logic_error("LinkedList::pop_back() : last is nullptr.");
    }

    return pop_node(this->last);
}

template <typename ArenaType>
Node* LinkedList<ArenaType>::pop_node(Node* node) {
    // Update first/last if needed
    if (node == this->first) {
        this->first = node->next;
    }

    if (node == this->last) {
        this->last = node->prev;
    }

    // Rebind neighbors
    if (node->prev) {
        node->prev->next = node->next;
    }

    if (node->next) {
        node->next->prev = node->prev;
    }

    // Unlink the node
    node->next = nullptr;
    node->prev = nullptr;

    this->size--;

    if (this->empty()) {
        this->first = nullptr;
        this->last = nullptr;
    }

    return node;
}
