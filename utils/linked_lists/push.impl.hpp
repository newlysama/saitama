#pragma once

#include "linked_lists.hh"

using namespace Checker;

template <typename ArenaType>
void LinkedList<ArenaType>::push_front(size_t value) {
    // Custom allocation for new_node
    Node* new_node = Node::create(arena, value);
    insert_node_at_front(new_node);
}

template <typename ArenaType>
void LinkedList<ArenaType>::push_front(Node* new_node) {
    insert_node_at_front(new_node);
}

template <typename ArenaType>
void LinkedList<ArenaType>::push_back(size_t value) {
    // Custom allocation for new_node
    Node* new_node = Node::create(arena, value);
    this->insert_node_at_back(new_node);
}

template <typename ArenaType>
void LinkedList<ArenaType>::push_back(Node* new_node) {
    this->insert_node_at_back(new_node);
}

template <typename ArenaType>
void LinkedList<ArenaType>::insert_node_at_front(Node* new_node) {
    if (!new_node) {
        throw std::invalid_argument("LinkedList::push_front() : new_node is nullptr");
    }

    // Set new prev/next for new_node
    new_node->next = this->first;
    new_node->prev = nullptr;

    // If new_node->next != nullptr, we need to set new_node as prev
    if (new_node->next) {
        new_node->next->prev = new_node;
    }

    // Set new first
    this->first = new_node;

    // If list was empty at first, set new_node as last
    if (!this->last) {
        this->last = this->first;
    }

    this->size++;
}

template <typename ArenaType>
void LinkedList<ArenaType>::insert_node_at_back(Node* new_node) {
    if (!new_node) {
        throw std::invalid_argument("LinkedList::push_back() : new_node is nullptr");
    }

    // If list is empty, new_node is first and last
    if (this->empty()) {
        this->last = new_node;
        this->first = new_node;
        this->size++;

        return;
    }

    check_access_nullptr(this->last, "LinkedList::push_back()");

    // new_node's prev is old list's last
    new_node->prev = this->last;

    // Adding new_node as old last's next
    this->last->next = new_node;

    // Set new_node as new last
    this->last = new_node;

    this->size++;
}