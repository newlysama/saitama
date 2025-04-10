#include <cstddef>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>

#include "utils/linked_lists/linked_lists.hh"
#include "utils/memory_manager/memory_manager.hh"

/**
 * @brief Simple namespace that holds generating functions for various data structures
 */
namespace Generator {
    // ===========================================================================
    //       			     VECTORS GENERATORS
    // ===========================================================================

    /**
     * @brief Generate a vector of random number values
     * 
     * @param size size of the vector
     * @param max max value of the vector
     * @return the generated vector
     */
    std::pmr::vector<size_t> generate_random_vector(size_t size, size_t max);

    /**
     * @brief Generate a vector of random number values using existing arena
     * 
     * @param size size of the vector
     * @param max max value of the vector
     * @return the generated vector
     */
    std::pmr::vector<size_t> generate_random_vector(size_t size, size_t max, std::pmr::memory_resource* raw_arena);
    
    /**
     * @brief Generate a vector of sorted number values
     * 
     * @param size size of the vector
     * @param max max value of the vector
     * @return the generated vector
     */
    std::pmr::vector<size_t> generate_sorted_vector(size_t size);


    /**
     * @brief Generate a vector of sorted number values using existing arena
     * 
     * @param size size of the vector
     * @param max max value of the vector
     * @return the generated vector
     */
    std::pmr::vector<size_t> generate_sorted_vector(size_t size, std::pmr::memory_resource* raw_arena);
    
    /**
     * @brief Generate a vector of reverse sorted number values
     * 
     * @param size size of the vector
     * @param max max value of the vector
     * @return the generated vector
     */
    std::pmr::vector<size_t> generated_reverse_sorted_vector(size_t size);

    /**
     * @brief Generate a vector of reverse sorted number values using existing arena
     * 
     * @param size size of the vector
     * @param max max value of the vector
     * @return the generated vector
     */
    std::pmr::vector<size_t> generated_reverse_sorted_vector(size_t size, std::pmr::memory_resource* raw_arena);

    // ===========================================================================
    //       			   LINKED LISTS GENERATORS
    // ===========================================================================

    /**
     * @brief Generate a linked list of random number values
     * 
     * @param size size of the linked list
     * @param max max value of the linked list
     * @return the generated linked list
     */
    template <typename ArenaType>
    LinkedList generate_random_linked_list(size_t size, size_t max);

    /**
     * @brief Generate a linked list of random number values using an existing arena
     * 
     * @param size size of the linked list
     * @param max max value of the linked list
     * @return the generated linked list
     */
    template <typename ArenaType>
    LinkedList generate_random_linked_list(size_t size, size_t max, std::pmr::memory_resource* raw_arena);
    
    /**
     * @brief Generate a linked list of sorted number values
     * 
     * @param size size of the linked list
     * @param max max value of the linked list
     * @return the generated linked list
     */
    template <typename ArenaType>
    LinkedList generate_sorted_linked_list(size_t size);
    
    /**
     * @brief Generate a linked list of sorted number values using an existant arena
     * 
     * @param size size of the linked list
     * @param max max value of the linked list
     * @return the generated linked list
     */
    template <typename ArenaType>
    LinkedList generate_sorted_linked_list(size_t size, std::pmr::memory_resource* raw_arena);
    
    /**
     * @brief Generate a linked list of reverse sorted number values
     * 
     * @param size size of the linked list
     * @param max max value of the linked list
     * @return the generated linked list
     */
    template <typename ArenaType>
    LinkedList generate_reverse_sorted_linked_list(size_t size);

    /**
     * @brief Generate a linked list of reverse sorted number values using an existant arena
     * 
     * @param size size of the linked list
     * @param max max value of the linked list
     * @return the generated linked list
     */
    template <typename ArenaType>
    LinkedList generate_reverse_sorted_linked_list(size_t size, std::pmr::memory_resource* raw_arena);
}

#include "generate_linkedlists.impl.hpp"