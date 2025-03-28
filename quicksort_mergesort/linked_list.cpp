#include "linked_list.hh"

Node::Node(size_t _value, std::unique_ptr<Node> _next)
    : value(_value)
    , next(std::move(_next))
    {}

LinkedList::LinkedList()
    : first(nullptr)
    , size(0)
    {}

LinkedList::LinkedList(std::vector<size_t> list)
    : first(nullptr)
    , size(0)
    {
        for (auto elt : list) {
            this->push_back(elt);
        }    
    }

bool LinkedList::empty() {
    return this->first == nullptr;
}

void LinkedList::print() {
    if (this->empty()) {
        std::cout << "Empty list.\n";
        return;
    }

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

void LinkedList::push_front(size_t value) {
    std::unique_ptr<Node> new_node;

    try {
        new_node = std::make_unique<Node>(value, std::move(this->first));
    } catch (std::exception &e) {
        std::ostringstream oss;
        oss << "Exception raised in LinkedList::push_front() during new_node creation : " << e.what() << "\n";
        Logger::error(oss.str());

        return;
    }
   
    try {
        this->first = std::move(new_node);
    } catch (std::exception &e) {
        std::ostringstream oss;
        oss << "Exception raised in LinkedList::push_front() during first elt attribution : " << e.what() << "\n";
        Logger::error(oss.str());

        return;
    }    

    this->size++;
}

void LinkedList::push_back(size_t value) {
    std::unique_ptr<Node> new_node;

    try {
        new_node = std::make_unique<Node>(value, nullptr);
    } catch (std::exception &e) {
        std::ostringstream oss;
        oss << "Exception raised in LinkedList::push_back() during new_node creation : " << e.what() << "\n";
        Logger::error(oss.str());

        return;
    }

    if (this->empty()) {
        try {
            this->first = std::move(new_node);
        } catch (std::exception &e) {
            std::ostringstream oss;
            oss << "Exception raised in LinkedList::push_back() during first/last elt attribution : " << e.what() << "\n";
            Logger::error(oss.str());
    
            return;
        }
        this->size++;

        return;
    }

    Node *current = this->first.get();
    while (current->next != nullptr) {
        current = current->next.get();
    }

    try {
        current->next = std::move(new_node);
    } catch (std::exception &e) {
        std::ostringstream oss;
        oss << "Exception raised in LinkedList::push_back() during last elt attribution : " << e.what() << "\n";
        Logger::error(oss.str());

        return;
    }

    this->size++;
}

std::unique_ptr<Node> LinkedList::pop_front() {
    if (this->empty()) {
        return nullptr;
    }

    std::unique_ptr<Node> res;

    try {
        res = std::move(this->first);
        this->first = std::move(res->next);
        res->next = nullptr;
    } catch (std::exception &e) {
        std::ostringstream oss;
        oss << "Exception raised in LinkedList::pop_front() during first elt delete : " << e.what() << "\n";
        Logger::error(oss.str());

        return nullptr;;
    }

    this->size--;

    return res;
}

std::unique_ptr<Node> LinkedList::pop_back() {
    std::unique_ptr<Node> res;

    if (this->empty()) {
        return nullptr;
    } else if (this->first->next == nullptr) {
        res = std::move(this->first);
        this->size--;

        return res;
    }

    Node *current = this->first.get();
    while (current->next->next != nullptr) {
        current = current->next.get();
    }

    res = std::move(current->next);
    this->size--;

    return res;
}

Node *LinkedList::get(std::size_t index) {
    if (index == 0) {
        return this->first.get();
    } else if (index >= this->size) {
        std::cout << "Cannot access element at index " << index << " on list of size " << this->size << ".\n";
        return nullptr;
    }

    Node *current = this->first.get();
    size_t i = 0;
    while (i < index) {
        current = current->next.get();
        i++;
    }

    return current;
}

std::unique_ptr<LinkedList> LinkedList::split() {
    if (this->empty()) {
        std::cout << "Empty list cannot be splitted.\n";
        
        return nullptr;
    } else if (this->size == 1) {
        std::cout << "List of size 1 cannot be splitted.\n";

        return nullptr;
    }

    size_t split_index = this->size / 2;

    std::unique_ptr<LinkedList> new_list = std::make_unique<LinkedList>();

    Node *current = this->first.get();
    size_t i = 0;
    while (i < split_index - 1) {
        current = current->next.get();
        i++;
    }

    try {
        new_list->first = std::move(current->next);
        current->next = nullptr;
    } catch (std::exception &e) {
        std::ostringstream oss;
        oss << "Exception raised in LinkedList::split() during assinging new least head : " << e.what() << "\n";
        Logger::error(oss.str());

        return nullptr;
    }

    return new_list;
}

// void LinkedList::merge(std::unique_ptr<LinkedList> list) {
//     if (this->empty() || list->empty()) {
//         std::cout << "One of the list is empty.\n";

//         return nullptr;
//     }

//     size_t i = 0;
//     while (!this->empty() && !list->empty()) {
//         if (this->first->value > list->first->value) {

//         }
//     }
// }