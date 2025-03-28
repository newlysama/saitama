#pragma once

#include <cuchar>
#include <memory>
#include <exception>
#include <sstream>
#include <vector>

#include <logger.hh>

/*
*  Class implementing integer Linked List structure (at least the one we needs)
*  No need to implement clear() method since we use smart pointers
*/

class Node {
    public:
        size_t value;
        std::unique_ptr<Node> next;

        /*
        *  Constructor / Destructor
        */
        Node(size_t value, std::unique_ptr<Node> next);
        ~Node() = default;
};

class LinkedList {
    public:
        std::unique_ptr<Node> first;
        std::size_t size;
    
        /*
        *  Constructor / Destructor
        */
        LinkedList();
        LinkedList(std::vector<size_t> list);
        ~LinkedList() = default;

        // Check if list is empty
        bool empty();

        // Print the list
        void print();

        // Append new node at the beginning of the list
        void push_front(size_t value);

        // Append new node at the end of the list
        void push_back(size_t value);

        // Pop node at the beginning of the list
        std::unique_ptr<Node> pop_front();

        // Pop node at the end of the list
        std::unique_ptr<Node> pop_back();

        // Get element at index
        Node *get(std::size_t index);

        // Split in two lists, returns the 2nd part of the list, since the first one is modified anyway
        std::unique_ptr<LinkedList> split();

        // Merge current list with new one, in ascending order
        void merge(std::unique_ptr<LinkedList> list);
};