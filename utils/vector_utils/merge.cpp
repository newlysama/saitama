#include "vector_utils.hh"

using ScalableVector = std::vector<size_t, tbb::scalable_allocator<size_t>>;

ScalableVector VectorUtils::merge(ScalableVector left, ScalableVector right) {
    if (left.empty()) {
        return right;
    } else if (right.empty()) {
        return left;
    }

    ScalableVector res(left.get_allocator());
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