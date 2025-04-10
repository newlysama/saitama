#pragma once

#include "generator.hh"

template <typename ArenaType>
LinkedList<ArenaType> Generator::generate_random_linked_list(size_t size, size_t max) {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<size_t> distrib(0, max);

    auto arena_size = MemoryManager::compute_safe_allocation_size(sizeof(Node), size);
    LinkedList<ArenaType> list(arena_size);
    for (size_t i = 0; i < size; ++i) {
        list.push_back(distrib(gen));
    }
    return list;
}

template <typename ArenaType>
LinkedList<ArenaType> Generator::generate_random_linked_list(size_t size, size_t max, std::shared_ptr<ArenaType> arena) {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<size_t> distrib(0, max);

    LinkedList<ArenaType> list(arena);
    for (size_t i = 0; i < size; ++i) {
        list.push_back(distrib(gen));
    }
    return list; 
}

template <typename ArenaType>
LinkedList<ArenaType> Generator::generate_sorted_linked_list(size_t size) {
    auto arena_size = MemoryManager::compute_safe_allocation_size(sizeof(Node), size);
    LinkedList<ArenaType> list(arena_size);
    for (size_t i = 0; i < size; ++i) {
        list.push_back(i);
    }
    return list;
}

template <typename ArenaType>
LinkedList<ArenaType> Generator::generate_sorted_linked_list(size_t size, std::shared_ptr<ArenaType> arena) {
    LinkedList<ArenaType> list(arena);
    for (size_t i = 0; i < size; ++i) {
        list.push_back(i);
    }
    return list;
}

template <typename ArenaType>
LinkedList<ArenaType> Generator::generate_reverse_sorted_linked_list(size_t size) {
    auto arena_size = MemoryManager::compute_safe_allocation_size(sizeof(Node), size);
    LinkedList<ArenaType> list(arena_size);
    for (size_t i = size; i > 0; --i) {
        list.push_back(i - 1);
    }
    return list;
}

template <typename ArenaType>
LinkedList<ArenaType> Generator::generate_reverse_sorted_linked_list(size_t size, std::shared_ptr<ArenaType> arena) {
    LinkedList<ArenaType> list(arena);
    for (size_t i = size; i > 0; --i) {
        list.push_back(i - 1);
    }
    return list;
}