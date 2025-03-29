#include "merge_sort.hh"

/*
*  ============================= LINKED LISTS =============================
*/

std::unique_ptr<LinkedList> merge_sort(std::unique_ptr<LinkedList> list) {
    if (list->empty() || list->size == 1) {
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

std::tuple<std::vector<std::size_t>, std::vector<std::size_t>> split(std::vector<std::size_t> list) {
    std::vector<std::size_t> new_list1;
    std::vector<std::size_t> new_list2;

    if (list.empty()) {
        throw std::invalid_argument("Vector split() : cannot split empty vector.");
    } else if (list.size() == 1) {
        throw std::invalid_argument("Vector split() : cannot split vector of size 1.");
    }

    std::size_t split_index = list.size() / 2;
    std::size_t i = 0;

    while (i < split_index) {
        new_list1.push_back(list[i]);
        i++;
    }

    while (i < list.size()) {
        new_list2.push_back(list[i]);
        i++;
    }

    return std::make_tuple(new_list1, new_list2);
}

std::vector<std::size_t> merge(std::vector<std::size_t> list1, std::vector<std::size_t> list2) {
    if (list1.empty()) {
        return list2;
    } else if (list2.empty()) {
        return list1;
    }

    std::vector<std::size_t> res;
    std::size_t i = 0;
    std::size_t j = 0;
    while (i < list1.size() && j < list2.size()) {
        if (list1[i] <= list2[j]) {
            res.push_back(list1[i++]);
        } else {
            res.push_back(list2[j++]);
        }
    }

    while (i < list1.size()) {
        res.push_back(list1[i++]);
    }

    while (j < list2.size()) {
        res.push_back(list2[j++]);
    }

    return res;
}

std::vector<std::size_t> merge_sort(std::vector<size_t> list) {
    if (list.empty() || list.size() == 1) {
        return list;
    }

    auto splited = split(list);
    auto left = std::get<0>(splited);
    auto right = std::get<1>(splited);

    return merge(merge_sort(left), merge_sort(right));
}
