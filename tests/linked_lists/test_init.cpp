#include <cassert>

#include <linked_lists/linked_lists.hh>
#include <logger/logger.hh>

void test_init_from_empty_vector() {
    std::vector<size_t> input = {};
    LinkedList list(input);
    assert(list.empty());
    assert(list.size == 0);
    Logger::success("test_init_from_empty_vector passed.");
}

void test_init_from_vector_single_element() {
    std::vector<size_t> input = {42};
    LinkedList list(input);
    assert(!list.empty());
    assert(list.size == 1);
    assert(list.get(0)->value == 42);
    assert(list.get(0) == list.last);
    Logger::success("test_init_from_vector_single_element passed.");
}

void test_init_from_vector_multiple_elements() {
    std::vector<size_t> input = {1, 2, 3, 4, 5};
    LinkedList list(input);
    assert(!list.empty());
    assert(list.size == input.size());
    for (size_t i = 0; i < input.size(); ++i) {
        assert(list.get(i)->value == input[i]);
    }
    assert(list.last->value == input.back());
    Logger::success("test_init_from_vector_multiple_elements passed.");
}
