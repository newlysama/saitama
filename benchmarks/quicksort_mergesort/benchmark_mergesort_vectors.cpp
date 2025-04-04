#include "benchmark_config.hh"

#ifdef MERGE_SORT
#ifdef VECTORS

#ifdef RANDOM_LISTS
static void BM_VectorMergeSort_Random(benchmark::State& state) {
    for (auto _ : state) {
        auto vector = generate_random_vector(SIZE, MAX_VAL);
        benchmark::DoNotOptimize(merge_sort(vector));
    }
}
BENCHMARK(BM_VectorMergeSort_Random);
#endif // RANDOM_LISTS

#ifdef SORTED_LISTS
static void BM_VectorMergeSort_Sorted(benchmark::State& state) {
    for (auto _ : state) {
        auto vector = generate_sorted_vector(SIZE);
        benchmark::DoNotOptimize(merge_sort(vector));
    }
}
BENCHMARK(BM_VectorMergeSort_Sorted);
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
#endif // MERGE_SORT