#include "linked_lists.hh"

std::unique_ptr<Node> LinkedList::pop_front() {
    if (this->empty()) {
        throw std::invalid_argument("LinkedList::pop_front() : cannot pop on empty list.");
    }

    auto res = std::move(this->first);

    this->first = std::move(res->next);
    res->next = nullptr;

    this->size--;

    if (this->empty()) {
        this->last = nullptr;
    } else {
        this->first->prev = nullptr;
    }

    return res;
}

std::unique_ptr<Node> LinkedList::pop_back() {
    std::unique_ptr<Node> res;

    if (this->empty()) {
        throw std::invalid_argument("LinkedList::pop_back() : cannot pop on empty list.");
    } else if (this->last == nullptr) {
        throw std::logic_error("LinkedList::pop_back() : trying to pop nullptr.");
    }

    else if (this->size == 1) {
        res = std::move(this->first);
        this->size--;
        this->last = nullptr;

        return res;
    }

    res = std::make_unique<Node>(this->last);

    check_access_nullptr(res->prev, "pop_back()");

    this->last = res->prev;
    res->prev->next = nullptr;
    res->prev = nullptr;
    this->size--;

    return res;
}