#pragma once

#define TBB_PREVIEW_MEMORY_POOL 1

#include <memory>
#include <vector>
#include <cstddef>

#include <tbb/memory_pool.h>
#include <tbb/scalable_allocator.h>
#include <iostream>

/**
 * @brief MemoryManager handles allocation strategies for high-performance systems.
 *
 * It provides two types of memory arenas:
 * - FixedArena: preallocated memory pool using custom bump allocator
 * - ScalableArena: dynamically allocated memory using TBB scalable_allocator
 *
 * This manager is implemented as a singleton.
 */
class MemoryManager {
public:
    /**
     * @brief A memory arena with preallocated fixed-size buffer using custom bump allocator's implementation.
     *
     * This arena is designed for predictable memory usage and fast allocation.
     * Memory is allocated in O(1), but CANNOT be released, we can only override it.
     * 
     * [WARNING]
     * 
     * This method is not thread safe, as current can point to the same ptr within 2 different threads, leading to
     * memory overriding when allocating.
     * Using this bump allocator within threads requires knowing in advance that concurrent threads will not interfeer with
     * with each other.
     */
    struct FixedArena {
        public:
            /**
             * @brief Constructs a FixedArena with a given buffer size.
             * @param size Number of bytes to preallocate.
             */
            FixedArena(size_t size);

            /**
             * @brief Allocate a sub-chunk within the buffer's arena
             * @param size Number of bytes to allocate
             * @return Pointer to allocated memory within the buffer, or nullptr if out of space
             */
            void* allocate(size_t size);

            /**
             * @brief Simply put back current at buffer, allowing to override existing stored datas
             */
            void reset();

        private:
            std::unique_ptr<char[]> buffer; // Pre-allocated memory chunk
            char* current; // Pointer to the next free byte in the buffer
            size_t size; // Total size of the buffer in bytes
    };

    /**
     * @brief A dynamic memory allocator using TBB's scalable_allocator.
     * Provides STL-compatible allocation with dynamic behavior.
     */
    struct ScalableArena {
        /**
         * @brief Default constructor.
         */
        ScalableArena() = default;

        /**
         * @brief Returns a TBB scalable allocator for a specific type.
         * @tparam T Type to allocate.
         * @return Scalable allocator instance.
         */
        template <typename T>
        tbb::scalable_allocator<T> get_allocator() const;

        /**
         * @brief Allocates memory for n elements of type T.
         * @tparam T Type to allocate.
         * @param n Number of elements (defaults to 1).
         * @return Pointer to allocated memory.
         */
        template <typename T>
        T* allocate(size_t n = 1);

        /**
         * @brief Deallocates memory allocated for n elements of type T.
         * @tparam T Type to deallocate.
         * @param ptr Pointer to the memory to deallocate.
         * @param n Number of elements (defaults to 1).
         */
        template <typename T>
        void deallocate(T* ptr, size_t n = 1);
    };

    /**
     * @brief Returns the singleton instance of the MemoryManager.
     * @return Reference to the manager.
     */
    static MemoryManager& instance();

    /**
     * @brief Creates and registers a new fixed-size arena.
     * @param size Number of bytes to preallocate.
     * @return Shared pointer to the created FixedArena.
     */
    std::shared_ptr<FixedArena> create_fixed_arena(size_t size);

    /**
     * @brief Creates and registers a new scalable arena.
     * @return Shared pointer to the created ScalableArena.
     */
    std::shared_ptr<ScalableArena> create_scalable_arena();

    /**
     * @brief Reset all registered fixed arenas.
     */
    void reset_fixed();

    /**
     * @brief Clears all registered arenas (both fixed and scalable).
     */
    void hard_reset();

private:
    MemoryManager() = default;

    std::vector<std::shared_ptr<FixedArena>> fixed_arenas;     ///< All active fixed arenas
    std::vector<std::shared_ptr<ScalableArena>> scalable_arenas; ///< All active scalable arenas
};

#include "scalable_arena.impl.hpp"