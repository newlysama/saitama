#pragma once

#include <cuchar>
#include <memory>
#include <exception>
#include <sstream>
#include <vector>
#include <tuple>
#include <optional>
#include <iostream>

#include "utils/logger/logger.hh"

class Node {
    public:
        size_t value;
        std::unique_ptr<Node> next;
        Node *prev; /* Can't make this unique_ptr since it would transfer ownership */

        Node(size_t value);
        Node(size_t value, std::unique_ptr<Node> next, Node* prev);
        Node(Node* node);
        ~Node() = default;
};

/**
 * @brief Doubly-linked list implementation for size_t values
 *        Provides typical list methods (print, get, push, pop, etc...)
 */
class LinkedList {
    public:
        std::unique_ptr<Node> first;
        Node *last; /* Can't make this unique_ptr since it would transfer ownership */
        size_t size;
    
        LinkedList();
        LinkedList(std::vector<size_t> list);
        ~LinkedList() = default;

        /**
         * @brief Move constructor operator
         */
        LinkedList(LinkedList&& other) noexcept;

        /**
         * @brief Move assignment operator
         */
        LinkedList& operator=(LinkedList&& other) noexcept;

        /**
         * @brief Check if the linked list is empty
         * @see tools.cpp
         * @return bool
         */
        bool empty();

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
        Node *get(size_t index);

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
        void push_front(std::unique_ptr<Node> new_node);

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
        void push_back(std::unique_ptr<Node> new_node);

        /**
         * @brief Remove first element of the list
         * @see pop.cpp
         * @return the popped node
         */
        std::unique_ptr<Node> pop_front();

        /**
         * @brief Remove last element of the list
         * @see pop.cpp
         * @return the popped node
         */
        std::unique_ptr<Node> pop_back();

        /**
         * @brief Swap values of two nodes by index (nodes themselves are not moved)
         * @see swap.cpp
         * @param i index of the first node
         * @param j index of the second node
         */
        void swap_values(size_t i, size_t j);
};

/**
 * @brief Check if a given node is nullptr
 * @see tools.cpp
 * @param node the node to check
 * @param function the function in which it's called
 * @param index index of the node in the list
 */
void check_access_nullptr(Node* node, const std::string& function, std::optional<size_t> index = std::nullopt);

/**
 * @brief Check that index is not out of bounds (here list->size)
 * @see tools.cpp
 * @param function the function which calls it
 * @param index the tested index
 * @param list_size size of the tested list
 */
void check_index(const std::string& function, size_t index, size_t list_size);