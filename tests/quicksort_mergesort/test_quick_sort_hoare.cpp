#include <cassert>
#include <algorithm>

#include <linked_lists/linked_lists.hh>
#include <logger/logger.hh>
#include <quicksort_mergesort/quick_sort.hh>

/*
 *  ============================= VECTORS =============================
 */

void test_partition_hoare_basic() {
    std::vector<size_t> list = {4, 2, 7, 1, 9};
    size_t split = partition_hoare(list, 0, list.size() - 1);
    size_t pivot = list[split];
    for (size_t i = 0; i <= split; ++i) {
        assert(list[i] <= pivot);
    }
    for (size_t i = split + 1; i < list.size(); ++i) {
        assert(list[i] >= pivot);
    }
    Logger::def("test_partition_hoare_basic passed.");
}

void test_partition_hoare_sorted() {
    std::vector<size_t> list = {1, 2, 3, 4, 5};
    size_t split = partition_hoare(list, 0, list.size() - 1);
    size_t pivot = list[split];
    for (size_t i = 0; i <= split; ++i) {
        assert(list[i] <= pivot);
    }
    for (size_t i = split + 1; i < list.size(); ++i) {
        assert(list[i] >= pivot);
    }
    Logger::def("test_partition_hoare_sorted passed.");
}

void test_partition_hoare_duplicates() {
    std::vector<size_t> list = {3, 3, 3, 3, 3};
    size_t split = partition_hoare(list, 0, list.size() - 1);
    size_t pivot = list[split];
    for (size_t i = 0; i <= split; ++i) {
        assert(list[i] <= pivot);
    }
    for (size_t i = split + 1; i < list.size(); ++i) {
        assert(list[i] >= pivot);
    }
    Logger::def("test_partition_hoare_duplicates passed.");
}

void test_quick_sort_vector_hoare_sorted_input() {
    std::vector<size_t> vec = {1, 2, 3, 4, 5};
    std::vector<size_t> expected = vec;

    quick_sort_hoare(vec, 0, vec.size() - 1);
    assert(vec == expected);
    Logger::def("test_quick_sort_vector_hoare_sorted_input passed.");
}

void test_quick_sort_vector_hoare_reverse_input() {
    std::vector<size_t> vec = {5, 4, 3, 2, 1};
    std::vector<size_t> expected = {1, 2, 3, 4, 5};

    quick_sort_hoare(vec, 0, vec.size() - 1);
    assert(vec == expected);
    Logger::def("test_quick_sort_vector_hoare_reverse_input passed.");
}

void test_quick_sort_vector_hoare_with_duplicates() {
    std::vector<size_t> vec = {4, 1, 2, 4, 2};
    std::vector<size_t> expected = {1, 2, 2, 4, 4};

    quick_sort_hoare(vec, 0, vec.size() - 1);
    assert(vec == expected);
    Logger::def("test_quick_sort_vector_hoare_with_duplicates passed.");
}

void test_quick_sort_vector_hoare_random() {
    std::vector<size_t> vec = {9, 7, 2, 6, 3};
    std::vector<size_t> expected = vec;
    std::sort(expected.begin(), expected.end());

    quick_sort_hoare(vec, 0, vec.size() - 1);
    assert(vec == expected);
    Logger::def("test_quick_sort_vector_hoare_random passed.");
}

/*
 *  ============================= LINKED LISTS =============================
 */


void test_quick_sort_hoare_empty_list() {
    LinkedList list;
    quick_sort_hoare(list, 0, 0);
    assert(list.empty());
    Logger::def("test_quick_sort_hoare_empty_list passed.");
}

void test_quick_sort_hoare_single_element() {
    LinkedList list({42});
    quick_sort_hoare(list, 0, list.size - 1);
    assert(list.size == 1);
    assert(list.get(0)->value == 42);
    Logger::def("test_quick_sort_hoare_single_element passed.");
}

void test_quick_sort_hoare_sorted_input() {
    LinkedList list({1, 2, 3, 4, 5});
    quick_sort_hoare(list, 0, list.size - 1);
    for (size_t i = 0; i < 5; ++i) {
        assert(list.get(i)->value == i + 1);
    }
    Logger::def("test_quick_sort_hoare_sorted_input passed.");
}

void test_quick_sort_hoare_reverse_input() {
    LinkedList list({5, 4, 3, 2, 1});
    quick_sort_hoare(list, 0, list.size - 1);
    for (size_t i = 0; i < 5; ++i) {
        assert(list.get(i)->value == i + 1);
    }
    Logger::def("test_quick_sort_hoare_reverse_input passed.");
}

void test_quick_sort_hoare_with_duplicates() {
    LinkedList list({4, 2, 2, 4, 3});
    quick_sort_hoare(list, 0, list.size - 1);
    std::vector<size_t> expected = {2, 2, 3, 4, 4};
    for (size_t i = 0; i < expected.size(); ++i) {
        assert(list.get(i)->value == expected[i]);
    }
    Logger::def("test_quick_sort_hoare_with_duplicates passed.");
}

void test_quick_sort_hoare_random_input() {
    LinkedList list({10, 1, 8, 5, 3});
    quick_sort_hoare(list, 0, list.size - 1);
    std::vector<size_t> expected = {1, 3, 5, 8, 10};
    for (size_t i = 0; i < expected.size(); ++i) {
        assert(list.get(i)->value == expected[i]);
    }
    Logger::def("test_quick_sort_hoare_random_input passed.");
}