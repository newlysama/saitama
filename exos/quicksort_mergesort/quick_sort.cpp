#include "quick_sort.hh"

/*
 *  ============================= LINKED LISTS =============================
*/

void quick_sort_lomuto(std::unique_ptr<LinkedList>& list) {
    if (list->size <= 1) return list;

    size_t pivot_index = list->partition_lomuto(0, list->size - 1);

    auto [left, pivot, right] = LinkedList::split_around_pivot(std::move(list), pivot_index);
    auto left_sorted = quick_sort_lomuto(std::move(left));
    auto right_sorted = quick_sort_lomuto(std::move(right));

    LinkedList::concat(LinkedList::concat(left_sorted, pivot), right_sorted);
}

void quick_sort_hoare(std::unique_ptr<LinkedList>& list, size_t low, size_t high) {
    if (low >= high) {
        return;
    }

    size_t pivot_index = list->partition_hoare(low, high);

    quick_sort_hoare(list, low, pivot_index);
    quick_sort_hoare(list, pivot_index + 1, high);
}

/*
 *  ============================= VECTORS =============================
*/

void quick_sort_lomuto(std::vector<size_t>& list, size_t low, size_t high) {

    if (list.size() <= 1 || low >= high) {
        return;
    }

    size_t pivot_index = partition_lomuto(list, low, high);

    if (pivot_index > 0)
        quick_sort_lomuto(list, low, pivot_index - 1);
    quick_sort_lomuto(list, pivot_index + 1, high);
}

void quick_sort_hoare(std::vector<size_t>& list, size_t low, size_t high) {
    if (list.size() <= 1) return;

    if (low < high) {
        size_t pivot_index = partition_hoare(list, low, high);

        quick_sort_hoare(list, low, pivot_index);
        quick_sort_hoare(list, pivot_index + 1, high);
    }
}
