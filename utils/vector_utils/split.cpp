#include "vector_utils.hh"

using ScalableVector = std::vector<size_t, tbb::scalable_allocator<size_t>>;

/**
 * @brief Use std::move to build tuples. This prevents make_tuple from copying the vector, which would be more time consuming.
 */
std::tuple<ScalableVector, ScalableVector> VectorUtils::split(ScalableVector vector) {
    ScalableVector left(vector.get_allocator());
    ScalableVector right(vector.get_allocator());

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