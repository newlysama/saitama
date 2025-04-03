#include <benchmark/benchmark.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>

#include <linked_lists/linked_lists.hh>
#include <linked_lists/linked_lists_algorithms.hh>
#include <quicksort_mergesort/quick_sort.hh>
#include <quicksort_mergesort/merge_sort.hh>
#include <quicksort_mergesort/benchmark_selector.hh>
#include <logger/logger.hh>

constexpr size_t SIZE = 10;
constexpr size_t MAX_VAL = 100;

std::vector<size_t> generate_random_vector(size_t size, size_t min = 0, size_t max = MAX_VAL) {
    std::vector<size_t> list(size);
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<size_t> distrib(min, max);
    std::generate(list.begin(), list.end(), [&]() { return distrib(gen); });
    return list;
}

std::vector<size_t> generate_sorted_vector(size_t size) {
    std::vector<size_t> list(size);
    std::iota(list.begin(), list.end(), 0);
    return list;
}

std::vector<size_t> generated_reverse_sorted_vector(size_t size) {
    std::vector<size_t> list(size);
    std::iota(list.begin(), list.end(), 0);
    std::reverse(list.begin(), list.end());
    return list;
}

LinkedList generate_random_linked_list(size_t size, size_t min = 0, size_t max = MAX_VAL) {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<size_t> distrib(min, max);

    LinkedList list;
    for (size_t i = 0; i < size; ++i) {
        list.push_back(distrib(gen));
    }
    return list;
}

LinkedList generate_sorted_linked_list(size_t size) {
    LinkedList list;
    for (size_t i = 0; i < size; ++i) {
        list.push_back(i);
    }
    return list;
}

LinkedList generate_reverse_sorted_linked_list(size_t size) {
    LinkedList list;
    for (size_t i = size; i > 0; --i) {
        list.push_back(i - 1);
    }
    return list;
}

#ifdef RANDOM_LISTS

// ---------------------------- VECTORS RANDOM ----------------------------

#ifdef VECTORS

static void BM_VectorMergeSort_Random(benchmark::State& state) {
    for (auto _ : state) {
        auto vector = generate_random_vector(SIZE);
        benchmark::DoNotOptimize(merge_sort(vector));
    }
}
BENCHMARK(BM_VectorMergeSort_Random);

static void BM_VectorQuickSortLomuto_Random(benchmark::State& state) {
    for (auto _ : state) {
        auto vector = generate_random_vector(SIZE);
        quick_sort_lomuto(vector);
        benchmark::DoNotOptimize(vector);
    }
}
BENCHMARK(BM_VectorQuickSortLomuto_Random);

static void BM_VectorQuickSortHoare_Random(benchmark::State& state) {
    for (auto _ : state) {
        auto vector = generate_random_vector(SIZE);
        quick_sort_hoare(vector);
        benchmark::DoNotOptimize(vector);
    }
}
BENCHMARK(BM_VectorQuickSortHoare_Random);

#endif // VECTORS

// ------------------------- LINKED LISTS RANDOM -------------------------

#ifdef LINKED_LISTS

static void BM_LinkedListMergeSort_Random(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_random_linked_list(SIZE, 0, SIZE_MAX);
        merge_sort(list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedListMergeSort_Random);

static void BM_LinkedListQuickSortLomuto_Random(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_random_linked_list(SIZE, 0, SIZE_MAX);
        quick_sort_lomuto(list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedListQuickSortLomuto_Random);

static void BM_LinkedListQuickSortHoare_Random(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_random_linked_list(SIZE, 0, SIZE_MAX);
        quick_sort_hoare(list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedListQuickSortHoare_Random);

#endif // LINKED_LISTS

#endif // RANDOM LIST

#ifdef SORTED_LISTS

// ---------------------------- VECTORS SORTED ----------------------------

#ifdef VECTORS

static void BM_VectorMergeSort_Sorted(benchmark::State& state) {
    for (auto _ : state) {
        auto vector = generate_sorted_vector(SIZE);
        benchmark::DoNotOptimize(merge_sort(vector));
    }
}
BENCHMARK(BM_VectorMergeSort_Sorted);

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

#endif // VECTORS

// ------------------------- LINKED LISTS SORTED -------------------------

#ifdef LINKED_LISTS

static void BM_LinkedListMergeSort_Sorted(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_sorted_linked_list(SIZE);
        merge_sort(list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedListMergeSort_Sorted);

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

#endif // LINKED_LISTS

#endif // SORTED_LISTS

#ifdef REVERSED_LISTS

// ---------------------------- VECTORS REVERSE ----------------------------

#ifdef VECTORS

static void BM_VectorMergeSort_Reverse(benchmark::State& state) {
    for (auto _ : state) {
        auto vector = generated_reverse_sorted_vector(SIZE);
        benchmark::DoNotOptimize(merge_sort(vector));
    }
}
BENCHMARK(BM_VectorMergeSort_Reverse);

static void BM_VectorQuickSortLomuto_Reverse(benchmark::State& state) {
    for (auto _ : state) {
        auto vector = generated_reverse_sorted_vector(SIZE);
        quick_sort_lomuto(vector);
        benchmark::DoNotOptimize(vector);
    }
}
BENCHMARK(BM_VectorQuickSortLomuto_Reverse);

static void BM_VectorQuickSortHoare_Reverse(benchmark::State& state) {
    for (auto _ : state) {
        auto vector = generated_reverse_sorted_vector(SIZE);
        quick_sort_hoare(vector);
        benchmark::DoNotOptimize(vector);
    }
}
BENCHMARK(BM_VectorQuickSortHoare_Reverse);

#endif // VECTORS

// ------------------------- LINKED LISTS REVERSE -------------------------

#ifdef LINKED_LISTS

static void BM_LinkedListMergeSort_Reverse(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_reverse_sorted_linked_list(SIZE);
        merge_sort(list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedListMergeSort_Reverse);

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

#endif // LINKED_LISTS

#endif // REVERSED_LISTS

// ---------------------------- MAIN -----------------------------

BENCHMARK_MAIN();
