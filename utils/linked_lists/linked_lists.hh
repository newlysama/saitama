#pragma once

#include <cuchar>
#include <memory>
#include <exception>
#include <sstream>
#include <vector>
#include <tuple>

#include <logger/logger.hh>

/*
*  Class implementing integer Linked List structure (at least the one we needs)
*  No need to implement clear() method since we use unique pointers
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

        // Get element at index, use brut ptr since we don't want to tranfer ownership
        Node *get(std::size_t index);

        // Swap nodes values at specified index
        void swap_values(size_t i, size_t j);

        // Split list in two lists, returns a tuple of the splited lists
        static std::tuple<std::unique_ptr<LinkedList>, std::unique_ptr<LinkedList>> split(std::unique_ptr<LinkedList> list);

        // Merge two sorted lists into a new one, keeping it sorted
        static std::unique_ptr<LinkedList> merge(std::unique_ptr<LinkedList> list1, std::unique_ptr<LinkedList> list2);
};