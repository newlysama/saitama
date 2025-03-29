#include <cassert>

#include <linked_lists/linked_lists.hh>
#include <logger/logger.hh>

void test_get_first_element() {
    LinkedList list({10, 20, 30});
    Node* n = list.get(0);
    assert(n != nullptr);
    assert(n->value == 10);
    Logger::def("test_get_first_element passed.");
}

void test_get_middle_element() {
    LinkedList list({10, 20, 30});
    Node* n = list.get(1);
    assert(n != nullptr);
    assert(n->value == 20);
    Logger::def("test_get_middle_element passed.");
}

void test_get_last_element() {
    LinkedList list({10, 20, 30});
    Node* n = list.get(2);
    assert(n != nullptr);
    assert(n->value == 30);
    Logger::def("test_get_last_element passed.");
}

void test_get_out_of_bounds_throws() {
    LinkedList list({1, 2, 3});
    bool exception_thrown = false;

    try {
        list.get(10);
    } catch (const std::invalid_argument& e) {
        exception_thrown = true;
    }

    assert(exception_thrown);
    Logger::def("test_get_out_of_bounds_throws passed.");
}
