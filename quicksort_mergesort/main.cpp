/*
* DAY ONE OF TRAINING
*/

#include "merge_sort.hh"
#include "quick_sort.hh"

// std::vector<size_t> arr = {75, 2, 3, 65, 5, 45, 85, 18, 102, 250, 1000, 7, 5};

// std::unique_ptr<LinkedList> list = std::make_unique<LinkedList>(arr);

// list->print();
// list = sort(std::move(list));
// list->print()

void print_vec(std::vector<std::size_t> vec)  {
    if (vec.size() == 0) {
        std::cout << "[ ]\n";
        return;
    }

    std::cout << "[ ";
    size_t i = 0;

    for (size_t j = 0; j < vec.size() - 1; j++, i++) {
        std::cout << vec[i] << ", ";
    }

    std::cout << vec[i] << " ]\n";
}

int main() {
    std::vector<size_t> arr = {};

    auto res = merge_sort(arr);

    print_vec(res);
    return 0;
}