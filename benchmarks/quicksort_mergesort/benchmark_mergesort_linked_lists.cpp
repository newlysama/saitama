#include "benchmark_config.hh"

#ifdef MERGE_SORT
#ifdef LINKED_LISTS

#ifdef RANDOM_LISTS
static void BM_LinkedListMergeSort_Random(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_random_linked_list(SIZE, MAX_VAL);
        merge_sort(list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedListMergeSort_Random);
#endif // RANDOM_LISTS

#ifdef SORTED_LISTS
static void BM_LinkedListMergeSort_Sorted(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_sorted_linked_list(SIZE);
        merge_sort(list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedListMergeSort_Sorted);
#endif // SORTED_LISTS

#ifdef REVERSED_LISTS
static void BM_LinkedListMergeSort_Reverse(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_reverse_sorted_linked_list(SIZE);
        merge_sort(list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedListMergeSort_Reverse);
#endif // REVERSED_LISTS

#endif // LINKED_LISTS
#endif // MERGE_SORT