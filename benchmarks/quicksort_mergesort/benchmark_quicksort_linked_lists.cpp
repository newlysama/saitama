#include "benchmark_config.hh"

using namespace Generator;

#ifdef QUICK_SORT
#ifdef LINKED_LISTS

#ifdef RANDOM_LISTS
static void BM_LinkedList_QuickSortLomuto_Random(benchmark::State& state) {
    for (auto _ : state) {
        LinkedList list = generate_random_linked_list(SIZE, MAX_VAL, raw_linked_list_arena);
        quick_sort_lomuto(list);
        benchmark::DoNotOptimize(list);
        list.clear();
    }

    MemoryManager::instance().reset_all();
}
BENCHMARK(BM_LinkedList_QuickSortLomuto_Random);

static void BM_LinkedList_QuickSortHoare_Random(benchmark::State& state) {
    for (auto _ : state) {
        LinkedList list = generate_random_linked_list(SIZE, MAX_VAL, raw_linked_list_arena);
        quick_sort_hoare(list);
        benchmark::DoNotOptimize(list);
        list.clear();
    }

    MemoryManager::instance().reset_all();
}
BENCHMARK(BM_LinkedList_QuickSortHoare_Random);
#endif

#ifdef SORTED_LISTS
static void BM_LinkedList_QuickSortLomuto_Sorted(benchmark::State& state) {
    for (auto _ : state) {
        LinkedList list = generate_sorted_linked_list(SIZE, raw_linked_list_arena);
        quick_sort_lomuto(list);
        benchmark::DoNotOptimize(list);
        list.clear();
    }

    MemoryManager::instance().reset_all();
}
BENCHMARK(BM_LinkedList_QuickSortLomuto_Sorted);

static void BM_LinkedList_QuickSortHoare_Sorted(benchmark::State& state) {
    for (auto _ : state) {
        LinkedList list = generate_sorted_linked_list(SIZE, raw_linked_list_arena);
        quick_sort_hoare(list);
        benchmark::DoNotOptimize(list);
        list.clear();
    }

    MemoryManager::instance().reset_all();
}
BENCHMARK(BM_LinkedList_QuickSortHoare_Sorted);
#endif

#ifdef REVERSED_LISTS
static void BM_LinkedList_QuickSortLomuto_Reverse(benchmark::State& state) {
    for (auto _ : state) {
        LinkedList list = generate_reverse_sorted_linked_list(SIZE, raw_linked_list_arena);
        quick_sort_lomuto(list);
        benchmark::DoNotOptimize(list);
        list.clear();
    }

    MemoryManager::instance().reset_all();
}
BENCHMARK(BM_LinkedList_QuickSortLomuto_Reverse);

static void BM_LinkedList_QuickSortHoare_Reverse(benchmark::State& state) {
    for (auto _ : state) {
        LinkedList list = generate_reverse_sorted_linked_list(SIZE, raw_linked_list_arena);
        quick_sort_hoare(list);
        benchmark::DoNotOptimize(list);
        list.clear();
    }

    MemoryManager::instance().reset_all();
}
BENCHMARK(BM_LinkedList_QuickSortHoare_Reverse);
#endif

#endif // LINKED_LISTS
#endif // QUICK_SORT
