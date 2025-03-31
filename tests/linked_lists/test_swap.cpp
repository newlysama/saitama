#include <cassert>

#include <linked_lists/linked_lists.hh>
#include <logger/logger.hh>

void test_swap_values_two_elements() {
    LinkedList list({1, 2});
    list.swap_values(0, 1);
    assert(list.get(0)->value == 2);
    assert(list.get(1)->value == 1);
    Logger::def("test_swap_values_two_elements passed.");
}

void test_swap_values_middle_elements() {
    LinkedList list({10, 20, 30, 40});
    list.swap_values(1, 2);
    assert(list.get(0)->value == 10);
    assert(list.get(1)->value == 30);
    assert(list.get(2)->value == 20);
    assert(list.get(3)->value == 40);
    Logger::def("test_swap_values_middle_elements passed.");
}

void test_swap_values_first_and_last() {
    LinkedList list({5, 6, 7, 8});
    list.swap_values(0, 3);
    assert(list.get(0)->value == 8);
    assert(list.get(3)->value == 5);
    Logger::def("test_swap_values_first_and_last passed.");
}

void test_swap_values_invalid_indices_throws() {
    LinkedList list({1, 2, 3});
    bool exception_thrown = false;

    try {
        list.swap_values(0, 10);
    } catch (const std::invalid_argument&) {
        exception_thrown = true;
    }

    assert(exception_thrown);
    Logger::def("test_swap_values_invalid_indices_throws passed.");
}
