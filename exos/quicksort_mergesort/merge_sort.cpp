#include "merge_sort.hh"

using namespace LinkedListAlgorithm;
using namespace VectorUtils;
using ScalableVector = std::vector<size_t, tbb::scalable_allocator<size_t>>;

void merge_sort(LinkedList<MemoryManager::FixedArena>& list) {
    if (list.size <= 1) {
        return;
    }

    auto splited = split(list);
    auto left = std::get<0>(std::move(splited));
    auto right = std::get<1>(std::move(splited));

    merge_sort(left);
    merge_sort(right);

    merge(left, right);

    // Move left into list, since merge() mergers into left
    list = std::move(left);
}


ScalableVector merge_sort(ScalableVector vector) {
    if (vector.size() <= 1) {
        return vector;
    }

    auto splited = split(vector);
    auto left = std::get<0>(splited);
    auto right = std::get<1>(splited);

    return merge(merge_sort(left), merge_sort(right));
}
