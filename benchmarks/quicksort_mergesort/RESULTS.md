# 🚩 **BENCHMARK RESULTS**</br>

## Benchmark result for quicksort and mergesort algorithms, tested on 500k sized lists</br>

### ▶️ Mergesort :

```text
Algo                List Sorting        LinkedList          Vector
--------------------------------------------------------------------------------
MergeSort           Random              4.495 s             23.551 s
MergeSort           Reverse             5.782 s             53.355 s
MergeSort           Sorted              6.857 s             38.106 s
```

### ▶️ Quicksort random pivot :

```text
Algo                List Sorting        LinkedList          Vector
--------------------------------------------------------------------------------
QuickSortHoare      Random              26.533 s            0.813 s
QuickSortHoare      Reverse             32.966 s            0.735 s
QuickSortHoare      Sorted              29.024 s            0.712 s
QuickSortLomuto     Random              29.942 s            0.874 s
QuickSortLomuto     Reverse             38.411 s            0.702 s
QuickSortLomuto     Sorted              33.809 s            0.657 s
```

### ▶️ Quicksort mid pivot :

```text
Algo                List Sorting        LinkedList          Vector
--------------------------------------------------------------------------------
QuickSortHoare      Random              27.380 s            0.876 s
QuickSortHoare      Reverse             30.905 s            0.673 s
QuickSortHoare      Sorted              27.651 s            0.762 s
QuickSortLomuto     Random              29.847 s            0.865 s
QuickSortLomuto     Reverse             33.080 s            0.690 s
QuickSortLomuto     Sorted              26.054 s            0.729 s
```