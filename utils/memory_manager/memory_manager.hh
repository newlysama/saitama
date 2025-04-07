#pragma once

#include <memory>
#include <memory_resource>


/**
 * @brief Class implementing a dynamic arena memory manager with multiple independent memory pools
 *
 * @details This manager allows the creation of multiple independent, heap-allocated arenas (buffers), each managed
 * by a std::pmr::monotonic_buffer_resource (implementation of memory_ressource interface).
 * These arenas are pre-allocated at runtime and can be used to back polymorphic containers such as std::pmr::vector, std::pmr::list, etc...
 *
 * Key advantages:
 * - Allows to create multiple dynamic-size memory pools (no hardcoded limit)
 * - All allocations are done in a contiguous chunk, enabling good cache locality
 * - Node need to allocate anythin, since everything is pre-allocated, and deallocation is instantaneous (via release())
 * - One single manager controls all arenas (ensures scalability among other things)
 *
 * Example usage:
 *
 * auto arena = MemoryManager::instance().create_arena(1024 * 1024); // 1 MB arena
 * std::pmr::vector<int> v(arena.get());
 * v.push_back(42);
 */
class MemoryManager {
    private:
        /**
         * @brief Arena structure
         * Sotores a memory buffer of dynamic size (defined at runtime)
         */
        struct Arena {
            std::unique_ptr<char[]> buffer;

            // Instance of monotic_buffer_ressource implementing the memory_resource interface
            std::unique_ptr<std::pmr::monotonic_buffer_resource> resource;
            std::size_t size;
    
            Arena(std::size_t s)
                : buffer(std::make_unique<char[]>(s))
                , resource(std::make_unique<std::pmr::monotonic_buffer_resource>(buffer.get(), s))
                ,  size(s) 
                {}
            
            void release() noexcept {
                this->resource->release();
            }
        };
    
        // Vector of our arenas
        // Use shared pointers to keep track of them
        std::vector<std::shared_ptr<Arena>> arenas;
    
        /**
         * @brief Instantiate MemoryManager
         * Private to ensure it is called only from our instance() method
         */
        MemoryManager() = default;
    
    public:
        // Prevent the copy of MemoryManager instances 
        MemoryManager(const MemoryManager&) = delete;
        MemoryManager& operator=(const MemoryManager&) = delete;

        /**
         * @brief Create a new MemoryManager instance
         * Singleton pattern
         * Prevent from creating multiple MemoryManager instances
         * Ensures to have 1 entry point for our memory managment
         * @return MemoryManager& 
         */
        static MemoryManager& instance() {
            static MemoryManager manager;
            return manager;
        }
    
        /**
         * @brief Create a new memory arena of a given size
         * @param size Size of the buffer to pre-allocate (in bytes)
         * @return A polymorphic memory_resource pointer to be used with PMR containers
         */
        std::shared_ptr<std::pmr::memory_resource> create_arena(std::size_t size) {
            auto arena = std::make_shared<Arena>(size);
            arenas.push_back(arena);
            return std::shared_ptr<std::pmr::memory_resource>(arena, arena->resource.get());
        }

        /**
         * @brief Release a given arena
         * @param released_arena the arena to release
         */
        void release_arena(std::pmr::memory_resource* released_arena) {
            for (auto& arena : arenas) {
                if (arena->resource.get() == released_arena) {
                    arena->release();
                    break;
                }
            }
        }

        /**
         * @brief Reset all arenas instances
         */
        void reset_all() {
            for (auto& arena : arenas) {
                arena->resource->release();
            }
        }
};