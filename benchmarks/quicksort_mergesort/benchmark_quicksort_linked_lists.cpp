#include "benchmark_config.hh"

#ifdef QUICK_SORT
#ifdef LINKED_LISTS

#ifdef RANDOM_LISTS
static void BM_LinkedList_QuickSortLomuto_Random(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_random_linked_list(SIZE, MAX_VAL);
        quick_sort_lomuto(list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedList_QuickSortLomuto_Random);

static void BM_LinkedList_QuickSortHoare_Random(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_random_linked_list(SIZE, MAX_VAL);
        quick_sort_hoare(list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedList_QuickSortHoare_Random);
#endif // RANDOM_LISTS

#ifdef SORTED_LISTS
static void BM_LinkedList_QuickSortLomuto_Sorted(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_sorted_linked_list(SIZE);
        quick_sort_lomuto(list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedList_QuickSortLomuto_Sorted);

static void BM_LinkedList_QuickSortHoare_Sorted(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_sorted_linked_list(SIZE);
        quick_sort_hoare(list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedList_QuickSortHoare_Sorted);
#endif // SORTED_LISTS

#ifdef REVERSED_LISTS
static void BM_LinkedList_QuickSortLomuto_Reverse(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_reverse_sorted_linked_list(SIZE);
        quick_sort_lomuto(list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedList_QuickSortLomuto_Reverse);

static void BM_LinkedList_QuickSortHoare_Reverse(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_reverse_sorted_linked_list(SIZE);
        quick_sort_hoare(list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedList_QuickSortHoare_Reverse);
#endif // REVERSED_LISTS

#endif // LINKED_LISTS
#endif // QUICK_SORT
