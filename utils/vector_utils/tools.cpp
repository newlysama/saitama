#include "vector_utils.hh"

using ScalableVector = std::vector<size_t, tbb::scalable_allocator<size_t>>;

void VectorUtils::print(ScalableVector vector) {
    size_t i;
    std::cout << "[ ";

    for (i = 0; i < vector.size() - 1; i++) {
        std::cout << vector[i] << ", ";
    }
    
    std::cout << vector[i] << " ]\n";
}