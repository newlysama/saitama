#include "linked_lists.hh"

using namespace Checker;

Node::Node(size_t _value) noexcept
    : value(_value)
    , next(nullptr)
    , prev(nullptr)
    {}

Node::Node(size_t _value, Node* _next, Node* _prev) noexcept
    : value(_value)
    , next(_next)
    , prev(_prev)
    {}

// Node::Node(Node* node)
//     : value(node->value)
//     , next(node->next)
//     , prev(node->prev)
//     {
//         node->next = nullptr;
//         node->prev = nullptr;
//         node->value = NULL;
//     }

LinkedList::LinkedList(std::size_t arena_size)
    : first(nullptr)
    , last(nullptr)
    , size(0)
    , arena(MemoryManager::instance().create_arena(arena_size))
    {}

// LinkedList instanciated from a vector
LinkedList::LinkedList(std::vector<std::size_t> list, std::size_t arena_size)
    : first(nullptr)
    , last(nullptr)
    , size(0)
    , arena(MemoryManager::instance().create_arena(arena_size)) {
    for (auto val : list) {
        this->push_back(val);
    }
}

// Copy arena constructor
LinkedList::LinkedList(std::shared_ptr<std::pmr::memory_resource> shared_arena)
    : first(nullptr)
    , last(nullptr)
    , size(0)
    , arena(std::move(shared_arena))
    {}

// Vector + arena copy
LinkedList::LinkedList(std::vector<std::size_t> list, std::shared_ptr<std::pmr::memory_resource> shared_arena)
    : first(nullptr)
    , last(nullptr)
    , size(0)
    , arena(std::move(shared_arena)) {
    for (auto val : list) {
        this->push_back(val);
    }
}

// Move constructor
LinkedList::LinkedList(LinkedList&& other) noexcept
    : first(other.first),
      last(other.last),
      size(other.size),
      arena(std::move(other.arena)) {
    other.first = nullptr;
    other.last = nullptr;
    other.size = 0;
}

// Move assignment operator
LinkedList& LinkedList::operator=(LinkedList&& other) noexcept {
    if (this != &other) {
        first = other.first;
        last = other.last;
        size = other.size;
        arena = std::move(other.arena);

        other.first = nullptr;
        other.last = nullptr;
        other.size = 0;
    }
    return *this;
}