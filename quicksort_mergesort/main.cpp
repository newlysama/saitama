/*
* DAY ONE OF TRAINING
*/


#include "linked_list.hh"
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
    std::vector<size_t> arr = {1, 2, 3, 4, 5, 6};
    std::unique_ptr<LinkedList> list = std::make_unique<LinkedList>(arr);

    list->print();

    std::unique_ptr<Node> n = list->pop_front();

    std::cout << n->value << "\n";
    list->print();

    return 0;
}