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

std::tuple<std::unique_ptr<LinkedList>, std::unique_ptr<LinkedList>> LinkedList::split(std::unique_ptr<LinkedList> list) {
    if (list->empty()) {
        return std::make_tuple(nullptr, nullptr);
    } else if (list->size == 1) {
        return std::make_tuple(nullptr, nullptr);
    }

    size_t split_index = list->size / 2;

    std::unique_ptr<LinkedList> new_list1 = std::make_unique<LinkedList>();
    std::unique_ptr<LinkedList> new_list2 = std::make_unique<LinkedList>();

    new_list1->first = std::move(list->first);
    Node *current = new_list1->first.get();
    size_t i = 0;
    while (i < split_index - 1) {
        current = current->next.get();
        i++;
    }

    try {
        new_list2->first = std::move(current->next);
        current->next = nullptr;
    } catch (std::exception &e) {
        std::ostringstream oss;
        oss << "Exception raised in LinkedList::split() during assinging new least head : " << e.what() << "\n";
        Logger::error(oss.str());

        return std::make_tuple(nullptr, nullptr);
    }

    std::tie(new_list1->size, new_list2->size) =
        list->size % 2 == 0
        ? std::make_tuple(split_index, split_index)
        : std::make_tuple(split_index, split_index + 1);

    return std::make_tuple<std::unique_ptr<LinkedList>, std::unique_ptr<LinkedList>>(std::move(new_list1), std::move(new_list2));
}

std::unique_ptr<LinkedList> LinkedList::merge(std::unique_ptr<LinkedList> list1, std::unique_ptr<LinkedList> list2) {
    if (list1->empty() || list2->empty()) {
        return nullptr;
    }

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