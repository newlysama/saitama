#include "merge_sort.hh"

#ifdef MERGE_SORT
std::unique_ptr<LinkedList> sort(std::unique_ptr<LinkedList> list) {
    if (list->size == 1) {
        return list;
    }

    std::unique_ptr<LinkedList> new_list = list->split();
    list->print();
    new_list->print();
    std::cout << "\n";

    return LinkedList::merge(sort(std::move(list)), sort(std::move(new_list)));
}
#endif