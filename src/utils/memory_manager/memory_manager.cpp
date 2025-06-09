#include "memory_manager.hh"

using namespace std;

MemoryManager& MemoryManager::instance() {
    static MemoryManager manager;
    return manager;
}

std::shared_ptr<MemoryManager::FixedArena> MemoryManager::create_fixed_arena(size_t s) {
    auto arena = std::make_shared<FixedArena>(s);
    fixed_arenas.push_back(arena);
    return arena;
}

std::shared_ptr<MemoryManager::ScalableArena> MemoryManager::create_scalable_arena() {
    auto arena = std::make_shared<ScalableArena>();
    scalable_arenas.push_back(arena);
    return arena;
}

void MemoryManager::reset_fixed() {
    for (auto& arena : fixed_arenas) {
        arena->reset();
    }
}

void MemoryManager::hard_reset() {
    fixed_arenas.clear();
    scalable_arenas.clear();
}


size_t MemoryManager::compute_safe_allocation_size(size_t object_size, size_t object_count) {
    constexpr size_t ALIGNMENT = alignof(std::max_align_t);

    // Calculate padded size per object
    size_t padding = (ALIGNMENT - (object_size % ALIGNMENT)) % ALIGNMENT;
    size_t padded_size = object_size + padding;

    // Total buffer size
    return padded_size * object_count;
}