#include "vector_utils.hh"

std::tuple<std::vector<std::size_t>, std::vector<std::size_t>> VectorUtils::split(std::vector<std::size_t> vector) {
    std::vector<size_t> left;
    std::vector<size_t> right;

    if (vector.empty()) {
        throw std::invalid_argument("VectorUtils::split() : cannot split empty vector.");
    } else if (vector.size() == 1) {
        throw std::invalid_argument("VectorUtils::split() : cannot split vector of size 1.");
    }

    std::size_t split_index = vector.size() / 2;
    std::size_t i = 0;

    while (i < split_index) {
        left.push_back(vector[i]);
        i++;
    }

    while (i < vector.size()) {
        right.push_back(vector[i]);
        i++;
    }

    return std::make_tuple(left, right);
}