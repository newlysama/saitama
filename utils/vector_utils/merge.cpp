#include "vector_utils.hh"

std::vector<std::size_t> VectorUtils::merge(std::vector<std::size_t> left, std::vector<std::size_t> right) {
    if (left.empty()) {
        return right;
    } else if (right.empty()) {
        return left;
    }

    std::vector<std::size_t> res;
    size_t i = 0;
    size_t j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            res.push_back(left[i++]);
        } else {
            res.push_back(right[j++]);
        }
    }

    while (i < left.size()) {
        res.push_back(left[i++]);
    }

    while (j < right.size()) {
        res.push_back(right[j++]);
    }

    return res;
}