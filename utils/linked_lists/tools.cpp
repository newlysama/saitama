#include "linked_lists.hh"

bool LinkedList::empty() {
    return this->first == nullptr;
}

void LinkedList::print() {
    if (this->empty()) {
        std::cout << "[ ]\n";
        return;
    }

    Node *current = this->first.get(); // use .get() to iterate so that we don't tranfer ownership
    std::ostringstream oss;

    oss << "[ ";
    while (current->next != nullptr) {
        oss << current->value << ", ";
        current = current->next.get();
    }

    oss << current->value << " ]\n";

    std::cout << oss.str();
}

Node *LinkedList::get(std::size_t index) {
    if (index == 0) {
        return this->first.get();
    } else if (index >= this->size) {
       throw std::invalid_argument("Get() required index is out of bounds.");
    }

    Node *current = this->first.get();
    size_t i = 0;
    while (i < index) {
        current = current->next.get();
        i++;
    }

    return current;
}