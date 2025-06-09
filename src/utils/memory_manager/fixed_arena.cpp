#include "memory_manager.hh"

MemoryManager::FixedArena::FixedArena(size_t s)
    : buffer(std::make_unique<char[]>(s))
    , current(buffer.get())
    , size(s)
    {}
    
void* MemoryManager::FixedArena::allocate(size_t s) {
    // Align current to alignof(std::max_align_t)
    std::uintptr_t aligned = (reinterpret_cast<std::uintptr_t>(current) + alignof(std::max_align_t) - 1) & ~(alignof(std::max_align_t) - 1);
    char* aligned_ptr = reinterpret_cast<char*>(aligned);

    // If not enough space to allocate s Bytes, return nullptr
    if (aligned_ptr + s > buffer.get() + size) {
        return nullptr;
    }
    
    current = aligned_ptr + s;
    return aligned_ptr;
}
    

void MemoryManager::FixedArena::reset() {
    current = buffer.get();
}