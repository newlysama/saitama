#include <cassert>

#include <linked_lists/linked_lists.hh>
#include <logger/logger.hh>

void test_pop_front_from_list_of_multiple_elements() {
    LinkedList list({1, 2, 3});
    std::unique_ptr<Node> popped = list.pop_front();
    assert(popped != nullptr);
    assert(popped->value == 1);
    assert(list.size == 2);
    assert(list.get(0)->value == 2);
    Logger::success("test_pop_front_from_list_of_multiple_elements passed.");
}

void test_pop_back_from_list_of_multiple_elements() {
    LinkedList list({1, 2, 3});
    std::unique_ptr<Node> popped = list.pop_back();
    assert(popped != nullptr);
    assert(popped->value == 3);
    assert(list.size == 2);
    assert(list.get(1)->value == 2);
    assert(list.last->value == 2);
    Logger::success("test_pop_back_from_list_of_multiple_elements passed.");
}

void test_pop_front_on_empty_list_throws() {
    LinkedList list;
    bool exception_thrown = false;

    try {
        list.pop_front();
    } catch (const std::invalid_argument& e) {
        exception_thrown = true;
    }

    assert(exception_thrown);
    Logger::success("test_pop_front_on_empty_list_throws passed.");
}


void test_pop_back_on_empty_list_throws() {
    LinkedList list;
    bool exception_thrown = false;

    try {
        list.pop_back();
    } catch (const std::invalid_argument& e) {
        exception_thrown = true;
    }

    assert(exception_thrown);
    Logger::success("test_pop_back_on_empty_list_throws passed.");
}

void test_pop_back_on_single_element_list() {
    LinkedList list({99});
    std::unique_ptr<Node> popped = list.pop_back();
    assert(popped != nullptr);
    assert(popped->value == 99);
    assert(list.empty());
    assert(list.last == nullptr);
    Logger::success("test_pop_back_on_single_element_list passed.");
}

void test_pop_front_on_single_element_list() {
    LinkedList list({88});
    std::unique_ptr<Node> popped = list.pop_front();
    assert(popped != nullptr);
    assert(popped->value == 88);
    assert(list.empty());
    assert(list.last == nullptr);
    Logger::success("test_pop_front_on_single_element_list passed.");
}