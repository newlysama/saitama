#include <cassert>
#include <algorithm>

#include <linked_lists/linked_lists.hh>
#include <logger/logger.hh>
#include <quicksort_mergesort/quick_sort.hh>

/*
 *  ============================= VECTORS =============================
 */

void test_partition_lomuto_basic() {
    std::vector<size_t> list = {3, 2, 1, 5, 4};
    size_t pivot_index = partition_lomuto(list, 0, list.size() - 1);
    for (size_t i = 0; i < pivot_index; ++i) {
        assert(list[i] <= list[pivot_index]);
    }
    for (size_t i = pivot_index + 1; i < list.size(); ++i) {
        assert(list[i] > list[pivot_index]);
    }
    Logger::def("test_partition_lomuto_basic passed.");
}

void test_partition_lomuto_sorted_input() {
    std::vector<size_t> list = {1, 2, 3, 4, 5};
    size_t pivot_index = partition_lomuto(list, 0, list.size() - 1);
    for (size_t i = 0; i < pivot_index; ++i) {
        assert(list[i] <= list[pivot_index]);
    }
    for (size_t i = pivot_index + 1; i < list.size(); ++i) {
        assert(list[i] > list[pivot_index]);
    }
    Logger::def("test_partition_lomuto_sorted_input passed.");
}

void test_partition_lomuto_duplicates() {
    std::vector<size_t> list = {3, 1, 2, 3, 1};
    size_t pivot_index = partition_lomuto(list, 0, list.size() - 1);
    for (size_t i = 0; i < pivot_index; ++i) {
        assert(list[i] <= list[pivot_index]);
    }
    for (size_t i = pivot_index + 1; i < list.size(); ++i) {
        assert(list[i] > list[pivot_index]);
    }
    Logger::def("test_partition_lomuto_duplicates passed.");
}


void test_quick_sort_vector_lomuto_sorted_input() {
    std::vector<size_t> vec = {1, 2, 3, 4, 5};
    std::vector<size_t> expected = vec;

    quick_sort_lomuto(vec, 0, vec.size() - 1);
    assert(vec == expected);
    Logger::def("test_quick_sort_vector_lomuto_sorted_input passed.");
}

void test_quick_sort_vector_lomuto_reverse_input() {
    std::vector<size_t> vec = {5, 4, 3, 2, 1};
    std::vector<size_t> expected = {1, 2, 3, 4, 5};

    quick_sort_lomuto(vec, 0, vec.size() - 1);
    assert(vec == expected);
    Logger::def("test_quick_sort_vector_lomuto_reverse_input passed.");
}

void test_quick_sort_vector_lomuto_with_duplicates() {
    std::vector<size_t> vec = {3, 1, 2, 3, 1};
    std::vector<size_t> expected = {1, 1, 2, 3, 3};

    quick_sort_lomuto(vec, 0, vec.size() - 1);
    assert(vec == expected);
    Logger::def("test_quick_sort_vector_lomuto_with_duplicates passed.");
}

void test_quick_sort_vector_lomuto_random() {
    std::vector<size_t> vec = {42, 5, 7, 19, 3};
    std::vector<size_t> expected = vec;
    std::sort(expected.begin(), expected.end());

    quick_sort_lomuto(vec, 0, vec.size() - 1);
    assert(vec == expected);
    Logger::def("test_quick_sort_vector_lomuto_random passed.");
}

/*
 *  ============================= LINKED LISTS =============================
 */

void test_quick_sort_lomuto_empty_list() {
    auto list = std::make_unique<LinkedList>();
    auto sorted = quick_sort_lomuto(std::move(list));
    assert(sorted->empty());
    Logger::def("test_quick_sort_lomuto_empty_list passed.");
}

void test_quick_sort_lomuto_single_element() {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{42});
    auto sorted = quick_sort_lomuto(std::move(list));
    assert(sorted->size == 1);
    assert(sorted->get(0)->value == 42);
    Logger::def("test_quick_sort_lomuto_single_element passed.");
}

void test_quick_sort_lomuto_sorted_input() {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{1, 2, 3, 4, 5});
    auto sorted = quick_sort_lomuto(std::move(list));
    for (size_t i = 0; i < 5; ++i) {
        assert(sorted->get(i)->value == i + 1);
    }
    Logger::def("test_quick_sort_lomuto_sorted_input passed.");
}

void test_quick_sort_lomuto_reverse_input() {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{5, 4, 3, 2, 1});
    auto sorted = quick_sort_lomuto(std::move(list));
    for (size_t i = 0; i < 5; ++i) {
        assert(sorted->get(i)->value == i + 1);
    }
    Logger::def("test_quick_sort_lomuto_reverse_input passed.");
}

void test_quick_sort_lomuto_duplicates() {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{3, 1, 2, 3, 1});
    auto sorted = quick_sort_lomuto(std::move(list));
    std::vector<size_t> expected = {1, 1, 2, 3, 3};
    for (size_t i = 0; i < expected.size(); ++i) {
        assert(sorted->get(i)->value == expected[i]);
    }
    Logger::def("test_quick_sort_lomuto_duplicates passed.");
}

void test_quick_sort_lomuto_random_input() {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{10, 2, 33, 4, 1});
    auto sorted = quick_sort_lomuto(std::move(list));
    std::vector<size_t> expected = {1, 2, 4, 10, 33};
    for (size_t i = 0; i < expected.size(); ++i) {
        assert(sorted->get(i)->value == expected[i]);
    }
    Logger::def("test_quick_sort_lomuto_random_input passed.");
}