#include "merge_sort.hh"

/*
 *  ============================= LINKED LISTS =============================
 */

std::unique_ptr<LinkedList> merge_sort(std::unique_ptr<LinkedList> list) {
    if (list->size <= 1) {
        return list;
    }

    auto splited = LinkedList::split(std::move(list));
    auto left = std::move(std::get<0>(splited));
    auto right = std::move(std::get<1>(splited));

    return LinkedList::merge(merge_sort(std::move(left)), merge_sort(std::move(right)));
}

/*
 *  ============================= VECTORS =============================
 */

std::vector<std::size_t> merge_sort(std::vector<size_t> list) {
    if (list.size() <= 1) {
        return list;
    }

    auto splited = VectorUtils::split(list);
    auto left = std::get<0>(splited);
    auto right = std::get<1>(splited);

    return VectorUtils::merge(merge_sort(left), merge_sort(right));
}
