#include "linked_lists.hh"

void LinkedList::push_front(size_t value) {
    std::unique_ptr<Node> new_node = std::make_unique<Node>(value, std::move(this->first), nullptr);
   
    if (this->empty()) {
        this->last = new_node.get();
    } else {
        this->first->prev = new_node.get();
    }

    this->first = std::move(new_node);
    this->size++;
}

void LinkedList::push_back(size_t value) {
    std::unique_ptr<Node> new_node = std::make_unique<Node>(value, nullptr, nullptr); 
    if (this->empty()) {
        this->last = new_node.get();
        this->first = std::move(new_node);
        this->size++;
        return;
    } 

    Node *tmp = new_node.get();
    new_node->prev = this->last;
    this->last->next = std::move(new_node);
    this->last = tmp;
    this->size++;
}

void LinkedList::push_back(std::unique_ptr<Node> new_node) {
    if (this->empty()) {
        this->last = new_node.get();
        this->first = std::move(new_node);
        this->size++;
        return;
    }

    Node *tmp = new_node.get();;
    new_node->prev = this->last;
    this->last->next = std::move(new_node);
    this->last = tmp;
    this->size++;
}