#include "linked_lists.hh"

void LinkedList::push_front(size_t value) {
    bool is_empty = this->empty();
    std::unique_ptr<Node> new_node = std::make_unique<Node>(value, std::move(this->first));
   
    if (is_empty) {
        this->last = new_node.get();
    }

    this->first = std::move(new_node);
    this->size++;
}

void LinkedList::push_back(size_t value) {
    std::unique_ptr<Node> new_node = std::make_unique<Node>(value, nullptr); 
    
    if (this->empty()) {
        this->last = new_node.get();
        this->first = std::move(new_node);
        this->size++;
        return;
    }

    Node *current = this->first.get();
    while (current->next != nullptr) {
        current = current->next.get();
    }

    this->last = new_node.get();
    current->next = std::move(new_node);
    this->size++;
}

void LinkedList::push_back(std::unique_ptr<Node> new_node) {
    if (this->empty()) {
        this->first = std::move(new_node);
        this->size++;
        return;
    }

    Node *current = this->first.get();
    while (current->next != nullptr) {
        current = current->next.get();
    }

    this->last = new_node.get();
    current->next = std::move(new_node);
    this->size++;
}