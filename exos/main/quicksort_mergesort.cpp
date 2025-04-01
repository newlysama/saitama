#include <benchmark/benchmark.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <memory>

#include <linked_lists/linked_lists.hh>
#include <quicksort_mergesort/quick_sort.hh>
#include <quicksort_mergesort/merge_sort.hh>
#include <logger/logger.hh>

constexpr size_t SIZE = 50'000; // Taille des listes 
constexpr size_t MAX_VAL = 1'000'000;

std::vector<size_t> generate_random_data(size_t size, size_t min = 0, size_t max = MAX_VAL) {
    std::vector<size_t> list(size);
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<size_t> distrib(min, max);
    std::generate(list.begin(), list.end(), [&]() { return distrib(gen); });
    return list;
}

std::vector<size_t> generate_sorted_data(size_t size) {
    std::vector<size_t> list(size);
    std::iota(list.begin(), list.end(), 0);
    return list;
}

std::vector<size_t> generate_reverse_sorted_data(size_t size) {
    std::vector<size_t> list(size);
    std::iota(list.begin(), list.end(), 0);
    std::reverse(list.begin(), list.end());
    return list;
}

std::unique_ptr<LinkedList> generate_random_linked_list(size_t size, size_t min = 0, size_t max = MAX_VAL) {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<size_t> distrib(min, max);

    auto list = std::make_unique<LinkedList>();
    for (size_t i = 0; i < size; ++i) {
        list->push_back(distrib(gen));
    }
    return list;
}

std::unique_ptr<LinkedList> generate_sorted_linked_list(size_t size) {
    auto list = std::make_unique<LinkedList>();
    for (size_t i = 0; i < size; ++i) {
        list->push_back(i);
    }
    return list;
}

std::unique_ptr<LinkedList> generate_reverse_sorted_linked_list(size_t size) {
    auto list = std::make_unique<LinkedList>();
    for (size_t i = size; i > 0; --i) {
        list->push_back(i - 1);
    }
    return list;
}

// ---------------------------- VECTORS RANDOM ----------------------------

static void BM_VectorMergeSort_Random(benchmark::State& state) {
    for (auto _ : state) {
        auto data = generate_random_data(SIZE);
        benchmark::DoNotOptimize(merge_sort(data));
    }
}
BENCHMARK(BM_VectorMergeSort_Random);

static void BM_VectorQuickSortLomuto_Random(benchmark::State& state) {
    for (auto _ : state) {
        auto data = generate_random_data(SIZE);
        quick_sort_lomuto(data);
        benchmark::DoNotOptimize(data);
    }
}
BENCHMARK(BM_VectorQuickSortLomuto_Random);

static void BM_VectorQuickSortHoare_Random(benchmark::State& state) {
    for (auto _ : state) {
        auto data = generate_random_data(SIZE);
        quick_sort_hoare(data);
        benchmark::DoNotOptimize(data);
    }
}
BENCHMARK(BM_VectorQuickSortHoare_Random);

// ------------------------- LINKED LISTS RANDOM -------------------------

static void BM_LinkedListMergeSort_Random(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_random_linked_list(SIZE);
        benchmark::DoNotOptimize(merge_sort(std::move(list)));
    }
}
BENCHMARK(BM_LinkedListMergeSort_Random);

static void BM_LinkedListQuickSortLomuto_Random(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_random_linked_list(SIZE);
        quick_sort_lomuto(*list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedListQuickSortLomuto_Random);

static void BM_LinkedListQuickSortHoare_Random(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_random_linked_list(SIZE);
        quick_sort_hoare(*list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedListQuickSortHoare_Random);

// ---------------------------- VECTORS SORTED ----------------------------

static void BM_VectorMergeSort_Sorted(benchmark::State& state) {
    for (auto _ : state) {
        auto data = generate_sorted_data(SIZE);
        benchmark::DoNotOptimize(merge_sort(data));
    }
}
BENCHMARK(BM_VectorMergeSort_Sorted);

static void BM_VectorQuickSortLomuto_Sorted(benchmark::State& state) {
    for (auto _ : state) {
        auto data = generate_sorted_data(SIZE);
        quick_sort_lomuto(data);
        benchmark::DoNotOptimize(data);
    }
}
BENCHMARK(BM_VectorQuickSortLomuto_Sorted);

static void BM_VectorQuickSortHoare_Sorted(benchmark::State& state) {
    for (auto _ : state) {
        auto data = generate_sorted_data(SIZE);
        quick_sort_hoare(data);
        benchmark::DoNotOptimize(data);
    }
}
BENCHMARK(BM_VectorQuickSortHoare_Sorted);

// ------------------------- LINKED LISTS SORTED -------------------------

static void BM_LinkedListMergeSort_Sorted(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_sorted_linked_list(SIZE);
        benchmark::DoNotOptimize(merge_sort(std::move(list)));
    }
}
BENCHMARK(BM_LinkedListMergeSort_Sorted);

static void BM_LinkedListQuickSortLomuto_Sorted(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_sorted_linked_list(SIZE);
        quick_sort_lomuto(*list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedListQuickSortLomuto_Sorted);

static void BM_LinkedListQuickSortHoare_Sorted(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_sorted_linked_list(SIZE);
        quick_sort_hoare(*list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedListQuickSortHoare_Sorted);

// ---------------------------- VECTORS REVERSE ----------------------------

static void BM_VectorMergeSort_Reverse(benchmark::State& state) {
    for (auto _ : state) {
        auto data = generate_reverse_sorted_data(SIZE);
        benchmark::DoNotOptimize(merge_sort(data));
    }
}
BENCHMARK(BM_VectorMergeSort_Reverse);

static void BM_VectorQuickSortLomuto_Reverse(benchmark::State& state) {
    for (auto _ : state) {
        auto data = generate_reverse_sorted_data(SIZE);
        quick_sort_lomuto(data);
        benchmark::DoNotOptimize(data);
    }
}
BENCHMARK(BM_VectorQuickSortLomuto_Reverse);

static void BM_VectorQuickSortHoare_Reverse(benchmark::State& state) {
    for (auto _ : state) {
        auto data = generate_reverse_sorted_data(SIZE);
        quick_sort_hoare(data);
        benchmark::DoNotOptimize(data);
    }
}
BENCHMARK(BM_VectorQuickSortHoare_Reverse);

// ------------------------- LINKED LISTS REVERSE -------------------------

static void BM_LinkedListMergeSort_Reverse(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_reverse_sorted_linked_list(SIZE);
        benchmark::DoNotOptimize(merge_sort(std::move(list)));
    }
}
BENCHMARK(BM_LinkedListMergeSort_Reverse);

static void BM_LinkedListQuickSortLomuto_Reverse(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_reverse_sorted_linked_list(SIZE);
        quick_sort_lomuto(*list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedListQuickSortLomuto_Reverse);

static void BM_LinkedListQuickSortHoare_Reverse(benchmark::State& state) {
    for (auto _ : state) {
        auto list = generate_reverse_sorted_linked_list(SIZE);
        quick_sort_hoare(*list);
        benchmark::DoNotOptimize(list);
    }
}
BENCHMARK(BM_LinkedListQuickSortHoare_Reverse);

// ---------------------------- MAIN -----------------------------

BENCHMARK_MAIN();
