#include "generator.hh"

std::vector<size_t> Generator::generate_random_vector(size_t size, size_t max) {
    std::vector<size_t> list(size);
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<size_t> distrib(0, max);
    std::generate(list.begin(), list.end(), [&]() { return distrib(gen); });
    return list;
}

std::vector<size_t> Generator::generate_sorted_vector(size_t size) {
    std::vector<size_t> list(size);
    std::iota(list.begin(), list.end(), 0);
    return list;
}

std::vector<size_t> Generator::generated_reverse_sorted_vector(size_t size) {
    std::vector<size_t> list(size);
    std::iota(list.begin(), list.end(), 0);
    std::reverse(list.begin(), list.end());
    return list;
}