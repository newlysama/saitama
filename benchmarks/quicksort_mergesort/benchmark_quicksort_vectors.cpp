#include "benchmark_config.hh"

using namespace Generator;

#ifdef QUICK_SORT
#ifdef VECTORS

#ifdef RANDOM_LISTS
static void BM_Vector_QuickSortLomuto_Random(benchmark::State& state) {

    #ifdef USE_CUSTOM_REPORTER 
        Logger::status("Running: BM_Vector_QuickSortLomuto_Random...\n");
    #endif

    for (auto _ : state) {
        vector = generate_random_vector(SIZE, MAX_VAL);
        quick_sort_lomuto(vector);
        benchmark::DoNotOptimize(vector);
        vector.clear();
    }
}
BENCHMARK(BM_Vector_QuickSortLomuto_Random);

static void BM_Vector_QuickSortHoare_Random(benchmark::State& state) {

    #ifdef USE_CUSTOM_REPORTER 
        Logger::status("Running: BM_Vector_QuickSortHoare_Random...\n");
    #endif

    for (auto _ : state) {
        vector = generate_random_vector(SIZE, MAX_VAL);
        quick_sort_hoare(vector);
        benchmark::DoNotOptimize(vector);
        vector.clear();
    }
}
BENCHMARK(BM_Vector_QuickSortHoare_Random);
#endif // RANDOM_LISTS

#ifdef SORTED_LISTS
static void BM_Vector_QuickSortLomuto_Sorted(benchmark::State& state) {

    #ifdef USE_CUSTOM_REPORTER 
        Logger::status("Running: BM_Vector_QuickSortLomuto_Sorted...\n");
    #endif

    for (auto _ : state) {
        vector = generate_sorted_vector(SIZE);
        quick_sort_lomuto(vector);
        benchmark::DoNotOptimize(vector);
        vector.clear();
    }
}
BENCHMARK(BM_Vector_QuickSortLomuto_Sorted);

static void BM_Vector_QuickSortHoare_Sorted(benchmark::State& state) {

    #ifdef USE_CUSTOM_REPORTER 
        Logger::status("Running: BM_Vector_QuickSortHoare_Sorted...\n");
    #endif

    for (auto _ : state) {
        vector = generate_sorted_vector(SIZE);
        quick_sort_hoare(vector);
        benchmark::DoNotOptimize(vector);
        vector.clear();
    }
}
BENCHMARK(BM_Vector_QuickSortHoare_Sorted);
#endif // SORTED_LISTS

#ifdef REVERSED_LISTS
static void BM_Vector_QuickSortLomuto_Reverse(benchmark::State& state) {

    #ifdef USE_CUSTOM_REPORTER 
        Logger::status("Running: BM_Vector_QuickSortLomuto_Reverse...\n");
    #endif

    for (auto _ : state) {
        vector = generated_reverse_sorted_vector(SIZE);
        quick_sort_lomuto(vector);
        benchmark::DoNotOptimize(vector);
        vector.clear();
    }
}
BENCHMARK(BM_Vector_QuickSortLomuto_Reverse);

static void BM_Vector_QuickSortHoare_Reverse(benchmark::State& state) {

    #ifdef USE_CUSTOM_REPORTER 
        Logger::status("Running: M_Vector_QuickSortHoare_Reverse...\n");
    #endif

    for (auto _ : state) {
        vector = generated_reverse_sorted_vector(SIZE);
        quick_sort_hoare(vector);
        benchmark::DoNotOptimize(vector);
        vector.clear();
    }
}
BENCHMARK(BM_Vector_QuickSortHoare_Reverse);
#endif // REVERSED_LISTS

#endif // VECTORS
#endif // QUICK_SORT
