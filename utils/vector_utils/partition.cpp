#include "vector_utils.hh"
#include "exos/quicksort_mergesort/pivot.hh"

using ScalableVector = std::vector<size_t, tbb::scalable_allocator<size_t>>;

/**
 * @brief Chose which pivot strategy to use, depending on the defined maccros in 'exos/quicksort_mergesort/pivot.hh'
 * @param low 
 * @param high 
 * @return size_t 
 */
static size_t chose_pivot(size_t low, size_t high) {
    #if PIVOT == RANDOM
        return low + rand() % (high - low + 1);
    #elif PIVOT == FIRST
        (void)high;
        return low;
    #elif PIVOT == LAST
        (void)low;
        return high;
    #elif PIVOT == MID
        return (low + high) / 2;
    #else
        throw std::invalid_argument("Unknown pivot strategy for quicksort.");
    #endif
}


size_t VectorUtils::partition_lomuto(ScalableVector& vector, size_t low, size_t high) {
    if (low >= high || high >= vector.size()) {
        std::ostringstream oss;
        oss << "VectorUtils::partition_lomuto() : invalid indices.";
        oss << "Got low : " << low << " || " << "high : " << high;
        throw std::invalid_argument(oss.str());
    }

    // Get the pivot and swap its place with vector[high]
    // since lomuto's partition works with pivot at high place
    size_t pivot_index = chose_pivot(low, high);
    std::swap(vector[pivot_index], vector[high]);
    size_t pivot = vector[high];

    std::ptrdiff_t i = static_cast<std::ptrdiff_t>(low) - 1;

    for (std::ptrdiff_t j = low; j <= static_cast<std::ptrdiff_t>(high) - 1; j++) {
        if (vector[j] <= pivot) {
            i++;
            std::swap(vector[i], vector[j]);
        }
    }

    std::swap(vector[i + 1], vector[high]);

    return i + 1;
}

size_t VectorUtils::partition_hoare(ScalableVector& vector, size_t low, size_t high) {
    if (low >= high || high >= vector.size()) {
        std::ostringstream oss;
        oss << "VectorUtils::partition_hoare() : invalid indices.";
        oss << "Got low : " << low << " || " << "high : " << high;
        throw std::invalid_argument(oss.str());
    }

    // Get the pivot and swap its place with vector[low]
    // since hoare's partition works with pivot at low place
    size_t pivot_index = chose_pivot(low, high);
    std::swap(vector[pivot_index], vector[high]);
    size_t pivot = vector[high];

    std::ptrdiff_t i = static_cast<std::ptrdiff_t>(low) - 1;
    std::ptrdiff_t j = static_cast<std::ptrdiff_t>(high) + 1;

    while (true) {
        do { i++; } while (vector[i] < pivot);
        do { j--; } while (vector[j] > pivot);

        if (i >= j)
            return j;

        std::swap(vector[i], vector[j]);
    }
}