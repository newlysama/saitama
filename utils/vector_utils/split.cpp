#include "vector_utils.hh"

std::tuple<std::vector<std::size_t>, std::vector<std::size_t>> VectorUtils::split(std::vector<std::size_t> list) {
    std::vector<size_t> left;
    std::vector<size_t> right;

    if (list.empty()) {
        throw std::invalid_argument("VectorUtils::split() : cannot split empty vector.");
    } else if (list.size() == 1) {
        throw std::invalid_argument("VectorUtils::split() : cannot split vector of size 1.");
    }

    std::size_t split_index = list.size() / 2;
    std::size_t i = 0;

    while (i < split_index) {
        left.push_back(list[i]);
        i++;
    }

    while (i < list.size()) {
        right.push_back(list[i]);
        i++;
    }

    return std::make_tuple(left, right);
}