#include <cassert>

#include <linked_lists/linked_lists.hh>
#include <logger/logger.hh>

void test_split_even_length_list_returns_two_equal_parts() {
    auto splited = LinkedList::split(std::make_unique<LinkedList>(std::vector<size_t>{1,2,3,4}));
    auto left = std::move(std::get<0>(splited));
    auto right = std::move(std::get<1>(splited));

    assert(left->size == 2);
    assert(right->size == 2);
    assert(left->get(0)->value == 1);
    assert(left->get(1)->value == 2);
    assert(right->get(0)->value == 3);
    assert(right->get(1)->value == 4);

    assert(left->last->value == 2);
    assert(right->last->value == 4);
    Logger::def("test_split_even_length_list_returns_two_equal_parts passed.");
}

void test_split_odd_length_list_returns_correct_sizes() {
    auto splited = LinkedList::split(std::make_unique<LinkedList>(std::vector<size_t>{1,2,3,4,5}));
    auto left = std::move(std::get<0>(splited));
    auto right = std::move(std::get<1>(splited));

    assert(left->size == 2);
    assert(right->size == 3);
    Logger::def("test_split_odd_length_list_returns_correct_sizes passed.");
}

void test_split_empty_list_throws() {
    LinkedList list;
    bool exception_thrown = false;

    try {
        list.split(std::make_unique<LinkedList>());
    } catch (const std::invalid_argument& e) {
        exception_thrown = true;
    }

    assert(exception_thrown);
    Logger::def("test_split_empty_list_throws passed.");
}


void test_split_single_element_list_throws() {
    LinkedList list({42});
    bool exception_thrown = false;

    try {
        list.split(std::make_unique<LinkedList>(std::vector<size_t>{42}));
    } catch (const std::invalid_argument& e) {
        exception_thrown = true;
    }

    assert(exception_thrown);
    Logger::def("test_split_single_element_list_throws passed.");
}


void test_split_preserves_order_in_both_parts() {
    auto splited = LinkedList::split(std::make_unique<LinkedList>(std::vector<size_t>{1,3,5,7}));
    auto left = std::move(std::get<0>(splited));
    auto right = std::move(std::get<1>(splited));

    assert(left->get(0)->value == 1);
    assert(left->get(1)->value == 3);
    assert(right->get(0)->value == 5);
    assert(right->get(1)->value == 7);
    Logger::def("test_split_preserves_order_in_both_parts passed.");
}

void test_split_at_index_custom() {
    auto splited = LinkedList::split(std::make_unique<LinkedList>(std::vector<size_t>{10, 20, 30, 40, 50}));
    auto left = std::move(std::get<0>(splited));
    auto right = std::move(std::get<1>(splited));
    
    assert(left->size == 2);
    assert(right->size == 3);
    assert(left->get(0)->value == 10);
    assert(left->get(1)->value == 20);
    assert(right->get(0)->value == 30);
    assert(right->get(1)->value == 40);
    assert(right->get(2)->value == 50);
    assert(left->last->value == 20);
    assert(right->last->value == 50);

    Logger::def("test_split_at_index_custom passed.");
}

// CUSTOM SPLIT FUNCTION
void test_split_around_pivot_middle() {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{1, 2, 3, 4, 5});
    auto [left, pivot, right] = LinkedList::split_around_pivot(std::move(list), 2);

    assert(left->size == 2);
    assert(left->get(0)->value == 1);
    assert(left->get(1)->value == 2);

    assert(pivot->size == 1);
    assert(pivot->get(0)->value == 3);

    assert(right->size == 2);
    assert(right->get(0)->value == 4);
    assert(right->get(1)->value == 5);

    Logger::def("test_split_around_pivot_middle passed.");
}

void test_split_around_pivot_zero() {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{10, 20, 30});
    auto [left, pivot, right] = LinkedList::split_around_pivot(std::move(list), 0);
    assert(left->size == 0);

    assert(pivot->size == 1);
    assert(pivot->get(0)->value == 10);

    assert(right->size == 2);
    assert(right->get(0)->value == 20);
    assert(right->get(1)->value == 30);

    Logger::def("test_split_around_pivot_zero passed.");
}

void test_split_around_pivot_last() {
    auto list = std::make_unique<LinkedList>(std::vector<size_t>{7, 8, 9});
    auto [left, pivot, right] = LinkedList::split_around_pivot(std::move(list), 2);

    assert(left->size == 2);
    assert(left->get(0)->value == 7);
    assert(left->get(1)->value == 8);

    assert(pivot->size == 1);
    assert(pivot->get(0)->value == 9);

    assert(right->size == 0);

    Logger::def("test_split_around_pivot_last passed.");
}

void test_split_around_pivot_invalid() {
    bool exception_thrown = false;
    try {
        auto list = std::make_unique<LinkedList>(std::vector<size_t>{1});
        LinkedList::split_around_pivot(std::move(list), 0);
    } catch (const std::invalid_argument&) {
        exception_thrown = true;
    }

    assert(exception_thrown);
    Logger::def("test_split_around_pivot_invalid passed.");
}