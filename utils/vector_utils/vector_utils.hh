#include <vector>
#include <sstream>
#include <cuchar>
#include <exception>
#include <numeric>

class VectorUtils {
    public:
        // Split two vectors (no shit)
        static std::tuple<std::vector<std::size_t>, std::vector<std::size_t>> split(std::vector<std::size_t> list);

        // Merge two vectors
        static std::vector<std::size_t> merge(std::vector<std::size_t> list1, std::vector<std::size_t> list2);

        // Lomuto's partition algorithm
        static size_t partition_lomuto(std::vector<size_t>& list, size_t low, size_t high);

        // Hoare's partition algorithm
        static size_t partition_hoare(std::vector<size_t>& list, size_t low, size_t high);
};