# 🚩 **BENCHMARK RESULTS**</br>

## Benchmark result for quicksort and mergesort algorithms, tested on 500k sized lists</br>

### 🚩 [ NOTE ] :

I've been running theese benchmarks on previous implementations of vectors and linked lists, which did not use our current
memory managment system (arena pools). It's a good occasion to check the performance improvment that allows custom memory managment.

### ▶️ Mergesort :

👉 Before arena pools :

```text
Algo                List Sorting        LinkedList          Vector
--------------------------------------------------------------------------------
MergeSort           Random              4.495 s             23.551 s
MergeSort           Reverse             5.782 s             53.355 s
MergeSort           Sorted              6.857 s             38.106 s
```

👉 After arena pools :

```text
Algo                List Sorting        LinkedList          Vector
--------------------------------------------------------------------------------
MergeSort           Random              0.640 s             1.587 s
MergeSort           Reverse             0.556 s             1.513 s
MergeSort           Sorted              0.731 s             1.518 s
```

### ▶️ Quicksort random pivot :

👉 Before arena pools :

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

👉 After arena pools :

```text
QuickSortHoare      Random              0.980 s             0.772 s
QuickSortHoare      Reverse             0.798 s             0.742 s
QuickSortHoare      Sorted              0.776 s             0.746 s
QuickSortLomuto     Random              1.406 s             0.805 s
QuickSortLomuto     Reverse             1.374 s             0.754 s
QuickSortLomuto     Sorted              1.429 s             0.717 s
```

### ▶️ Quicksort mid pivot :

👉 Before arena pools :

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

👉 After arena pools :

```text
QuickSortHoare      Random              1.094 s             0.694 s
QuickSortHoare      Reverse             0.788 s             0.813 s
QuickSortHoare      Sorted              0.769 s             0.686 s
QuickSortLomuto     Random              1.573 s             0.765 s
QuickSortLomuto     Reverse             1.205 s             0.716 s
QuickSortLomuto     Sorted              1.133 s             0.721 s
```