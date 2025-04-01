#include "vector_utils.hh"

size_t VectorUtils::partition_lomuto(std::vector<size_t>& list, size_t low, size_t high) {
    if (low >= high || high >= list.size()) {
        std::ostringstream oss;
        oss << "VectorUtils::partition_lomuto() : invalid indices.";
        oss << "Got low : " << low << " || " << "high : " << high;
        throw std::invalid_argument(oss.str());
    }

    size_t pivot = list[high];
    std::ptrdiff_t i = static_cast<std::ptrdiff_t>(low) - 1;

    for (std::ptrdiff_t j = low; j <= static_cast<std::ptrdiff_t>(high) - 1; j++) {
        if (list[j] <= pivot) {
            i++;
            std::swap(list[i], list[j]);
        }
    }

    std::swap(list[i + 1], list[high]);

    return i + 1;
}

size_t VectorUtils::partition_hoare(std::vector<size_t>& list, size_t low, size_t high) {
    if (low >= high || high >= list.size()) {
        std::ostringstream oss;
        oss << "VectorUtils::partition_hoare() : invalid indices.";
        oss << "Got low : " << low << " || " << "high : " << high;
        throw std::invalid_argument(oss.str());
    }

    size_t pivot = list[low];
    std::ptrdiff_t i = static_cast<std::ptrdiff_t>(low) - 1;
    std::ptrdiff_t j = static_cast<std::ptrdiff_t>(high) + 1;

    while (true) {
        do { i++; } while (list[i] < pivot);
        do { j--; } while (list[j] > pivot);

        if (i >= j)
            return j;

        std::swap(list[i], list[j]);
    }
}