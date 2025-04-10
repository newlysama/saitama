#pragma once

#include "linked_lists.hh"

using namespace Checker;

template <typename ArenaType>
LinkedList<ArenaType>::LinkedList(std::optional<size_t> arena_size)
    : first(nullptr)
    , last(nullptr)
    , size(0) {

    if constexpr (std::is_same_v<ArenaType, MemoryManager::FixedArena>) {
        if (!arena_size.has_value()) {
            throw std::invalid_argument("FixedArena requires an arena size");
        }
        arena = MemoryManager::instance().create_fixed_arena(arena_size.value());
    } else if constexpr (std::is_same_v<ArenaType, MemoryManager::ScalableArena>) {
        arena = MemoryManager::instance().create_scalable_arena();
    } else {
        static_assert(std::is_same_v<ArenaType, MemoryManager::FixedArena> ||
                        std::is_same_v<ArenaType, MemoryManager::ScalableArena>,
                        "Unsupported arena type in LinkedList constructor");
    }
}
    

template <typename ArenaType>
LinkedList<ArenaType>::LinkedList(std::vector<size_t> vector, std::optional<size_t> arena_size)
    : first(nullptr)
    , last(nullptr)
    , size(0) {

    if constexpr (std::is_same_v<ArenaType, MemoryManager::FixedArena>) {
        if (!arena_size.has_value()) {
            throw std::invalid_argument("FixedArena requires an arena size");
        }
        arena = MemoryManager::instance().create_fixed_arena(arena_size.value());
    } else if constexpr (std::is_same_v<ArenaType, MemoryManager::ScalableArena>) {
        arena = MemoryManager::instance().create_scalable_arena();
    } else {
        static_assert(std::is_same_v<ArenaType, MemoryManager::FixedArena> ||
                      std::is_same_v<ArenaType, MemoryManager::ScalableArena>,
                      "Unsupported arena type in LinkedList constructor");
    }

    for (auto val : vector) {
        this->push_back(val);
    }
}

template <typename ArenaType>
LinkedList<ArenaType>::LinkedList(std::shared_ptr<ArenaType> _arena)
    : first(nullptr)
    , last(nullptr)
    , size(0)
    , arena(_arena)
    {}

template <typename ArenaType>
LinkedList<ArenaType>::LinkedList(std::vector<size_t> vector, std::shared_ptr<ArenaType> _arena)
    : first(nullptr)
    , last(nullptr)
    , size(0)
    , arena(_arena) {
    for (auto val : vector) {
        this->push_back(val);
    }
}

template <typename ArenaType>
LinkedList<ArenaType>::LinkedList(LinkedList&& other) noexcept
    : first(other.first)
    , last(other.last)
    , size(other.size)
    , arena(std::move(other.arena)) {
    other.clear();
}

template <typename ArenaType>
LinkedList<ArenaType>& LinkedList<ArenaType>::operator=(LinkedList&& other) noexcept {
    if (this != &other) {
        first = other.first;
        last = other.last;
        size = other.size;
        arena = std::move(other.arena);

        other.clear();
    }
    return *this;
}