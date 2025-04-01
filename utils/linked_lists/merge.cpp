#include "linked_lists.hh"

std::unique_ptr<LinkedList> LinkedList::merge(std::unique_ptr<LinkedList> list1, std::unique_ptr<LinkedList> list2) {
    // We don't care about checking if both lists are empty, we'll just return the other one anyway
    if (list1->empty()) {
        return list2;
    } else if (list2->empty()) {
        return list1;
    }

    // Return a new list is simplier and more readable here
    // But if we want to improve memory managment, we can merge list2 into list 1 in-place
    std::unique_ptr<LinkedList> res = std::make_unique<LinkedList>();

    while (!list1->empty() && !list2->empty()) {
        if (list1->first->value <= list2->first->value) {
            auto n = list1->pop_front();
            res->push_back(std::move(n));
        } else {
            auto n = list2->pop_front();
            res->push_back(std::move(n));
        }
    }

    while (!list1->empty()) {
        auto n = list1->pop_front();
        res->push_back(std::move(n));   
    }

    while (!list2->empty()) {
        auto n = list2->pop_front();
        res->push_back(std::move(n));   
    }

    return res;
}