/*
* DAY ONE OF TRAINING
*/

#include "merge_sort.hh"
#include "quick_sort.hh"

    // std::unique_ptr<LinkedList> list = std::make_unique<LinkedList>();

    // list->push_back(1);
    // list->push_back(2);
    // list->push_back(3);
    // list->push_back(4);
    // list->push_back(5);
    
    // list->print();


int main() {
    std::vector<size_t> arr = {75, 2, 3, 65, 5, 45, 85, 18, 102, 250, 1000, 7, 5};

    std::unique_ptr<LinkedList> list = std::make_unique<LinkedList>(arr);

    list->print();
    sort(std::move(list));

    return 0;
}