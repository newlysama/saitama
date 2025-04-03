#include "linked_lists.hh"

void LinkedList::push_front(size_t value) {
    auto new_node = std::make_unique<Node>(value);

    new_node->next = std::move(this->first);
    if (new_node->next) {
        new_node->next->prev = new_node.get();
    }

    this->first = std::move(new_node);

    if (!this->last) {
        this->last = this->first.get();
    }

    this->size++;
}

void LinkedList::push_front(std::unique_ptr<Node> new_node) {
    if (!new_node) {
        throw std::invalid_argument("LinkedList::push_front() : new_node is nullptr");
    }

    new_node->next = std::move(this->first);

    if (new_node->next) {
        new_node->next->prev = new_node.get();
    }

    this->first = std::move(new_node);

    if (!this->last) {
        this->last = this->first.get();
    }

    ++this->size;
}

void LinkedList::push_back(size_t value) {
    auto new_node = std::make_unique<Node>(value);

    if (this->empty()) {
        this->last = new_node.get();
        this->first = std::move(new_node);
        this->size++;

        return;
    } 

    check_access_nullptr(this->last, "push_back(size_t)");

    auto tmp = new_node.get();

    new_node->prev = this->last;
    this->last->next = std::move(new_node);
    this->last = tmp;
    this->size++;
}

void LinkedList::push_back(std::unique_ptr<Node> new_node) {
    if (!new_node) {
        std::ostringstream oss;
        oss << "LinkedList::push_back(std::unique_ptr<Node>) : trying to push nullptr.";
        throw std::invalid_argument(oss.str());
    }

    if (this->empty()) {
        this->last = new_node.get();
        this->first = std::move(new_node);
        this->size++;

        return;
    }

    check_access_nullptr(this->last, "push_back(std::unique_ptr<Node>)");

    auto tmp = new_node.get();

    new_node->prev = this->last;
    this->last->next = std::move(new_node);
    this->last = tmp;
    this->size++;
}