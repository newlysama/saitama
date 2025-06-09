#include "utils/generator/generator.hh"
#include "utils/linked_lists/linked_lists.hh"
#include "utils/vector_utils/vector_utils.hh"
#include "utils/memory_manager/memory_manager.hh"
#include "utils/logger/logger.hh"

#include "exos/quicksort_mergesort/quick_sort.hh"
#include "exos/quicksort_mergesort/merge_sort.hh"

using namespace Generator;
using namespace VectorUtils;
using ScalableVector = std::vector<size_t, tbb::scalable_allocator<size_t>>;
using FixedList = LinkedList<MemoryManager::FixedArena>;

constexpr size_t SIZE = 20;
constexpr size_t MAX_VAL = 100;

int main() {
    auto arena_size = MemoryManager::compute_safe_allocation_size(sizeof(Node), SIZE);
    auto arena = MemoryManager::instance().create_fixed_arena(arena_size);

    ScalableVector vector_random;

    // =========================================================
    //       			     VECTORS
    // =========================================================

    vector_random = generate_random_vector(SIZE, MAX_VAL);
    Logger::status("Quicksort Lomuto Vectors on:      ");
    print(vector_random);
    quick_sort_lomuto(vector_random);
    Logger::status("Sorting result:                   ");
    print(vector_random);

    std::cout << "\n";

    vector_random = generate_random_vector(SIZE, MAX_VAL);
    Logger::status("Quicksort Hoare Vectors on:       ");
    print(vector_random);
    quick_sort_hoare(vector_random);
    Logger::status("Sorting result:                   ");
    print(vector_random);

    std::cout << "\n";

    vector_random = generate_random_vector(SIZE, MAX_VAL);
    Logger::status("Mergesort Vectors on:             ");
    print(vector_random);
    vector_random = merge_sort(vector_random);
    Logger::status("Sorting result:                   ");
    print(vector_random);

    std::cout << "\n";

    // =========================================================
    //       			   LINKED LISTS
    // =========================================================

    FixedList linked_list_random = generate_random_linked_list(SIZE, MAX_VAL, arena);
    Logger::status("Quicksort Lomuto Linked Lists on: ");
    linked_list_random.print();
    quick_sort_lomuto(linked_list_random);
    Logger::status("Sorting result:                   ");
    linked_list_random.print();
    linked_list_random.clear();
    arena->reset();

    std::cout << "\n";

    linked_list_random = generate_random_linked_list(SIZE, MAX_VAL, arena);
    Logger::status("Quicksort Hoare Linked Lists on:  ");
    linked_list_random.print();
    quick_sort_hoare(linked_list_random);
    Logger::status("Sorting result:                   ");
    linked_list_random.print();
    linked_list_random.clear();
    arena->reset();

    std::cout << "\n";

    linked_list_random = generate_random_linked_list(SIZE, MAX_VAL, arena);
    Logger::status("Mergesort Linked Lists on:        ");
    linked_list_random.print();
    merge_sort(linked_list_random);
    Logger::status("Sorting result:                   ");
    linked_list_random.print();
    linked_list_random.clear();
    arena->reset();

    return 0;
}
