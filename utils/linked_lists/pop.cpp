#include "linked_lists.hh"

std::unique_ptr<Node> LinkedList::pop_front() {
    if (this->empty()) {
        throw std::invalid_argument("Cannot pop_front() on empty list.");
    }

    std::unique_ptr<Node> res = std::move(this->first);
    this->first = std::move(res->next);
    res->next = nullptr;

    this->size--;

    if (this->empty()) {
        this->last = nullptr;
    }

    // Return the poped node, since we'll need it later
    return res;
}

std::unique_ptr<Node> LinkedList::pop_back() {
    std::unique_ptr<Node> res;

    if (this->empty()) {
        throw std::invalid_argument("Cannot pop_back() on empty list.");
    } else if (this->size == 1) {
        res = std::move(this->first);
        this->size--;
        this->last = nullptr;
        return res;
    }

    Node *current = this->first.get();
    while (current->next->next != nullptr) {
        current = current->next.get();
    }

    this->last = current;
    res = std::move(current->next);
    this->size--;

    return res;
}