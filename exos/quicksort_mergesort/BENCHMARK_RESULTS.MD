# BENCHMARK RESULTS

Here you can find some of the benchmark results I managed to get for my quick sort and merge sort algorithms,
depending on the data structure and the type of list (random elements, sorted, reverse sorted).

### Random pivot strategy (matters for quicksort)

-------------------------------------------------------------------------------
Benchmark                                     Time             CPU   Iterations
-------------------------------------------------------------------------------
BM_VectorMergeSort_Random                  1.30 s          1.25 s             1
BM_VectorQuickSortLomuto_Random           0.038 s         0.036 s            19
BM_VectorQuickSortHoare_Random            0.031 s         0.030 s            23
BM_LinkedListMergeSort_Random             0.889 s         0.851 s             1
BM_LinkedListQuickSortLomuto_Random        2.15 s          2.06 s             1
BM_LinkedListQuickSortHoare_Random         1.20 s          1.15 s             1
BM_VectorMergeSort_Sorted                  2.44 s          2.34 s             1
BM_VectorQuickSortLomuto_Sorted           0.030 s         0.029 s            25
BM_VectorQuickSortHoare_Sorted            0.017 s         0.016 s            43
BM_LinkedListMergeSort_Sorted              1.46 s          1.40 s             1
BM_LinkedListQuickSortLomuto_Sorted        2.40 s          2.30 s             1
BM_LinkedListQuickSortHoare_Sorted         1.38 s          1.33 s             1
BM_VectorMergeSort_Reverse                 3.71 s          3.56 s             1
BM_VectorQuickSortLomuto_Reverse          0.033 s         0.031 s            23
BM_VectorQuickSortHoare_Reverse           0.020 s         0.019 s            37
BM_LinkedListMergeSort_Reverse             1.47 s          1.40 s             1
BM_LinkedListQuickSortLomuto_Reverse       3.28 s          3.13 s             1
BM_LinkedListQuickSortHoare_Reverse        2.06 s          1.96 s             1

