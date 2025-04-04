#include "benchmark_config.hh"

#ifdef QUICK_SORT
#ifdef VECTORS

#ifdef RANDOM_LISTS
static void BM_VectorQuickSortLomuto_Random(benchmark::State& state) {
    for (auto _ : state) {
        auto vector = generate_random_vector(SIZE, MAX_VAL);
        quick_sort_lomuto(vector);
        benchmark::DoNotOptimize(vector);
    }
}
BENCHMARK(BM_VectorQuickSortLomuto_Random);

static void BM_VectorQuickSortHoare_Random(benchmark::State& state) {
    for (auto _ : state) {
        auto vector = generate_random_vector(SIZE, MAX_VAL);
        quick_sort_hoare(vector);
        benchmark::DoNotOptimize(vector);
    }
}
BENCHMARK(BM_VectorQuickSortHoare_Random);
#endif // RANDOM_LISTS

#ifdef SORTED_LISTS
static void BM_VectorQuickSortLomuto_Sorted(benchmark::State& state) {
    for (auto _ : state) {
        auto vector = generate_sorted_vector(SIZE);
        quick_sort_lomuto(vector);
        benchmark::DoNotOptimize(vector);
    }
}
BENCHMARK(BM_VectorQuickSortLomuto_Sorted);

static void BM_VectorQuickSortHoare_Sorted(benchmark::State& state) {
    for (auto _ : state) {
        auto vector = generate_sorted_vector(SIZE);
        quick_sort_hoare(vector);
        benchmark::DoNotOptimize(vector);
    }
}
BENCHMARK(BM_VectorQuickSortHoare_Sorted);
#endif // SORTED_LISTS

#ifdef REVERSED_LISTS
static void BM_VectorMergeSort_Reverse(benchmark::State& state) {
    for (auto _ : state) {
        auto vector = generated_reverse_sorted_vector(SIZE);
        benchmark::DoNotOptimize(merge_sort(vector));
    }
}
BENCHMARK(BM_VectorMergeSort_Reverse);
#endif // REVERSED_LISTS

#endif // VECTORS
#endif // QUICK_SORT