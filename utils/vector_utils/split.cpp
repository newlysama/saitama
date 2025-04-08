#include "vector_utils.hh"

/**
 * @brief Use std::move to build tuples. This prevents make_tuple from copying the vector, which would be more time consuming.
 */
std::tuple<std::pmr::vector<size_t>, std::pmr::vector<size_t>> VectorUtils::split(std::pmr::vector<size_t> vector) {
    std::pmr::vector<size_t> left(vector.get_allocator().resource());
    std::pmr::vector<size_t> right(vector.get_allocator().resource());

    if (vector.empty()) {
        throw std::invalid_argument("VectorUtils::split() : cannot split empty vector.");
    } else if (vector.size() == 1) {
        throw std::invalid_argument("VectorUtils::split() : cannot split vector of size 1.");
    }

    size_t split_index = vector.size() / 2;
    size_t i = 0;

    while (i < split_index) {
        left.push_back(vector[i]);
        i++;
    }

    while (i < vector.size()) {
        right.push_back(vector[i]);
        i++;
    }

    return std::make_tuple(std::move(left), std::move(right));
}