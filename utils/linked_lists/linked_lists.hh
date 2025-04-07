#pragma once

#include <cstddef>
#include <exception>
#include <sstream>
#include <vector>
#include <tuple>
#include <optional>
#include <iostream>

#include "utils/logger/logger.hh"
#include "utils/memory_manager/memory_manager.hh"
#include "utils/checker/checker.hh"

class Node {
    public:
        size_t value;
        Node* next;
        Node* prev;

        Node(size_t value) noexcept;
        Node(size_t value, Node* next, Node* prev) noexcept;
        // Node(Node* node);
        ~Node() = default;

        /**
         * @brief Constructs a Node using placement new into pre-allocated memory resource
         * @see tools.cpp
         * @param resource Pointer to the memory resource.
         * @param value Value to initialize the Node with.
         * @return Pointer to the newly created Node.
         */
        static Node* create(std::pmr::memory_resource* resource, size_t value) noexcept;
};

/**
 * @brief Doubly-linked list implementation for size_t values
 * Provides typical list methods (print, get, push, pop, etc...)
 * Uses utils/memory_manager/ for custom memory managment
 */
class LinkedList {
    public:
        Node* first;
        Node* last;
        size_t size;

        // Arena pool for our nodes
        std::shared_ptr<std::pmr::memory_resource> arena;
    
        /**
         * @brief Create new list with specified arena size
         * @param arena_size size of the arena
         */
        LinkedList(std::size_t arena_size);

        /**
         * @brief Create new list from a vector + with specified arena size
         * @param list the vector to use
         * @param arena_size size of the arena
         */
        LinkedList(std::vector<size_t> list, std::size_t arena_size);

        /**
         * @brief Copy arena constructor
         * Create a new list that uses an already existing arena
         * @param shared_arena the arena we want to share
         */
        LinkedList(std::shared_ptr<std::pmr::memory_resource> shared_arena);

        /**
         * @brief Vector + copy arena constructor
         * @param list the vector used to construct the list
         * @param shared_arena the arena to share
         */
        LinkedList(std::vector<size_t> list, std::shared_ptr<std::pmr::memory_resource> shared_arena);

        /**
         * @brief Move constructor operator
         */
        LinkedList(LinkedList&& other) noexcept;

        /**
         * @brief Move assignment operator
         */
        LinkedList& operator=(LinkedList&& other) noexcept;

        /**
         * @brief Default destructor
         */
        ~LinkedList() = default;

        /**
         * @brief Check if the linked list is empty
         * @see tools.cpp
         * @return bool
         */
        bool empty() noexcept;

        /**
         * @brief Print the linked list. Format : [ elt, elt, elt ]
         * @see tools.cpp
         */
        void print();

        /**
         * @brief Get a not at a certain index
         * @see tools.cpp
         * @param index the requested node index
         * @return the requested node 
         */
        Node* get(size_t index);

        /**
         * @brief clear the list
         */
        void clear();

        /**
         * @brief Add new element at the beginning of the list
         * @see push.cpp
         * @param value the value we want to add
         */
        void push_front(size_t value);

        /**
         * @brief Add new node at the beginning of the list
         * @see push.cpp
         * @param new_node the node we want to add
         */
        void push_front(Node* new_node);

        /**
         * @brief Add new element at the end of the list
         * @see push.cpp
         * @param value the value we want to add
         */
        void push_back(size_t value);
    
        /**
         * @brief Add new node at the end of the list
         * @see push.cpp
         * @param new_node the node we want to add
         */
        void push_back(Node* new_node);

        /**
         * @brief Remove first element of the list
         * @see pop.cpp
         * @return the popped node
         */
        Node* pop_front();

        /**
         * @brief Remove last element of the list
         * @see pop.cpp
         * @return the popped node
         */
        Node* pop_back();

        /**
         * @brief Swap values of two nodes by index (nodes themselves are not moved)
         * @see swap.cpp
         * @param i index of the first node
         * @param j index of the second node
         */
        void swap_values(size_t i, size_t j);
    
    private:
        /**
         * @brief Function factoring code for both puck_front() methods
         * @see push.cpp
         * @param new_node the new node to insert
         */
        void insert_node_at_front(Node* new_node);

        /**
         * @brief Function factoring code for both puck_back() methods
         * @see push.cpp
         * @param new_node the new node to insert
         */
        void insert_node_at_back(Node* new_node);

        /**
         * @brief Function factoring code for pop() methods
         * @see pop.cpp
         * @param new_node the new node to pop
         */
        Node* pop_node(Node* node);
};