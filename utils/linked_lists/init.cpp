#include "linked_lists.hh"

Node::Node(size_t _value)
    : value(_value)
    , next(nullptr)
    , prev(nullptr)
    {}

Node::Node(size_t _value, std::unique_ptr<Node> _next, Node* _prev)
    : value(_value)
    , next(std::move(_next))
    , prev(_prev)
    {}

Node::Node(Node* node)
    : value(node->value)
    , next(std::move(node->next))
    , prev(node->prev)
    {}

LinkedList::LinkedList()
    : first(nullptr)
    , last(nullptr)
    , size(0)
    {}

LinkedList::LinkedList(std::vector<std::size_t> list)
    : first(nullptr)
    , last(nullptr)
    , size(0)
    {
        for (auto e : list) { this->push_back(e); }
    }

LinkedList::LinkedList(LinkedList&& other) noexcept
    : first(std::move(other.first)),
      last(other.last),
      size(other.size) {
    other.last = nullptr;
    other.size = 0;
}

LinkedList& LinkedList::operator=(LinkedList&& other) noexcept {
    if (this != &other) {
        first = std::move(other.first);
        last = other.last;
        size = other.size;

        other.last = nullptr;
        other.size = 0;
    }
    return *this;
}