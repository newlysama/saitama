#include <cassert>

#include <linked_lists/linked_lists.hh>
#include <logger/logger.hh>

void test_get_first_element() {
    LinkedList list({10, 20, 30});
    Node* n = list.get(0);
    assert(n != nullptr);
    assert(n->value == 10);
    Logger::success("test_get_first_element passed.");
}

void test_get_middle_element() {
    LinkedList list({10, 20, 30});
    Node* n = list.get(1);
    assert(n != nullptr);
    assert(n->value == 20);
    Logger::success("test_get_middle_element passed.");
}

void test_get_last_element() {
    LinkedList list({10, 20, 30});
    Node* n = list.get(2);
    assert(n != nullptr);
    assert(n->value == 30);
    Logger::success("test_get_last_element passed.");
}

void test_get_out_of_bounds_returns_nullptr() {
    LinkedList list({1, 2, 3});
    Node* n = list.get(10);
    assert(n == nullptr);
    Logger::success("test_get_out_of_bounds_returns_nullptr passed.");
}