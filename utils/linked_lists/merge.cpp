#include "linked_lists.hh"

std::unique_ptr<LinkedList> LinkedList::merge(std::unique_ptr<LinkedList> list1, std::unique_ptr<LinkedList> list2) {
    // We don't care about checking if both lists are empty, we'll just return the other one anyway
    if (list1->empty()) {
        return list2;
    } else if (list2->empty()) {
        return list1;
    }

    // Return a new list is simplier here, since we didn't implement insert() method
    std::unique_ptr<LinkedList> res = std::make_unique<LinkedList>();
    while (!list1->empty() && !list2->empty()) {
        if (list1->first->value <= list2->first->value) {
            std::unique_ptr<Node> n = list1->pop_front();
            res->push_back(std::move(n));
        } else {
            std::unique_ptr<Node> n = list2->pop_front();
            res->push_back(std::move(n));
        }
    }

    while (!list1->empty()) {
        std::unique_ptr<Node> n = list1->pop_front();
        res->push_back(std::move(n));   
    }

    while (!list2->empty()) {
        std::unique_ptr<Node> n = list2->pop_front();
        res->push_back(std::move(n));   
    }

    return res;
}