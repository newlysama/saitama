#include "linked_lists.hh"


void LinkedList::concat(std::unique_ptr<LinkedList>& list1, std::unique_ptr<LinkedList>& list2) {
    if (list1->empty()) {
        LinkedList::transfer(list1, list2);
        return;
    } else if (list2->empty()) {
        return;
    }

    check_access_nullptr(list1->last, "concat()");

    list2->first->prev = list1->last;
    list1->last->next = std::move(list2->first);
    list1->last = list2->last;
    list1->size += list2->size;
}