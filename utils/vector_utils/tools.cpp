#include "vector_utils.hh"

void VectorUtils::print(std::pmr::vector<size_t> vector) {
    size_t i;
    std::cout << "[ ";

    for (i = 0; i < vector.size() - 1; i++) {
        std::cout << vector[i] << ", ";
    }
    
    std::cout << vector[i] << " ]\n";
}