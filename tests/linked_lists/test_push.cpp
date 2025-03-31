#include <cassert>

#include <linked_lists/linked_lists.hh>
#include <logger/logger.hh>

void test_push_front_single_element() {
    LinkedList list;
    list.push_front(10);
    assert(list.size == 1);
    assert(list.get(0)->value == 10);
    assert(list.last->value == 10);
    assert(list.first->prev == nullptr);
    assert(list.last->prev == nullptr);
    Logger::def("test_push_front_single_element passed.");
}

void test_push_front_multiple_elements_order() {
    LinkedList list;
    list.push_front(1);  // Liste: 1
    list.push_front(2);  // Liste: 2 -> 1
    list.push_front(3);  // Liste: 3 -> 2 -> 1

    assert(list.size == 3);
    assert(list.get(0)->value == 3);
    assert(list.get(1)->value == 2);
    assert(list.get(2)->value == 1);

    // Vérifie prev
    assert(list.get(0)->prev == nullptr);
    assert(list.get(1)->prev == list.get(0));
    assert(list.get(2)->prev == list.get(1));

    Logger::def("test_push_front_multiple_elements_order passed.");
}

void test_push_back_single_element() {
    LinkedList list;
    list.push_back(10);

    assert(!list.empty());
    assert(list.size == 1);
    assert(list.get(0)->value == 10);
    assert(list.get(0) == list.last);
    assert(list.get(0)->prev == nullptr);
    Logger::def("test_push_back_single_element passed.");
}

void test_push_back_multiple_elements_order() {
    LinkedList list;
    std::vector<size_t> input = {1, 2, 3, 4};
    for (size_t v : input) list.push_back(v);

    assert(list.size == input.size());
    for (size_t i = 0; i < input.size(); ++i) {
        assert(list.get(i)->value == input[i]);
        if (i == 0) {
            assert(list.get(i)->prev == nullptr);
        } else {
            assert(list.get(i)->prev == list.get(i - 1));
        }
    }

    assert(list.last->value == input.back());
    Logger::def("test_push_back_multiple_elements_order passed.");
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

    // Vérifie prev
    assert(list.get(0)->prev == nullptr);
    assert(list.get(1)->prev == list.get(0));
    assert(list.get(2)->prev == list.get(1));

    assert(list.last->value == 15);
    Logger::def("test_push_front_and_back_combination passed.");
}
