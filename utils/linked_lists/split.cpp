#include "linked_lists.hh"
#include "linked_lists_algorithms.hh"

/**
 * @details Here to build the tuples, we need to std::move() the lists we want in.
 * This is due to the fact that std::make_tuple() tryies to build its object by copying
 * the elements we want in it, but we don't have any copy constructor for out linked lists (and we don't want some).
 */


std::tuple<LinkedList, LinkedList> LinkedListAlgorithm::split(LinkedList& list, std::optional<size_t> split_index) {
    if (list.empty()) {
        throw std::invalid_argument("LinkedListAlgorithm::split() : cannot split empty list.");
    } else if (list.size == 1) {
        throw std::invalid_argument("LinkedListAlgorithm::split() : cannot split list of size 1.");
    }
    

    split_index = split_index.value_or(list.size / 2);
    check_index("LinkedListAlgorithm::split()", split_index.value(), list.size);

    LinkedList left;
    LinkedList right;

    // Custom handling for split at last element to save time
    // Also, next coming loop compares to split_index - 1, which makes 0 - 1 at first element (doesn't work as expected with size_t's)
    if (split_index.value() == 0) {
        auto first = list.pop_front();
        left.push_back(std::move(first));

        return std::make_tuple(std::move(left), std::move(list)); 
    } else if (split_index.value() == list.size - 1) {
        auto last = list.pop_back();
        right.push_back(std::move(last));

        return std::make_tuple(std::move(list), std::move(right));    
    }

    left.first = std::move(list.first);
    auto current = left.first.get();
    size_t i = 0;

    while (i < split_index.value() - 1) {
        check_access_nullptr(current, "LinkedListAlgorithm::split()", i);

        current = current->next.get();
        i++;
    }
    left.last = current;

    check_access_nullptr(current, "LinkedListAlgorithm::split()", i);

    right.first = std::move(current->next);
    right.first->prev = nullptr;
    left.last->next = nullptr;
    right.last = list.last;

    left.size = i + 1;
    right.size = list.size - left.size;

    return std::make_tuple(std::move(left), std::move(right));
}

std::tuple<LinkedList, LinkedList, LinkedList> LinkedListAlgorithm::split_around_pivot(LinkedList& list, size_t pivot_index) {
    if (list.empty()) {
        throw std::invalid_argument("LinkedList::split_around_pivot() : cannot split empty list.");
    } else if (list.size == 1) {
        throw std::invalid_argument("LinkedList::split_around_pivot() : cannot split list of size 1.");
    }

    check_index("split_around_pivot()", pivot_index, list.size);

    LinkedList left;
    LinkedList right;
    LinkedList pivot;

    // Custom handling for split at last element to save time
    // Also, next coming loop compares to split_index - 1, which makes 0 - 1 at first element (doesn't work as expected with size_t's)
    if (pivot_index == 0) {
        auto first = list.pop_front();
        pivot.push_back(std::move(first));

        return std::make_tuple(std::move(left), std::move(pivot), std::move(list));
    } else if (pivot_index == list.size - 1) {
        auto last = list.pop_back();
        pivot.push_back(std::move(last));
        
        return std::make_tuple(std::move(list), std::move(pivot), std::move(right));    
    }

    auto right_last = list.last;

    left.first = std::move(list.first);
    auto current = left.first.get();
    size_t i = 0;

    while (i < pivot_index - 1) {
        check_access_nullptr(current, "split_around_pivot()", i);

        current = current->next.get();
        i++;
    }

    pivot.first = std::move(current->next);
    current->next = nullptr;
    left.last = current;

    right.first = std::move(pivot.first->next);
    right.first->prev = nullptr;
    pivot.first->next = nullptr;
    pivot.first->prev = nullptr;

    left.size = pivot_index;
    pivot.size = 1;
    right.size = list.size - pivot_index - 1;

    if (left.size > 0)
        left.last = left.get(left.size - 1);

    pivot.last = pivot.first.get();

    if (right.size > 0) {
        right.last = right_last;
    }

    return std::make_tuple(std::move(left), std::move(pivot), std::move(right));
}