#include "benchmark_config.hh"
#include "custom_output.hh"
#include "benchmark_mergesort_linked_lists.cpp"
#include "benchmark_mergesort_vectors.cpp"
#include "benchmark_quicksort_linked_lists.cpp"
#include "benchmark_quicksort_vectors.cpp"

#include <benchmark/benchmark.h>

ScalableVector vector;
std::shared_ptr<MemoryManager::FixedArena> arena;

int main(int argc, char** argv) {
    // Define vector and arena
    auto arena_size = MemoryManager::compute_safe_allocation_size(sizeof(Node), SIZE);
    arena = MemoryManager::instance().create_fixed_arena(arena_size);
    vector.reserve(SIZE);

    benchmark::Initialize(&argc, argv);

    #ifdef USE_CUSTOM_REPORTER
        GenericGroupingReporter reporter;
        benchmark::RunSpecifiedBenchmarks(&reporter);
        reporter.Finalize();
    #else
        benchmark::RunSpecifiedBenchmarks();
    #endif

    return 0;
}
