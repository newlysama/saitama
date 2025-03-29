#include <cassert>

#include <linked_lists/linked_lists.hh>
#include <logger/logger.hh>

void test_merge_two_sorted_lists() {
    auto list1 = std::make_unique<LinkedList>(std::vector<size_t>{1, 3, 5});
    auto list2 = std::make_unique<LinkedList>(std::vector<size_t>{2, 4, 6});
    auto merged = LinkedList::merge(std::move(list1), std::move(list2));

    assert(merged->size == 6);
    for (size_t i = 0; i < 6; ++i) {
        assert(merged->get(i)->value == i + 1);
    }

    assert(merged->last->value == 6);
    Logger::def("test_merge_two_sorted_lists passed.");
}

void test_merge_with_one_list_empty() {
    auto list1 = std::make_unique<LinkedList>(std::vector<size_t>{});
    auto list2 = std::make_unique<LinkedList>(std::vector<size_t>{10, 20});
    auto merged = LinkedList::merge(std::move(list1), std::move(list2));

    assert(merged->first->value == 10);
    assert(merged->last->value == 20);
    Logger::def("test_merge_with_one_list_empty passed.");
}

void test_merge_with_both_lists_empty() {
    auto list1 = std::make_unique<LinkedList>();
    auto list2 = std::make_unique<LinkedList>();
    auto merged = LinkedList::merge(std::move(list1), std::move(list2));

    assert(merged->first == nullptr);
    assert(merged->last == nullptr);
    Logger::def("test_merge_with_both_lists_empty passed.");
}

void test_merge_preserves_order_and_elements() {
    auto list1 = std::make_unique<LinkedList>(std::vector<size_t>{1, 4, 5});
    auto list2 = std::make_unique<LinkedList>(std::vector<size_t>{2, 3, 6});
    auto merged = LinkedList::merge(std::move(list1), std::move(list2));

    std::vector<size_t> expected = {1, 2, 3, 4, 5, 6};
    for (size_t i = 0; i < expected.size(); ++i) {
        assert(merged->get(i)->value == expected[i]);
    }

    assert(merged->last->value == 6);
    Logger::def("test_merge_preserves_order_and_elements passed.");
}

void test_merge_duplicates_are_preserved() {
    auto list1 = std::make_unique<LinkedList>(std::vector<size_t>{1, 3, 3});
    auto list2 = std::make_unique<LinkedList>(std::vector<size_t>{2, 3, 4});
    auto merged = LinkedList::merge(std::move(list1), std::move(list2));

    std::vector<size_t> expected = {1, 2, 3, 3, 3, 4};
    assert(merged->size == expected.size());
    for (size_t i = 0; i < expected.size(); ++i) {
        assert(merged->get(i)->value == expected[i]);
    }

    assert(merged->last->value == 4);
    Logger::def("test_merge_duplicates_are_preserved passed.");
}