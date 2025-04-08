#include "linked_lists.hh"

using namespace Checker;

bool LinkedList::empty() noexcept {
    return this->first == nullptr;
}

void LinkedList::print() {
    if (this->empty()) {
        std::cout << "[ ]\n";
        return;
    }

    std::ostringstream oss;
    oss << "[ ";

    for (Node* current = this->first; current != nullptr; current = current->next) {
        oss << current->value;
        if (current->next != nullptr) oss << ", ";
    }

    oss << " ]\n";
    std::cout << oss.str();
}

Node *LinkedList::get(std::size_t index) {
    if (this->empty()) {
        throw std::invalid_argument("LinkedList::get() : cannot get() on empty list.");
    }

    // Index checking
    check_index("LinkedList::get()", index, this->size);
    if (index == 0) return this->first;

    // If index if after the middle of the list, browse backward
    bool from_front = index <= this->size / 2;
    Node* current = from_front ? this->first : this->last;
    size_t i = from_front ? 0 : this->size - 1;
    
    while (i != index) {
        check_access_nullptr(current, "LinkedList::get()", i);
        current = from_front ? current->next : current->prev;
        from_front ? ++i : --i;
    }

    check_access_nullptr(current, "LinkedList::get()", i);
    return current;
}

void LinkedList::clear() {
    this->first = nullptr;
    this->last = nullptr;
    this->size = 0;
}

Node* Node::create(std::pmr::memory_resource* resource, size_t value) noexcept {
    std::pmr::polymorphic_allocator<Node> alloc(resource);
    Node* node = alloc.allocate(1);
    new (node) Node(value);  // Placement new

    return node;
}