#include "linked_lists.hh"

std::tuple<std::unique_ptr<LinkedList>, std::unique_ptr<LinkedList>>
LinkedList::split(std::unique_ptr<LinkedList> list, std::optional<size_t> split_index) {
    if (list->empty()) {
        throw std::invalid_argument("Cannot split() on empty list.");
    } else if (list->size == 1) {
        throw std::invalid_argument("Cannot split() list of size 1.");
    }

    split_index = split_index.value_or(list->size / 2);

    if (split_index.value() > list->size) {
        throw std::invalid_argument("Cannot split() beyond the end of the list.");
    }

    // Custom handling for pivot_index = 0, since 'pivot_index - 1' in next while loop won't behave as expected (pivot_index is size_t)
    if (split_index.value() == 0) {
        auto left = std::make_unique<LinkedList>();
        return std::make_tuple<std::unique_ptr<LinkedList>, std::unique_ptr<LinkedList>>(std::move(left), std::move(list));
    }

    std::unique_ptr<LinkedList> new_list1 = std::make_unique<LinkedList>();
    std::unique_ptr<LinkedList> new_list2 = std::make_unique<LinkedList>();

    new_list1->first = std::move(list->first);
    Node *current = new_list1->first.get();
    size_t i = 0;
    while (i < split_index.value() - 1) {
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
        ? std::make_tuple(split_index.value(), split_index.value())
        : std::make_tuple(split_index.value(), split_index.value() + 1);

    return std::make_tuple<std::unique_ptr<LinkedList>, std::unique_ptr<LinkedList>>(std::move(new_list1), std::move(new_list2));
}

std::tuple<std::unique_ptr<LinkedList>, std::unique_ptr<LinkedList>, std::unique_ptr<LinkedList>>
LinkedList::split_around_pivot(std::unique_ptr<LinkedList> list, size_t pivot_index) {
    if (list->empty()) {
        throw std::invalid_argument("Cannot split() on empty list.");
    } else if (list->size == 1) {
        throw std::invalid_argument("Cannot split() list of size 1.");
    }

    std::unique_ptr<LinkedList> left = std::make_unique<LinkedList>();
    std::unique_ptr<LinkedList> pivot = std::make_unique<LinkedList>();
    std::unique_ptr<LinkedList> right = std::make_unique<LinkedList>();

    // Custom handling for pivot_index = 0, since 'pivot_index - 1' in next while loop won't behave as expected (pivot_index is size_t)
    if (pivot_index == 0) {
        pivot->push_back(list->first->value);
        
        right->first = std::move(list->first->next);
        right->last = list->last;
        right->size = list->size - 1;
        
        return std::make_tuple(std::move(left), std::move(pivot), std::move(right));
    }

    left->first = std::move(list->first);
    Node *current = left->first.get();
    size_t i = 0;
    while (i < pivot_index - 1) {
        current = current->next.get();
        i++;
    }

    pivot->first = std::move(current->next);
    current->next = nullptr;
    left->last = current;

    right->first = std::move(pivot->first->next);
    pivot->first->next = nullptr;

    left->size = pivot_index;
    pivot->size = 1;
    right->size = list->size - pivot_index - 1;

    if (left->size > 0)
        left->last = left->get(left->size - 1);

    pivot->last = pivot->first.get();

    if (right->size > 0)
        right->last = right->get(right->size - 1);

    return std::make_tuple(std::move(left), std::move(pivot), std::move(right));
}