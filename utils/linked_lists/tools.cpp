#include "linked_lists.hh"

bool LinkedList::empty() {
    return this->first == nullptr;
}

void LinkedList::print() {
    if (this->empty()) {
        std::cout << "[ ]\n";
        return;
    }

    // use .get() to iterate so that we don't tranfer ownership
    Node *current = this->first.get();
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
    if (this->empty()) {
        throw std::invalid_argument("get() : cannot get on empty list.");
    }

    check_index("get()", index, this->size);

    if (index == 0) return this->first.get();

    Node *current;
    size_t i;

    // If index is after middle of the list, browse from the back
    if (index <= this->size / 2) {
        i = 0;
        current = this->first.get();

        while (i < index) {
            check_access_nullptr(current, "get() forward", i);
    
            current = current->next.get();
            i++;
        }
    } else {
        i = this->size - 1;
        current = this->last;

        while (i > index) {
            check_access_nullptr(current, "get() backward", i);
    
            current = current->prev;
            i--;
        }
    }

    check_access_nullptr(current, "get()", i);
    return current;
}

void check_access_nullptr(Node* node, const std::string& function, std::optional<size_t> index) {
    if (node == nullptr) {
        std::ostringstream oss;
        oss << "LinkedList::" << function << " : trying to access nullptr";

        if (index.has_value()) {
            oss << " at index : " << index.value();
        } else {
            oss << ".";
        }
        
        throw std::logic_error(oss.str());
    }
}

void check_index(const std::string& function, size_t index, size_t list_size) {
    if (index >= list_size) {
        std::ostringstream oss;
        oss << "LinkedList::" << function << " : required index is out of bounds : " << index;
        throw std::invalid_argument(oss.str());
    }
}