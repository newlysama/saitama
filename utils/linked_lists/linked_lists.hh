#pragma once

#include <cuchar>
#include <memory>
#include <exception>
#include <sstream>
#include <vector>
#include <tuple>
#include <optional>
#include <iostream>

/*
*  Class implementing size_t Linked List structure (at least the methods we needs)
*  No need to implement clear() method since we use unique pointers
*/

class Node {
    public:
        size_t value;
        std::unique_ptr<Node> next;
        // can't make prev unique_ptr because node->prev->prev->next already has ownership
        Node *prev;

        /*
        *  Constructor / Destructor
        */
        Node(size_t value, std::unique_ptr<Node> next, Node* prev);
        Node(Node* node);
        ~Node() = default;
};

class LinkedList {
    public:
        std::unique_ptr<Node> first;
        // can't make last unique_ptr because penultimate node->next already has ownership
        Node *last; 
        size_t size;
    
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

        // Get element at index, use brut ptr since we don't want to tranfer ownership
        Node *get(size_t index);

        // Transfer src into dest in-place
        static void transfer(std::unique_ptr<LinkedList>& dest, std::unique_ptr<LinkedList>& src);

        // Append new node at the beginning of the list
        void push_front(size_t value);

        // Append new node at the end of the list
        void push_back(size_t value);
    
        // Need this version for last handleing
        void push_back(std::unique_ptr<Node> new_node);

        // Pop node at the beginning of the list
        std::unique_ptr<Node> pop_front();

        // Pop node at the end of the list
        std::unique_ptr<Node> pop_back();

        // Swap nodes values at specified index
        void swap_values(size_t i, size_t j);

        // Split list in two lists, returns a tuple of the splited lists
        // Use optional split_index parameter, so we can specify or not at which index we want to split
        // Split index is middle by default
        static std::tuple<std::unique_ptr<LinkedList>, std::unique_ptr<LinkedList>>
        split(std::unique_ptr<LinkedList> list, std::optional<size_t> split_index = std::nullopt);

        // Custom split to isolate the pivot (used for quick sort Lomuto version)
        // Return pivot as LinkedList so we can concat it in quicksort
        static std::tuple<std::unique_ptr<LinkedList>, std::unique_ptr<LinkedList>, std::unique_ptr<LinkedList>>
        split_around_pivot(std::unique_ptr<LinkedList> list, size_t pivot_index);

        // Merge two sorted lists into a new one, keeping it sorted
        static std::unique_ptr<LinkedList> merge(std::unique_ptr<LinkedList> list1, std::unique_ptr<LinkedList> list2);

        // Concat 2 lists in-place
        static void concat(std::unique_ptr<LinkedList>& list1, std::unique_ptr<LinkedList>& list2);

        // Lomuto partition algorithm
        size_t partition_lomuto(size_t low, size_t high);

        // Hoare's partition algorithm
        size_t partition_hoare(size_t low, size_t high);
};

// Used to check if we try to access nullptr, throw std::logic_arg if yes
void check_access_nullptr(Node* node, const std::string& function, std::optional<size_t> index = std::nullopt);

// Used to check if the required index is out of bounds, throw std::invalid_argument if yes
void check_index(const std::string& function, size_t index, size_t list_size);