# 🚩 **BENCHMARK RESULTS**</br>

## Benchmark result for quicksort and mergesort algorithms, tested on 2M sized lists</br>

### 🚩 [ NOTE ] :

I've been running theese benchmarks on previous implementations of vectors and linked lists, which did not use our current
memory managment system (arena pools). It's a good occasion to check the performance improvment that allows custom memory managment.

### ▶️ Mergesort :

👉 Before arena pools :

```text
Algo                List Sorting        LinkedList          Vector
--------------------------------------------------------------------------------
MergeSort           Random              9.012 s             3.336 s
MergeSort           Reverse             7.821 s             3.024 s
MergeSort           Sorted              8.823 s             3.024 s
```

👉 After arena pools :

```text
Algo                List Sorting        LinkedList          Vector
--------------------------------------------------------------------------------
MergeSort           Random              2.577 s             6.835 s
MergeSort           Reverse             2.263 s             6.538 s
MergeSort           Sorted              3.016 s             6.689 s
```

### ▶️ Quicksort random pivot :

👉 Before arena pools :

```text
Algo                List Sorting        LinkedList          Vector
--------------------------------------------------------------------------------
QuickSortHoare      Random              4.818 s             0.815 s
QuickSortHoare      Reverse             4.100 s             0.684 s
QuickSortHoare      Sorted              3.958 s             0.848 s
QuickSortLomuto     Random              9.040 s             0.925 s
QuickSortLomuto     Reverse             8.935 s             0.619 s
QuickSortLomuto     Sorted              8.837 s             0.889 s
```

👉 After arena pools :

```text
Algo                List Sorting        LinkedList          Vector
--------------------------------------------------------------------------------
QuickSortHoare      Random              4.076 s             0.866 s
QuickSortHoare      Reverse             3.399 s             0.717 s
QuickSortHoare      Sorted              3.329 s             0.662 s
QuickSortLomuto     Random              5.985 s             0.963 s
QuickSortLomuto     Reverse             6.151 s             0.609 s
QuickSortLomuto     Sorted              5.825 s             0.867 s
```

### ▶️ Quicksort mid pivot :

👉 Before arena pools :

```text
Algo                List Sorting        LinkedList          Vector
--------------------------------------------------------------------------------
QuickSortHoare      Random              5.244 s             0.790 s
QuickSortHoare      Reverse             3.724 s             0.740 s
QuickSortHoare      Sorted              3.622 s             0.789 s
QuickSortLomuto     Random              9.535 s             0.949 s
QuickSortLomuto     Reverse             7.205 s             0.721 s
QuickSortLomuto     Sorted              6.845 s             0.854 s
```

👉 After arena pools :

```text
Algo                List Sorting        LinkedList          Vector
--------------------------------------------------------------------------------
QuickSortHoare      Random              4.737 s             0.834 s
QuickSortHoare      Reverse             3.373 s             0.780 s
QuickSortHoare      Sorted              3.258 s             0.693 s
QuickSortLomuto     Random              6.896 s             0.983 s
QuickSortLomuto     Reverse             5.211 s             0.775 s
QuickSortLomuto     Sorted              4.904 s             0.698 s
```