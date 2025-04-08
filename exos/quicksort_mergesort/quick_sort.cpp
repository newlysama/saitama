#include "quick_sort.hh"

using namespace LinkedListAlgorithm;
using namespace VectorUtils;

/*
 *  ============================= LINKED LISTS =============================
*/

void quick_sort_lomuto(LinkedList& list) {
    if (list.size <= 1) return;

    size_t pivot_index = partition_lomuto(list);

    auto splited = split_around_pivot(list, pivot_index);
    
    auto left = std::get<0>(std::move(splited));
    auto pivot = std::get<1>(std::move(splited));
    auto right = std::get<2>(std::move(splited));

    if (left.size > 1) quick_sort_lomuto(left);
    if (right.size > 1) quick_sort_lomuto(right);

    concat(left, pivot);
    concat(left, right);
    
    // Move left into list, since concat() is made in-place into left
    list = std::move(left);
}

void quick_sort_hoare(LinkedList& list) {
    if (list.size <= 1) {
        return;
    }

    size_t pivot_index = partition_hoare(list);

    auto splited = split(list, pivot_index + 1);
    
    auto left = std::get<0>(std::move(splited));
    auto right = std::get<1>(std::move(splited));

    if (left.size > 1) quick_sort_hoare(left);
    if (right.size > 1) quick_sort_hoare(right);

    concat(left, right);

    list = std::move(left);
}

/*
 *  ============================= VECTORS =============================
*/

// Lomuto

void _quick_sort_lomuto(std::pmr::vector<size_t>& list, size_t low, size_t high) {

    if (list.size() <= 1 || low >= high) {
        return;
    }

    size_t pivot_index = partition_lomuto(list, low, high);

    if (pivot_index > 0)
        _quick_sort_lomuto(list, low, pivot_index - 1);
    _quick_sort_lomuto(list, pivot_index + 1, high);
}

void quick_sort_lomuto(std::pmr::vector<size_t>& list) {
    _quick_sort_lomuto(list, 0, list.size() - 1);
}

// Hoare

void _quick_sort_hoare(std::pmr::vector<size_t>& list, size_t low, size_t high) {
    if (list.size() <= 1) return;

    if (low < high) {
        size_t pivot_index = partition_hoare(list, low, high);

        _quick_sort_hoare(list, low, pivot_index);
        _quick_sort_hoare(list, pivot_index + 1, high);
    }
}

void quick_sort_hoare(std::pmr::vector<size_t>& list) {
    _quick_sort_hoare(list, 0, list.size() - 1);
}
