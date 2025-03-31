#include "quick_sort.hh"

/*
 *  ============================= LINKED LISTS =============================
*/

std::unique_ptr<LinkedList> quick_sort_lomuto(std::unique_ptr<LinkedList> list) {
    if (list->size <= 1) return list;

    size_t pivot_index = list->partition_lomuto(0, list->size - 1);

    auto [left, pivot, right] = LinkedList::split_around_pivot(std::move(list), pivot_index);
    auto left_sorted = quick_sort_lomuto(std::move(left));
    auto right_sorted = quick_sort_lomuto(std::move(right));

    return LinkedList::concat(LinkedList::concat(std::move(left_sorted), std::move(pivot)), std::move(right_sorted));
}

void quick_sort_hoare(LinkedList& list, size_t low, size_t high) {
    if (low >= high) {
        return;
    }

    size_t pivot_index = list.partition_hoare(low, high);

    quick_sort_hoare(list, low, pivot_index);
    quick_sort_hoare(list, pivot_index + 1, high);
}

/*
 *  ============================= VECTORS =============================
*/

size_t partition_lomuto(std::vector<size_t>& list, size_t low, size_t high) {
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

size_t partition_hoare(std::vector<size_t>& list, size_t low, size_t high) {
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
