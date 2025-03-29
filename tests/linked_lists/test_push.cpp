#include <cassert>

#include <linked_lists/linked_lists.hh>
#include <logger/logger.hh>

void test_push_front_single_element() {
    LinkedList list;
    list.push_front(10);
    assert(list.size == 1);
    assert(list.get(0)->value == 10);
    Logger::success("test_push_front_single_element passed.");
}

void test_push_front_multiple_elements_order() {
    LinkedList list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    assert(list.size == 3);
    assert(list.get(0)->value == 3);
    assert(list.get(1)->value == 2);
    assert(list.get(2)->value == 1);
    Logger::success("test_push_front_multiple_elements_order passed.");
}

void test_push_back_single_element() {
    LinkedList list;
    list.push_back(99);
    assert(list.size == 1);
    assert(list.get(0)->value == 99);
    Logger::success("test_push_back_single_element passed.");
}

void test_push_back_multiple_elements_order() {
    LinkedList list;
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    assert(list.size == 3);
    assert(list.get(0)->value == 4);
    assert(list.get(1)->value == 5);
    assert(list.get(2)->value == 6);
    Logger::success("test_push_back_multiple_elements_order passed.");
}

void test_push_front_and_back_combination() {
    LinkedList list;
    list.push_back(10);
    list.push_front(5);
    list.push_back(15);
    assert(list.size == 3);
    assert(list.get(0)->value == 5);
    assert(list.get(1)->value == 10);
    assert(list.get(2)->value == 15);
    Logger::success("test_push_front_and_back_combination passed.");
}