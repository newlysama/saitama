#include "generator.hh"

std::pmr::vector<size_t> Generator::generate_random_vector(size_t size, size_t max) {
    auto arena = MemoryManager::instance().create_arena(sizeof(size_t) * size);

    std::pmr::vector<size_t> list(arena.get());
    list.reserve(size);

    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<size_t> distrib(0, max);

    for (size_t i = 0; i < size; ++i) {
        list.push_back(distrib(gen));
    }
    return list;
}

std::pmr::vector<size_t> Generator::generate_random_vector(size_t size, size_t max, std::pmr::memory_resource* arena) {
    std::pmr::vector<size_t> list(arena);
    list.reserve(size);

    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<size_t> distrib(0, max);

    for (size_t i = 0; i < size; ++i) {
        list.push_back(distrib(gen));
    }
    return list;
}

std::pmr::vector<size_t> Generator::generate_sorted_vector(size_t size) {
    auto arena = MemoryManager::instance().create_arena(sizeof(size_t) * size);
    std::pmr::vector<size_t> list(size, arena.get());
    std::iota(list.begin(), list.end(), 0);
    return list;
}

std::pmr::vector<size_t> Generator::generate_sorted_vector(size_t size, std::pmr::memory_resource* arena) {
    std::pmr::vector<size_t> list(size, arena);
    std::iota(list.begin(), list.end(), 0);
    return list;
}

std::pmr::vector<size_t> Generator::generated_reverse_sorted_vector(size_t size) {
    auto arena = MemoryManager::instance().create_arena(sizeof(size_t) * size);
    std::pmr::vector<size_t> list(size, arena.get());
    std::iota(list.begin(), list.end(), 0);
    std::reverse(list.begin(), list.end());
    return list;
}

std::pmr::vector<size_t> Generator::generated_reverse_sorted_vector(size_t size, std::pmr::memory_resource* arena) {
    std::pmr::vector<size_t> list(size, arena);
    std::iota(list.begin(), list.end(), 0);
    std::reverse(list.begin(), list.end());
    return list;
}