#include "linked_lists.hh"

Node::Node(size_t _value, std::unique_ptr<Node> _next, Node* _prev)
    : value(_value)
    , next(std::move(_next))
    , prev(_prev)
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
        for (auto e : list) {
            this->push_back(e);
        }
    }