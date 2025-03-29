#include "linked_lists.hh"

std::tuple<std::unique_ptr<LinkedList>, std::unique_ptr<LinkedList>> LinkedList::split(std::unique_ptr<LinkedList> list) {
    if (list->empty()) {
        throw std::invalid_argument("Cannot split() on empty list.");
    } else if (list->size == 1) {
        throw std::invalid_argument("Cannot split() list of size 1.");
    }

    size_t split_index = list->size / 2;

    // Don't need to modify emplace, since we use unique ptrs anyway
    std::unique_ptr<LinkedList> new_list1 = std::make_unique<LinkedList>();
    std::unique_ptr<LinkedList> new_list2 = std::make_unique<LinkedList>();

    new_list1->first = std::move(list->first);
    Node *current = new_list1->first.get();
    size_t i = 0;
    while (i < split_index - 1) {
        current = current->next.get();
        i++;
    }
    new_list1->last = current;

    new_list2->first = std::move(current->next);
    current->next = nullptr;
    new_list2->last = list->last;

    // Double assignment because it's cool
    std::tie(new_list1->size, new_list2->size) =
        list->size % 2 == 0
        ? std::make_tuple(split_index, split_index)
        : std::make_tuple(split_index, split_index + 1);

    return std::make_tuple<std::unique_ptr<LinkedList>, std::unique_ptr<LinkedList>>(std::move(new_list1), std::move(new_list2));
}