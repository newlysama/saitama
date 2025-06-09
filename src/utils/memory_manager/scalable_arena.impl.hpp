#pragma once

#include "memory_manager.hh"

using namespace tbb;

template <typename T>
scalable_allocator<T> MemoryManager::ScalableArena::get_allocator() const {
    return scalable_allocator<T>();
}

template <typename T>
T* MemoryManager::ScalableArena::allocate(size_t n) {
    scalable_allocator<T> alloc;
    return alloc.allocate(n);
}

template <typename T>
void MemoryManager::ScalableArena::deallocate(T* ptr, size_t n) {
    scalable_allocator<T> alloc;
    alloc.deallocate(ptr, n);
}
