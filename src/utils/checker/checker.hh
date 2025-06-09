#pragma once

#include <sstream>
#include <exception>

/**
 * @brief Namespace implementing various checking functions
 */
namespace Checker {

    /**
     * @brief Check if a given ptr is nullptr
     * @param ptr the ptr to check
     * @param function the function in which it's called
     * @param index index of the ptr (if we work with indexed containers)
     */
    template <typename T>
    void check_access_nullptr(T* ptr, const std::string& function, std::optional<size_t> index = std::nullopt) {
        if (!ptr) {
            std::ostringstream oss;
            oss << function << " : trying to access nullptr";

            if (index.has_value()) {
                oss << " at index : " << index.value();
            } else {
                oss << ".";
            }
            
            throw std::logic_error(oss.str());
        }
    }

    /**
     * @brief Check that index is not out of bounds
     * @param function the function which calls it
     * @param index the tested index
     * @param container size of the tested container
     */
    inline void check_index(const std::string& function, size_t index, size_t container_size) {
        if (index >= container_size) {
            std::ostringstream oss;
            oss << function << " : required index is out of bounds : " << index;
            throw std::invalid_argument(oss.str());
        }
    }
}