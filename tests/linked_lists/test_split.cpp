#include <cassert>

#include <linked_lists/linked_lists.hh>
#include <logger/logger.hh>

void test_split_even_length_list_returns_two_equal_parts() {
    auto splited = LinkedList::split(std::make_unique<LinkedList>(std::vector<size_t>{1,2,3,4}));
    auto left = std::move(std::get<0>(splited));
    auto right = std::move(std::get<1>(splited));

    assert(left->size == 2);
    assert(right->size == 2);
    assert(left->get(0)->value == 1);
    assert(left->get(1)->value == 2);
    assert(right->get(0)->value == 3);
    assert(right->get(1)->value == 4);
    Logger::success("test_split_even_length_list_returns_two_equal_parts passed.");
}

void test_split_odd_length_list_returns_correct_sizes() {
    auto splited = LinkedList::split(std::make_unique<LinkedList>(std::vector<size_t>{1,2,3,4,5}));
    auto left = std::move(std::get<0>(splited));
    auto right = std::move(std::get<1>(splited));

    assert(left->size == 2);
    assert(right->size == 3);
    Logger::success("test_split_odd_length_list_returns_correct_sizes passed.");
}

void test_split_empty_list_returns_nullptr() {
    auto splited = LinkedList::split(std::make_unique<LinkedList>());
    assert(std::move(std::get<0>(splited)) == nullptr);
    Logger::success("test_split_empty_list_returns_nullptr passed.");
}

void test_split_single_element_list_returns_nullptr() {
    auto splited = LinkedList::split(std::make_unique<LinkedList>(std::vector<size_t>{42}));
    assert(std::move(std::get<0>(splited)) == nullptr);
    Logger::success("test_split_single_element_list_returns_nullptr passed.");
}

void test_split_preserves_order_in_both_parts() {
    auto splited = LinkedList::split(std::make_unique<LinkedList>(std::vector<size_t>{1,3,5,7}));
    auto left = std::move(std::get<0>(splited));
    auto right = std::move(std::get<1>(splited));

    assert(left->get(0)->value == 1);
    assert(left->get(1)->value == 3);
    assert(right->get(0)->value == 5);
    assert(right->get(1)->value == 7);
    Logger::success("test_split_preserves_order_in_both_parts passed.");
}