/**
 * @brief Use std::move to build tuples. This prevents make_tuple from copying the list, which would be more time consuming.
 * And we don't have copy constructor anyway, so the call would just fail x)
 */

#include "linked_lists.hh"
#include "linked_lists_algorithms.hh"

using namespace Checker;

std::tuple<LinkedList, LinkedList> LinkedListAlgorithm::split(LinkedList& list, std::optional<size_t> split_index) {
    if (list.empty()) {
        throw std::invalid_argument("LinkedListAlgorithm::split() : cannot split empty list.");
    } else if (list.size == 1) {
        throw std::invalid_argument("LinkedListAlgorithm::split() : cannot split list of size 1.");
    }
    

    split_index = split_index.value_or(list.size / 2);
    check_index("LinkedListAlgorithm::split()", split_index.value(), list.size);

    // Create new lists on the same arena than original list
    // ==> More performant and less memory consuming (pre-allocated + contiguous)
    LinkedList left(list.arena);
    LinkedList right(list.arena);

    // Custom handling for split at last element to save time
    // Also, next coming loop compares to split_index - 1, which makes 0 - 1 at first element (doesn't work as expected with size_t's)
    if (split_index.value() == 0) {
        left.push_back(list.pop_front());
        return std::make_tuple(std::move(left), std::move(list)); 
    } else if (split_index.value() == list.size - 1) {
        right.push_back(list.pop_back());
        return std::make_tuple(std::move(list), std::move(right));    
    }

    // Set left's beginning
    left.first = list.first;
    auto current = left.first;

    // Index to keep track of the splitting, allowing
    // To set right's size properly
    size_t i = 0;

    while (i < split_index.value() - 1) {
        check_access_nullptr(current, "LinkedListAlgorithm::split()", i);
        current = current->next;
        i++;
    }
    left.last = current;

    check_access_nullptr(current, "LinkedListAlgorithm::split()", i);

    right.first = current->next;

    // Unbind rights's first's prev elt and left's last's next
    right.first->prev = nullptr;
    left.last->next = nullptr;

    right.last = list.last;

    left.size = i + 1;
    right.size = list.size - left.size;

    list.clear();
    return std::make_tuple(std::move(left), std::move(right));
}

std::tuple<LinkedList, LinkedList, LinkedList> LinkedListAlgorithm::split_around_pivot(LinkedList& list, size_t pivot_index) {
    if (list.empty()) {
        throw std::invalid_argument("LinkedList::split_around_pivot() : cannot split empty list.");
    } else if (list.size == 1) {
        throw std::invalid_argument("LinkedList::split_around_pivot() : cannot split list of size 1.");
    }

    check_index("LinkedListAlgorithm::split_around_pivot()", pivot_index, list.size);

    // Create new lists on the same arena than original list
    // ==> More performant and less memory consuming (pre-allocated + contiguous)
    LinkedList left(list.arena);
    LinkedList pivot(list.arena);
    LinkedList right(list.arena);

    // Custom handling for split at last element to save time
    // Also, next coming loop compares to split_index - 1, which makes 0 - 1 at first element (doesn't work as expected with size_t's)
    if (pivot_index == 0) {
        pivot.push_back(list.pop_front());
        return { std::move(left), std::move(pivot), std::move(list) };
    } else if (pivot_index == list.size - 1) {
        pivot.push_back(list.pop_back());
        return { std::move(list), std::move(pivot), std::move(right) };
    }

    // Save last now before it gets freed
    auto right_last = list.last;

    left.first = list.first;
    auto current = left.first;
    size_t i = 0;

    while (i < pivot_index - 1) {
        check_access_nullptr(current, "split_around_pivot()", i);

        current = current->next;
        i++;
    }

    pivot.first = current->next;
    current->next = nullptr;
    left.last = current;

    right.first = pivot.first->next;
    right.first->prev = nullptr;
    pivot.first->next = nullptr;
    pivot.first->prev = nullptr;

    left.size = pivot_index;
    pivot.size = 1;
    right.size = list.size - pivot_index - 1;

    if (left.size > 0)
        left.last = left.get(left.size - 1);

    pivot.last = pivot.first;

    if (right.size > 0) {
        right.last = right_last;
    }

    return std::make_tuple(std::move(left), std::move(pivot), std::move(right));
}
