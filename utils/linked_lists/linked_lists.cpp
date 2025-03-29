#include "linked_lists.hh"

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

void LinkedList::push_front(size_t value) {
    std::unique_ptr<Node> new_node = std::make_unique<Node>(value, std::move(this->first));
   
    this->first = std::move(new_node);
    this->size++;
}

void LinkedList::push_back(size_t value) {
    std::unique_ptr<Node> new_node = std::make_unique<Node>(value, nullptr); 
    
    if (this->empty()) {
        this->first = std::move(new_node);
        this->size++;
        return;
    }

    Node *current = this->first.get();
    while (current->next != nullptr) {
        current = current->next.get();
    }

    current->next = std::move(new_node);
    this->size++;
}

std::unique_ptr<Node> LinkedList::pop_front() {
    if (this->empty()) {
        throw std::invalid_argument("Cannot pop_front() on empty list.");
    }

    std::unique_ptr<Node> res = std::move(this->first);
    this->first = std::move(res->next);
    res->next = nullptr;

    this->size--;

    // Return the poped node, since we'll need it leter
    return res;
}

std::unique_ptr<Node> LinkedList::pop_back() {
    std::unique_ptr<Node> res;

    if (this->empty()) {
        throw std::invalid_argument("Cannot pop_back() on empty list.");
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

void LinkedList::swap_values(size_t i, size_t j) {
    if (i >= this->size || j >= this->size) {
        throw std::invalid_argument("Swap() required index is out of bounds.");
    } else if (i == j) {
        throw std::invalid_argument("Swap() required indexs are equal.");
    }

    // So we don't have to check and build 2 loops...
    if (i > j) { std::swap(i, j); }

    // Don't use this->get() here since we want don't want to go through our list twice
    std::size_t index = 0;
    Node *current = this->first.get();
    while (index < i) {
        current = current->next.get();
        index++;
    }
    Node* tmp = current;

    while (index < j) {
        current = current->next.get();
        index++;     
    }

    // Only swap values since we don't care about the node itself here
    std::swap(tmp->value, current->value);
}

std::tuple<std::unique_ptr<LinkedList>, std::unique_ptr<LinkedList>> LinkedList::split(std::unique_ptr<LinkedList> list) {
    if (list->empty()) {
        throw std::invalid_argument("Cannot split() on empty list.");
    } else if (list->size == 1) {
        throw std::invalid_argument("Cannot split() list of size 1.");
    }

    size_t split_index = list->size / 2;

    // Don't need to modify emplace, since we use unique ptrs anyway
    std::unique_ptr<LinkedList> new_list1 = std::make_unique<LinkedList>();
    std::unique_ptr<LinkedList> new_list2 = std::make_unique<LinkedList>();

    new_list1->first = std::move(list->first);
    Node *current = new_list1->first.get();
    size_t i = 0;
    while (i < split_index - 1) {
        current = current->next.get();
        i++;
    }

    new_list2->first = std::move(current->next);
    current->next = nullptr;

    // Double assignment because it's cool
    std::tie(new_list1->size, new_list2->size) =
        list->size % 2 == 0
        ? std::make_tuple(split_index, split_index)
        : std::make_tuple(split_index, split_index + 1);

    return std::make_tuple<std::unique_ptr<LinkedList>, std::unique_ptr<LinkedList>>(std::move(new_list1), std::move(new_list2));
}

std::unique_ptr<LinkedList> LinkedList::merge(std::unique_ptr<LinkedList> list1, std::unique_ptr<LinkedList> list2) {
    // We don't care about checking if both lists are empty, we'll just return the other one anyway
    if (list1->empty()) {
        return list2;
    } else if (list2->empty()) {
        return list1;
    }

    // Return a new list is simplier here, since we didn't implement insert() method
    std::unique_ptr<LinkedList> res = std::make_unique<LinkedList>();
    while (!list1->empty() && !list2->empty()) {
        if (list1->first->value <= list2->first->value) {
            std::unique_ptr<Node> n = list1->pop_front();
            res->push_back(n->value);
        } else {
            std::unique_ptr<Node> n = list2->pop_front();
            res->push_back(n->value);
        }
    }

    while (!list1->empty()) {
        std::unique_ptr<Node> n = list1->pop_front();
        res->push_back(n->value);   
    }

    while (!list2->empty()) {
        std::unique_ptr<Node> n = list2->pop_front();
        res->push_back(n->value);   
    }

    return res;
}