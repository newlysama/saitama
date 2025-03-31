#include <cassert>

#include <linked_lists/linked_lists.hh>
#include <logger/logger.hh>

void test_init_from_empty_vector() {
    std::vector<size_t> input = {};
    LinkedList list(input);
    assert(list.empty());
    assert(list.size == 0);
    assert(list.last == nullptr);
    Logger::def("test_init_from_empty_vector passed.");
}

void test_init_from_vector_single_element() {
    std::vector<size_t> input = {42};
    LinkedList list(input);
    assert(!list.empty());
    assert(list.size == 1);
    assert(list.get(0)->value == 42);
    assert(list.get(0) == list.last);
    assert(list.get(0)->prev == nullptr);
    Logger::def("test_init_from_vector_single_element passed.");
}

void test_init_from_vector_multiple_elements() {
    std::vector<size_t> input = {1, 2, 3, 4, 5};
    LinkedList list(input);
    assert(!list.empty());
    assert(list.size == input.size());

    Node* current = list.first.get();
    for (size_t i = 0; i < input.size(); ++i) {
        assert(current->value == input[i]);
        if (i == 0) {
            assert(current->prev == nullptr);
        } else {
            assert(current->prev != nullptr);
            assert(current->prev->value == input[i - 1]);
        }
        current = current->next.get();
    }

    assert(list.last->value == input.back());
    assert(list.last->prev->value == input[input.size() - 2]);

    Logger::def("test_init_from_vector_multiple_elements passed.");
}