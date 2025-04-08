#include "benchmark_config.hh"
#include "custom_output.hh"
#include "benchmark_mergesort_linked_lists.cpp"
#include "benchmark_mergesort_vectors.cpp"
#include "benchmark_quicksort_linked_lists.cpp"
#include "benchmark_quicksort_vectors.cpp"

#include <benchmark/benchmark.h>

// Global arenas
std::shared_ptr<std::pmr::memory_resource> global_linked_list_arena;
std::pmr::memory_resource* raw_linked_list_arena = nullptr;

std::shared_ptr<std::pmr::memory_resource> global_vector_arena;
std::pmr::memory_resource* raw_vector_arena = nullptr;

int main(int argc, char** argv) {
    global_linked_list_arena = MemoryManager::instance().create_arena(size_t(SIZE * sizeof(Node)));
    raw_linked_list_arena = global_linked_list_arena.get();

    global_vector_arena = MemoryManager::instance().create_arena(size_t(SIZE * sizeof(size_t)));
    raw_vector_arena = global_vector_arena.get();

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
