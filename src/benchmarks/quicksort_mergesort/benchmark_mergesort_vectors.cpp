#include "benchmark_config.hh"

using namespace Generator;

#ifdef MERGE_SORT
#ifdef VECTORS

#ifdef RANDOM_LISTS
static void BM_Vector_MergeSort_Random(benchmark::State& state) {

    #ifdef USE_CUSTOM_REPORTER 
        Logger::status("Running: BM_Vector_MergeSort_Random...\n");
    #endif

    for (auto _ : state) {
        vector = generate_random_vector(SIZE, MAX_VAL);
        benchmark::DoNotOptimize(merge_sort(vector));
        vector.clear();
    }
}
BENCHMARK(BM_Vector_MergeSort_Random);
#endif // RANDOM_LISTS

#ifdef SORTED_LISTS
static void BM_Vector_MergeSort_Sorted(benchmark::State& state) {

    #ifdef USE_CUSTOM_REPORTER 
        Logger::status("Running: BM_Vector_MergeSort_Sorted...\n");
    #endif

    for (auto _ : state) {
        vector = generate_sorted_vector(SIZE);
        benchmark::DoNotOptimize(merge_sort(vector));
        vector.clear();
    }
}
BENCHMARK(BM_Vector_MergeSort_Sorted);
#endif // SORTED_LISTS

#ifdef REVERSED_LISTS
static void BM_Vector_MergeSort_Reverse(benchmark::State& state) {

    #ifdef USE_CUSTOM_REPORTER 
        Logger::status("Running: BM_Vector_MergeSort_Reverse...\n");
    #endif

    for (auto _ : state) {
        vector = generated_reverse_sorted_vector(SIZE);
        benchmark::DoNotOptimize(merge_sort(vector));
        vector.clear();
    }
}
BENCHMARK(BM_Vector_MergeSort_Reverse);
#endif // REVERSED_LISTS

#endif // VECTORS
#endif // MERGE_SORT
