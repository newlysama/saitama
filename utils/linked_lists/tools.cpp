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
        throw std::invalid_argument("LinkedList::get() : cannot get on empty list.");
    }

    if (index == 0) return this->first.get();

    else if (index >= this->size) {
        std::ostringstream oss;
        oss << "LinkedList::get() : required index is out of bounds : " << index;
        throw std::invalid_argument(oss.str());
    }

    Node *current;

    // If i is after middle of the list, browse from the back
    if (index <= this->size / 2) {
        size_t i = 0;
        current = this->first.get();

        while (i < index) {
            if (!current) {
                std::ostringstream oss;
                oss << "LinkedList::get() : trying to access nullptr at index " << i;
                throw std::logic_error(oss.str());
            }
    
            current = current->next.get();
            i++;
        }
    } else {
        size_t i = this->size - 1;
        current = this->last;

        while (i > index) {
            if (!current) {
                std::ostringstream oss;
                oss << "LinkedList::get() : trying to access nullptr at index " << i;
                throw std::logic_error(oss.str());
            }
    
            current = current->prev;
            i--;
        }
    }

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