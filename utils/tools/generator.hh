#include <cuchar>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>

#include "utils/linked_lists/linked_lists.hh"

/**
 * @brief Simple namespace that holds generating functions for various data structures
 */
namespace Generator {
    // ===========================================================================
    //       			     VECTORS GENERATORS
    // ===========================================================================

    /**
     * @brief Generate a vector of random values
     * 
     * @param size size of the vector
     * @param max max value of the vector
     * @return the generated vector
     */
    std::vector<size_t> generate_random_vector(size_t size, size_t max);
    
    /**
     * @brief Generate a vector of sorted values
     * 
     * @param size size of the vector
     * @param max max value of the vector
     * @return the generated vector
     */
    std::vector<size_t> generate_sorted_vector(size_t size);
    
    /**
     * @brief Generate a vector of reverse sorted values
     * 
     * @param size size of the vector
     * @param max max value of the vector
     * @return the generated vector
     */
    std::vector<size_t> generated_reverse_sorted_vector(size_t size);

    // ===========================================================================
    //       			   LINKED LISTS GENERATORS
    // ===========================================================================

    /**
     * @brief Generate a linked list of random values
     * 
     * @param size size of the linked list
     * @param max max value of the linked list
     * @return the generated linked list
     */
    LinkedList generate_random_linked_list(size_t size, size_t max);
    
    /**
     * @brief Generate a linked list of sorted values
     * 
     * @param size size of the linked list
     * @param max max value of the linked list
     * @return the generated linked list
     */
    LinkedList generate_sorted_linked_list(size_t size);
    
    /**
     * @brief Generate a linked list of reverse sorted values
     * 
     * @param size size of the linked list
     * @param max max value of the linked list
     * @return the generated linked list
     */
    LinkedList generate_reverse_sorted_linked_list(size_t size);
}