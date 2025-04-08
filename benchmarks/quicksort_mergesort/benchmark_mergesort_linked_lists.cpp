#include "benchmark_config.hh"

using namespace Generator;

#ifdef MERGE_SORT
#ifdef LINKED_LISTS

#ifdef RANDOM_LISTS
static void BM_LinkedList_MergeSort_Random(benchmark::State& state) {
    for (auto _ : state) {
        LinkedList list = generate_random_linked_list(SIZE, MAX_VAL, raw_arena);
        merge_sort(list);
        benchmark::DoNotOptimize(list);
        list.clear();
    }

    MemoryManager::instance().reset_all();
}
BENCHMARK(BM_LinkedList_MergeSort_Random);
#endif

#ifdef SORTED_LISTS
static void BM_LinkedList_MergeSort_Sorted(benchmark::State& state) {
    for (auto _ : state) {
        LinkedList list = generate_sorted_linked_list(SIZE, raw_arena);
        merge_sort(list);
        benchmark::DoNotOptimize(list);
        list.clear();
    }

    MemoryManager::instance().reset_all();
}
BENCHMARK(BM_LinkedList_MergeSort_Sorted);
#endif

#ifdef REVERSED_LISTS
static void BM_LinkedList_MergeSort_Reverse(benchmark::State& state) {
    for (auto _ : state) {
        LinkedList list = generate_reverse_sorted_linked_list(SIZE, raw_arena);
        merge_sort(list);
        benchmark::DoNotOptimize(list);
        list.clear();
    }

    MemoryManager::instance().reset_all();
}
BENCHMARK(BM_LinkedList_MergeSort_Reverse);
#endif

#endif // LINKED_LISTS
#endif // MERGE_SORT
