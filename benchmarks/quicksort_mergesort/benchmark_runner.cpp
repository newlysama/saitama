#include "benchmark_config.hh"
#include "custom_output.hh"
#include "benchmark_mergesort_linked_lists.cpp"
#include "benchmark_mergesort_vectors.cpp"
#include "benchmark_quicksort_linked_lists.cpp"
#include "benchmark_quicksort_vectors.cpp"

#include <benchmark/benchmark.h>

int main(int argc, char** argv) {
    benchmark::Initialize(&argc, argv);
    GenericGroupingReporter reporter;
    benchmark::RunSpecifiedBenchmarks(&reporter);
    reporter.Finalize();
}