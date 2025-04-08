#include "benchmark_config.hh"
#include "custom_output.hh"
#include "benchmark_mergesort_linked_lists.cpp"
#include "benchmark_mergesort_vectors.cpp"
#include "benchmark_quicksort_linked_lists.cpp"
#include "benchmark_quicksort_vectors.cpp"

#include <benchmark/benchmark.h>

// Global arena
std::shared_ptr<std::pmr::memory_resource> global_arena;
std::pmr::memory_resource* raw_arena = nullptr;

int main(int argc, char** argv) {
    // Add 10% more memory than needed to ensure everything goes well
    global_arena = MemoryManager::instance().create_arena(size_t(SIZE * sizeof(Node)));
    raw_arena = global_arena.get();

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
