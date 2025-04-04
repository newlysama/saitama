#include "benchmark_config.hh"

#ifdef QUICK_SORT
#ifdef LINKED_LISTS

#ifdef RANDOM_LISTS
static void BM_LinkedListQuickSortLomuto_Random(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_random_linked_list(SIZE, MAX_VAL);
        quick_sort_lomuto(list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedListQuickSortLomuto_Random);

static void BM_LinkedListQuickSortHoare_Random(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_random_linked_list(SIZE, MAX_VAL);
        quick_sort_hoare(list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedListQuickSortHoare_Random);
#endif // RANDOM_LISTS

#ifdef SORTED_LISTS
static void BM_LinkedListQuickSortLomuto_Sorted(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_sorted_linked_list(SIZE);
        quick_sort_lomuto(list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedListQuickSortLomuto_Sorted);

static void BM_LinkedListQuickSortHoare_Sorted(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_sorted_linked_list(SIZE);
        quick_sort_hoare(list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedListQuickSortHoare_Sorted);
#endif // SORTED_LISTS

#ifdef REVERSED_LISTS
static void BM_LinkedListQuickSortLomuto_Reverse(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_reverse_sorted_linked_list(SIZE);
        quick_sort_lomuto(list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedListQuickSortLomuto_Reverse);

static void BM_LinkedListQuickSortHoare_Reverse(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_reverse_sorted_linked_list(SIZE);
        quick_sort_hoare(list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedListQuickSortHoare_Reverse);
#endif // REVERSED_LISTS

#endif // LINKED_LISTS
#endif // QUICK_SORT