#include <cassert>

#include <linked_lists/linked_lists.hh>
#include <logger/logger.hh>

void test_concat_two_non_empty_lists() {
    auto list1 = std::make_unique<LinkedList>(std::vector<size_t>{1, 3});
    auto list2 = std::make_unique<LinkedList>(std::vector<size_t>{2, 4});
    auto result = LinkedList::concat(std::move(list1), std::move(list2));
    assert(result->size == 4);
    assert(result->get(0)->value == 1);
    assert(result->get(1)->value == 3);
    assert(result->get(2)->value == 2);
    assert(result->get(3)->value == 4);
    assert(result->last->value == 4);
    Logger::def("test_concat_two_non_empty_lists passed.");
}

void test_concat_with_first_list_empty() {
    auto list1 = std::make_unique<LinkedList>();
    auto list2 = std::make_unique<LinkedList>(std::vector<size_t>{5, 6});
    auto result = LinkedList::concat(std::move(list1), std::move(list2));
    assert(result->size == 2);
    assert(result->get(0)->value == 5);
    assert(result->get(1)->value == 6);
    assert(result->last->value == 6);
    Logger::def("test_concat_with_first_list_empty passed.");
}

void test_concat_with_second_list_empty() {
    auto list1 = std::make_unique<LinkedList>(std::vector<size_t>{7, 8});
    auto list2 = std::make_unique<LinkedList>();
    auto result = LinkedList::concat(std::move(list1), std::move(list2));
    assert(result->size == 2);
    assert(result->get(0)->value == 7);
    assert(result->get(1)->value == 8);
    assert(result->last->value == 8);
    Logger::def("test_concat_with_second_list_empty passed.");
}

void test_concat_with_both_empty_returns_empty_list() {
    auto list1 = std::make_unique<LinkedList>();
    auto list2 = std::make_unique<LinkedList>();
    auto result = LinkedList::concat(std::move(list1), std::move(list2));
    assert(result->empty());
    assert(result->last == nullptr);
    Logger::def("test_concat_with_both_empty_returns_empty_list passed.");
}
