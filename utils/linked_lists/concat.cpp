#include "linked_lists.hh"

std::unique_ptr<LinkedList> LinkedList::concat(std::unique_ptr<LinkedList> list1, std::unique_ptr<LinkedList> list2) {
    if (list1->empty()) {
        return list2;
    } else if (list2->empty()) {
        return list1;
    }

    list1->last->next = std::move(list2->first);
    list1->last = list2->last;
    list1->size += list2->size;

    return list1;
}