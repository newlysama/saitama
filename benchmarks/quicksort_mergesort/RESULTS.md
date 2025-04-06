# 🚩 **BENCHMARK RESULTS**</br>

## Benchmark result for quicksort and mergesort algorithms, tested on 50k sized lists</br>

### ▶️ Mergesort on linked lists :

-------------------------------------------------------------------------</br>
Benchmark                               Time             CPU   Iterations</br>
-------------------------------------------------------------------------</br>
BM_LinkedListMergeSort_Random       0.313 s         0.301 s             2</br>
BM_LinkedListMergeSort_Sorted       0.396 s         0.381 s             2</br>
BM_LinkedListMergeSort_Reverse      0.283 s         0.272 s             2</br>

### ▶️ Mergesort on vectors :

---------------------------------------------------------------------</br>
Benchmark                           Time             CPU   Iterations</br>
---------------------------------------------------------------------</br>
BM_VectorMergeSort_Random       0.559 s         0.538 s             1</br>
BM_VectorMergeSort_Sorted       0.698 s         0.671 s             1</br>
BM_VectorMergeSort_Reverse      0.870 s         0.837 s             1</br>

### ▶️ Quicksort on linked lists, random pivot strategy :

-------------------------------------------------------------------------------</br>
Benchmark                                     Time             CPU   Iterations</br>
-------------------------------------------------------------------------------</br>
BM_LinkedListQuickSortLomuto_Random       0.866 s         0.832 s             1</br>
BM_LinkedListQuickSortHoare_Random        0.444 s         0.426 s             2</br>
BM_LinkedListQuickSortLomuto_Sorted       0.964 s         0.926 s             1</br>
BM_LinkedListQuickSortHoare_Sorted        0.413 s         0.397 s             2</br>
BM_LinkedListQuickSortLomuto_Reverse      0.994 s         0.955 s             1</br>
BM_LinkedListQuickSortHoare_Reverse       0.481 s         0.462 s             2</br>

### ▶️ Quicksort in linked lists, mid pivot strategy :

-------------------------------------------------------------------------------</br>
Benchmark                                     Time             CPU   Iterations</br>
-------------------------------------------------------------------------------</br>
BM_LinkedListQuickSortLomuto_Random       0.903 s         0.865 s             1</br>
BM_LinkedListQuickSortHoare_Random        0.491 s         0.472 s             2</br>
BM_LinkedListQuickSortLomuto_Sorted       0.729 s         0.700 s             1</br>
BM_LinkedListQuickSortHoare_Sorted        0.263 s         0.252 s             2</br>
BM_LinkedListQuickSortLomuto_Reverse      0.766 s         0.736 s             1</br>
BM_LinkedListQuickSortHoare_Reverse       0.267 s         0.257 s             2</br>

### ▶️ Quicksort in vectors, random pivot strategy :

--------------------------------------------------------------------------</br>
Benchmark                                Time             CPU   Iterations</br>
--------------------------------------------------------------------------</br>
BM_VectorQuickSortLomuto_Random      0.018 s         0.018 s            39</br>
BM_VectorQuickSortHoare_Random       0.015 s         0.015 s            47</br>
BM_VectorQuickSortLomuto_Sorted      0.015 s         0.014 s            49</br>
BM_VectorQuickSortHoare_Sorted       0.009 s         0.008 s            85</br>
BM_VectorMergeSort_Reverse           0.552 s         0.530 s             1</br>

### ▶️ Quicksort in vectors, mid pivot strategy :

--------------------------------------------------------------------------</br>
Benchmark                                Time             CPU   Iterations</br>
--------------------------------------------------------------------------</br>
BM_VectorQuickSortLomuto_Random      0.018 s         0.017 s            41</br>
BM_VectorQuickSortHoare_Random       0.014 s         0.013 s            52</br>
BM_VectorQuickSortLomuto_Sorted      0.010 s         0.010 s            71</br>
BM_VectorQuickSortHoare_Sorted       0.005 s         0.005 s           134</br>
BM_VectorMergeSort_Reverse           0.556 s         0.534 s             1</br>