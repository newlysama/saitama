#include <cassert>

#include <linked_lists/linked_lists.hh>
#include <quicksort_mergesort/merge_sort.hh>
#include <logger/logger.hh>

/*
 * VECTOR FUNCTIONS
 */

void test_vector_split_even_size() {
    std::vector<size_t> input = {1, 2, 3, 4};
    auto [left, right] = split(input);
    assert(left == std::vector<size_t>({1, 2}));
    assert(right == std::vector<size_t>({3, 4}));
    Logger::success("test_vector_split_even_size passed.");
}

void test_vector_split_odd_size() {
    std::vector<size_t> input = {10, 20, 30, 40, 50};
    auto [left, right] = split(input);
    assert(left == std::vector<size_t>({10, 20}));
    assert(right == std::vector<size_t>({30, 40, 50}));
    Logger::success("test_vector_split_odd_size passed.");
}

void test_vector_split_empty_throws() {
    bool threw = false;
    try {
        split({});
    } catch (const std::invalid_argument&) {
        threw = true;
    }
    assert(threw);
    Logger::success("test_vector_split_empty_throws passed.");
}

void test_vector_merge_sorted_inputs() {
    std::vector<size_t> a = {1, 3, 5};
    std::vector<size_t> b = {2, 4, 6};
    std::vector<size_t> merged = merge(a, b);
    assert(merged == std::vector<size_t>({1, 2, 3, 4, 5, 6}));
    Logger::success("test_vector_merge_sorted_inputs passed.");
}

void test_vector_merge_with_duplicates() {
    std::vector<size_t> a = {1, 2, 2};
    std::vector<size_t> b = {2, 3};
    std::vector<size_t> merged = merge(a, b);
    assert(merged == std::vector<size_t>({1, 2, 2, 2, 3}));
    Logger::success("test_vector_merge_with_duplicates passed.");
}

void test_vector_merge_sort_unsorted_input() {
    std::vector<size_t> input = {5, 1, 4, 2, 3};
    std::vector<size_t> sorted = merge_sort(input);
    assert(sorted == std::vector<size_t>({1, 2, 3, 4, 5}));
    Logger::success("test_vector_merge_sort_unsorted_input passed.");
}

void test_vector_merge_sort_stability_and_duplicates() {
    std::vector<size_t> input = {4, 2, 2, 4, 1};
    std::vector<size_t> sorted = merge_sort(input);
    assert(sorted == std::vector<size_t>({1, 2, 2, 4, 4}));
    Logger::success("test_vector_merge_sort_stability_and_duplicates passed.");
}

/*
 * LINKED LISTS
 */

void test_linkedlist_merge_sort_already_sorted() {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{1, 2, 3, 4, 5});
    auto sorted = merge_sort(std::move(list));
    for (size_t i = 0; i < 5; ++i) {
        assert(sorted->get(i)->value == i + 1);
    }
    assert(sorted->first->value == 1);
    assert(sorted->last->value == 5);
    Logger::success("test_linkedlist_merge_sort_already_sorted passed.");
}

void test_linkedlist_merge_sort_reverse_order() {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{5, 4, 3, 2, 1});
    auto sorted = merge_sort(std::move(list));
    for (size_t i = 0; i < 5; ++i) {
        assert(sorted->get(i)->value == i + 1);
    }
    assert(sorted->first->value == 1);
    assert(sorted->last->value == 5);
    Logger::success("test_linkedlist_merge_sort_reverse_order passed.");
}

void test_linkedlist_merge_sort_with_duplicates() {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{4, 2, 2, 3, 1});
    auto sorted = merge_sort(std::move(list));
    std::vector<size_t> expected = {1, 2, 2, 3, 4};
    for (size_t i = 0; i < expected.size(); ++i) {
        assert(sorted->get(i)->value == expected[i]);
    }
    assert(sorted->first->value == 1);
    assert(sorted->last->value == 4);
    Logger::success("test_linkedlist_merge_sort_with_duplicates passed.");
}

void test_linkedlist_merge_sort_single_element() {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{42});
    auto sorted = merge_sort(std::move(list));
    assert(sorted->size == 1);
    assert(sorted->first->value == 42);
    assert(sorted->last->value == 42);
    Logger::success("test_linkedlist_merge_sort_single_element passed.");
}

void test_linkedlist_merge_sort_empty_list() {
    auto list = std::make_unique<LinkedList>();
    auto sorted = merge_sort(std::move(list));
    assert(sorted->empty());
    assert(sorted->first == nullptr);
    assert(sorted->last == nullptr);
    Logger::success("test_linkedlist_merge_sort_empty_list passed.");
}
