#include <cassert>

#include <linked_lists/linked_lists.hh>
#include <logger/logger.hh>

// Helper functions to check if elements are partitioned correctly around pivot
bool is_partitioned_lomuto(LinkedList& list, size_t pivot_index) {
    size_t pivot = list.get(pivot_index)->value;
    for (size_t i = 0; i < pivot_index; ++i)
        if (list.get(i)->value > pivot)
            return false;
    for (size_t i = pivot_index + 1; i < list.size; ++i)
        if (list.get(i)->value < pivot)
            return false;
    return true;
}

// Also checks if the elements are partitionned correctly around split_index
bool is_partitioned_hoare(LinkedList& list, size_t left, size_t right, size_t pivot, size_t split_index) {
    for (size_t i = left; i <= split_index; ++i) {
        if (list.get(i)->value > pivot) return false;
    }

    for (size_t i = split_index + 1; i <= right; ++i) {
        if (list.get(i)->value < pivot) return false;
    }

    return true;
}


// ====================
//    Lomuto tests
// ====================

void test_partition_lomuto_basic_case() {
    LinkedList list({9, 3, 7, 1, 5});
    size_t pivot_index = list.partition_lomuto(0, list.size - 1);
    assert(pivot_index < list.size);
    assert(is_partitioned_lomuto(list, pivot_index));
    Logger::def("test_partition_lomuto_basic_case passed.");
}

void test_partition_lomuto_sorted_list() {
    LinkedList list({1, 2, 3, 4, 5});
    size_t pivot_index = list.partition_lomuto(0, list.size - 1);
    assert(is_partitioned_lomuto(list, pivot_index));
    Logger::def("test_partition_lomuto_sorted_list passed.");
}

void test_partition_lomuto_reverse_list() {
    LinkedList list({5, 4, 3, 2, 1});
    size_t pivot_index = list.partition_lomuto(0, list.size - 1);
    assert(is_partitioned_lomuto(list, pivot_index));
    Logger::def("test_partition_lomuto_reverse_list passed.");
}

// ====================
//    Hoare tests
// ====================

void test_partition_hoare_basic_case() {
    LinkedList list({5, 1, 8, 2, 9});
    size_t pivot = list.get(0)->value;
    size_t split_index = list.partition_hoare(0, list.size - 1);
    assert(is_partitioned_hoare(list, 0, list.size - 1, pivot, split_index));
    Logger::def("test_partition_hoare_basic_case passed.");
}

void test_partition_hoare_sorted_list() {
    LinkedList list({1, 2, 3, 4, 5});
    size_t pivot = list.get(0)->value;
    size_t split_index = list.partition_hoare(0, list.size - 1);
    assert(is_partitioned_hoare(list, 0, list.size - 1, pivot, split_index));
    Logger::def("test_partition_hoare_sorted_list passed.");
}

void test_partition_hoare_reverse_list() {
    LinkedList list({5, 4, 3, 2, 1});
    size_t pivot = list.get(0)->value;
    size_t split_index = list.partition_hoare(0, list.size - 1);
    assert(is_partitioned_hoare(list, 0, list.size - 1, pivot, split_index));
    Logger::def("test_partition_hoare_reverse_list passed.");
}
