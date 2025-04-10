#include "generator.hh"

using ScalableVector = std::vector<size_t, tbb::scalable_allocator<size_t>>;

ScalableVector Generator::generate_random_vector(size_t size, size_t max) {
    ScalableVector vector;
    vector.reserve(size);

    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<size_t> distrib(0, max);

    for (size_t i = 0; i < size; ++i) {
        vector.push_back(distrib(gen));
    }
    return vector;
}

ScalableVector Generator::generate_sorted_vector(size_t size) {
    ScalableVector vector(size);
    vector.reserve(size);
    std::iota(vector.begin(), vector.end(), 0);
    return vector;
}

ScalableVector Generator::generated_reverse_sorted_vector(size_t size) {
    ScalableVector vector(size);
    vector.reserve(size);
    std::iota(vector.begin(), vector.end(), 0);
    std::reverse(vector.begin(), vector.end());
    return vector;
}