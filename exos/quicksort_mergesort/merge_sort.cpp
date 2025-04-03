#include "merge_sort.hh"

void merge_sort(LinkedList& list) {
    if (list.size <= 1) {
        return;
    }

    auto splited = LinkedListAlgorithm::split(list);
    auto left = std::get<0>(std::move(splited));
    auto right = std::get<1>(std::move(splited));

    merge_sort(left);
    merge_sort(right);

    LinkedListAlgorithm::merge(left, right);

    // Regive ownership to list, since it's been transfered to left
    list = std::move(left);
}


std::vector<std::size_t> merge_sort(std::vector<size_t> list) {
    if (list.size() <= 1) {
        return list;
    }

    auto splited = VectorUtils::split(list);
    auto left = std::get<0>(splited);
    auto right = std::get<1>(splited);

    return VectorUtils::merge(merge_sort(left), merge_sort(right));
}
