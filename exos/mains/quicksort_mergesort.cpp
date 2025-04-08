#include "utils/generator/generator.hh"
#include "utils/linked_lists/linked_lists.hh"
#include "utils/vector_utils/vector_utils.hh"
#include "utils/memory_manager/memory_manager.hh"
#include "utils/logger/logger.hh"

#include "exos/quicksort_mergesort/quick_sort.hh"
#include "exos/quicksort_mergesort/merge_sort.hh"

using namespace Generator;
using namespace VectorUtils;

constexpr size_t SIZE = 20;
constexpr size_t MAX_VAL = 100;

int main() {
    // Creates 1 arena for linked lists, 1 for vectors
    auto vector_arena = MemoryManager::instance().create_arena(SIZE * sizeof(size_t) * 4);
    auto list_arena = MemoryManager::instance().create_arena(SIZE * sizeof(Node) * 4);

    auto raw_vector_arena = vector_arena.get();
    auto raw_list_arena = list_arena.get();

    std::pmr::vector<size_t> vector_random(raw_vector_arena);

    // =========================================================
    //       			     VECTORS
    // =========================================================

    vector_random = generate_random_vector(SIZE, MAX_VAL, raw_vector_arena);
    Logger::status("Quicksort Lomuto Vectors on:      ");
    print(vector_random);
    quick_sort_lomuto(vector_random);
    Logger::status("Sorting result:                   ");
    print(vector_random);

    std::cout << "\n";

    vector_random = generate_random_vector(SIZE, MAX_VAL, raw_vector_arena);
    Logger::status("Quicksort Hoare Vectors on:       ");
    print(vector_random);
    quick_sort_hoare(vector_random);
    Logger::status("Sorting result:                   ");
    print(vector_random);

    std::cout << "\n";

    vector_random = generate_random_vector(SIZE, MAX_VAL, raw_vector_arena);
    Logger::status("Mergesort Vectors on:             ");
    print(vector_random);
    vector_random = merge_sort(vector_random);
    Logger::status("Sorting result:                   ");
    print(vector_random);

    std::cout << "\n";

    // =========================================================
    //       			   LINKED LISTS
    // =========================================================

    auto linked_list_random = generate_random_linked_list(SIZE, MAX_VAL, raw_list_arena);
    Logger::status("Quicksort Lomuto Linked Lists on: ");
    linked_list_random.print();
    quick_sort_lomuto(linked_list_random);
    Logger::status("Sorting result:                   ");
    linked_list_random.print();

    std::cout << "\n";

    linked_list_random = generate_random_linked_list(SIZE, MAX_VAL, raw_list_arena);
    Logger::status("Quicksort Hoare Linked Lists on:  ");
    linked_list_random.print();
    quick_sort_hoare(linked_list_random);
    Logger::status("Sorting result:                   ");
    linked_list_random.print();

    std::cout << "\n";

    linked_list_random = generate_random_linked_list(SIZE, MAX_VAL, raw_list_arena);
    Logger::status("Mergesort Linked Lists on:        ");
    linked_list_random.print();
    merge_sort(linked_list_random);
    Logger::status("Sorting result:                   ");
    linked_list_random.print();

    return 0;
}
