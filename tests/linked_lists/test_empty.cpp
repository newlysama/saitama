#include <cassert>

#include <linked_lists/linked_lists.hh>
#include <logger/logger.hh>

void test_empty_on_default_constructed_list() {
    LinkedList list;
    assert(list.empty());
    Logger::success("test_empty_on_default_constructed_list passed.");
}

void test_empty_on_list_after_all_pops() {
    LinkedList list;
    list.push_back(10);
    list.pop_front();
    assert(list.empty());
    Logger::success("test_empty_on_list_after_all_pops passed.");
}

void test_empty_false_after_push_front() {
    LinkedList list;
    list.push_front(5);
    assert(!list.empty());
    Logger::success("test_empty_false_after_push_front passed.");
}

void test_empty_false_after_push_back() {
    LinkedList list;
    list.push_back(42);
    assert(!list.empty());
    Logger::success("test_empty_false_after_push_back passed.");
}
