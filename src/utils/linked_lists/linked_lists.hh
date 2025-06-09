#pragma once

#include <cstddef>
#include <exception>
#include <sstream>
#include <vector>
#include <tuple>
#include <optional>
#include <iostream>
#include <type_traits>

#include "utils/logger/logger.hh"
#include "utils/memory_manager/memory_manager.hh"
#include "utils/checker/checker.hh"

class Node {
    public:
        size_t value;
        Node* next;
        Node* prev;

        Node(size_t _value) noexcept
            : value(_value)
            , next(nullptr)
            , prev(nullptr)
            {}

        ~Node() = default;

        /**
         * @brief Constructs a Node using placement new into an arena.
         * @param arena The arena we want to place new node in (can be fixed or scalable)
         * @param value Value to initialize the Node with.
         * @return Pointer to the newly created Node.
         */
        template <typename ArenaType>
        static Node* create(std::shared_ptr<ArenaType> arena, size_t value) noexcept {
            void* mem;

            if constexpr (std::is_same_v<ArenaType, MemoryManager::FixedArena>) {
                mem = arena->allocate(sizeof(Node));
            } else if constexpr (std::is_same_v<ArenaType, MemoryManager::ScalableArena>) {
                mem = arena.get()->template allocate<Node>(1);; // 1 elt by default
            } else {
                static_assert(std::is_same_v<ArenaType, MemoryManager::FixedArena> ||
                                std::is_same_v<ArenaType, MemoryManager::ScalableArena>,
                                "Unsupported arena type in LinkedList constructor");
            }

            return new (mem) Node(value); // Placement new
        }
};

/**
 * @brief Doubly-linked list implementation for size_t values
 * Provides typical list methods (print, get, push, pop, etc...)
 * Uses utils/memory_manager/ for custom memory managment.
 */
template <typename ArenaType>
class LinkedList {
    public:
        Node* first;
        Node* last;
        size_t size;

        // Arena pool for our nodes
        // Can be FixedArena or ScalableArena
        std::shared_ptr<ArenaType> arena;
    
        /**
         * @brief Create new list with specified arena size
         * @see init.impl.hpp
         * @param arena_size Optional arena size parameter (no need of arena_size when Arena is scalable)
         */
        LinkedList(std::optional<size_t> arena_size = std::nullopt);

        /**
         * @brief Create new list from a vector + with specified arena size
         * @see init.impl.hpp
         * @param vector the vector to use
         * @param arena_size Optional arena size parameter (no need of arena_size when Arena is scalable)
         */
        LinkedList(std::vector<size_t> vector, std::optional<size_t> arena_size = std::nullopt);

        /**
         * @brief Copy arena constructor
         * Create a new list that uses an already existing arena
         * @see init.impl.hpp
         * @param arena the arena we want to use
         */
        LinkedList(std::shared_ptr<ArenaType> arena);

        /**
         * @brief Vector + copy arena constructor
         * Create a new list using an existing vector + arena
         * @see init.impl.hpp
         * @param vector the vector used to construct the list
         * @param arena the arena to use
         */
        LinkedList(std::vector<size_t> vector, std::shared_ptr<ArenaType> arena);

        /**
         * @brief Move constructor operator
         * @see init.impl.hpp
         */
        LinkedList(LinkedList&& other) noexcept;

        /**
         * @brief Move assignment operator
         * @see init.impl.hpp
         */
        LinkedList& operator=(LinkedList&& other) noexcept;

        /**
         * @brief Default destructor
         */
        ~LinkedList() noexcept = default;

        /**
         * @brief Check if the linked list is empty
         * @see tools.impl.hpp
         * @return bool
         */
        bool empty() noexcept;

        /**
         * @brief Print the linked list. Format : [ elt, elt, elt ]
         * @see tools.impl.hpp
         */
        void print();

        /**
         * @brief Get a not at a certain index
         * @see tools.impl.hpp
         * @param index the requested node index
         * @return the requested node 
         */
        Node* get(size_t index);

        /**
         * @brief clear the list
         * @see tools.impl.hpp
         */
        void clear();

        /**
         * @brief Add new element at the beginning of the list
         * @see push.impl.hpp
         * @param value the value we want to add
         */
        void push_front(size_t value);

        /**
         * @brief Add new node at the beginning of the list
         * @see push.impl.hpp
         * @param new_node the node we want to add
         */
        void push_front(Node* new_node);

        /**
         * @brief Add new element at the end of the list
         * @see push.impl.hpp
         * @param value the value we want to add
         */
        void push_back(size_t value);
    
        /**
         * @brief Add new node at the end of the list
         * @see push.impl.hpp
         * @param new_node the node we want to add
         */
        void push_back(Node* new_node);

        /**
         * @brief Remove first element of the list
         * @see pop.impl.hpp
         * @return the popped node
         */
        Node* pop_front();

        /**
         * @brief Remove last element of the list
         * @see pop.impl.hpp
         * @return the popped node
         */
        Node* pop_back();

        /**
         * @brief Swap values of two nodes by index (nodes themselves are not moved)
         * @see swap.impl.hpp
         * @param i index of the first node
         * @param j index of the second node
         */
        void swap_values(size_t i, size_t j);
    
    private:
        /**
         * @brief Function factoring code for both puck_front() methods
         * @see push.impl.hpp
         * @param new_node the new node to insert
         */
        void insert_node_at_front(Node* new_node);

        /**
         * @brief Function factoring code for both puck_back() methods
         * @see push.impl.hpp
         * @param new_node the new node to insert
         */
        void insert_node_at_back(Node* new_node);

        /**
         * @brief Function factoring code for pop() methods
         * @see pop.impl.hpp
         * @param new_node the new node to pop
         */
        Node* pop_node(Node* node);
};

#include "init.impl.hpp"
#include "pop.impl.hpp"
#include "push.impl.hpp"
#include "swap.impl.hpp"
#include "tools.impl.hpp"