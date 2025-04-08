# 🚩 **BENCHMARK RESULTS**</br>

## Benchmark result for quicksort and mergesort algorithms, tested on 2M sized lists</br>

### 🚩 [ NOTE ] :

I've been running theese benchmarks on previous implementations of vectors and linked lists, which did not use our current
memory managment system (arena pools). It's a good occasion to check the performance improvement that allows custom memory managment.
In our tables, before and after stand for "before/after arena pools".


### ▶️ MergeSort

```text
| Implementation | List Type | LinkedList (before) | LinkedList (after) | Vector (before)  | Vector (after)  |
|----------------|-----------|---------------------|--------------------|------------------|-----------------|
| MergeSort      | Random    | 9.012 s             | 2.577 s            | 3.336 s          | 6.835 s         |
| MergeSort      | Reversed  | 7.821 s             | 2.263 s            | 3.024 s          | 6.538 s         |
| MergeSort      | Sorted    | 8.823 s             | 3.010 s            | 3.024 s          | 6.538 s         |
```

### ▶️ QuickSort (Mid Pivot)

```text
| Implementation | List Type | LinkedList (before) | LinkedList (after) | Vector (before)  | Vector (after)  |
|----------------|-----------|---------------------|--------------------|------------------|-----------------|
| Hoare          | Random    | 5.538 s             | 1.999 s            | 2.002 s          | 2.001 s         |
| Lomuto         | Random    | 5.112 s             | 1.998 s            | 2.002 s          | 2.001 s         |
| Hoare          | Reversed  | 4.428 s             | 1.999 s            | 2.001 s          | 2.000 s         |
| Lomuto         | Reversed  | 4.227 s             | 1.999 s            | 2.001 s          | 2.000 s         |
| Hoare          | Sorted    | 4.436 s             | 2.000 s            | 2.000 s          | 2.000 s         |
| Lomuto         | Sorted    | 4.223 s             | 2.000 s            | 2.000 s          | 2.000 s         |
```

### ▶️ QuickSort (Random Pivot)

```text
| Implementation | List Type | LinkedList (before) | LinkedList (after) | Vector (before)  | Vector (after)  |
|----------------|-----------|---------------------|--------------------|------------------|-----------------|
| Hoare          | Random    | 5.431 s             | 1.998 s            | 2.002 s          | 2.001 s         |
| Lomuto         | Random    | 5.431 s             | 1.998 s            | 2.002 s          | 2.001 s         |
| Hoare          | Reversed  | 4.437 s             | 1.999 s            | 2.001 s          | 2.000 s         |
| Lomuto         | Reversed  | 4.437 s             | 1.999 s            | 2.001 s          | 2.000 s         |
| Hoare          | Sorted    | 4.437 s             | 2.000 s            | 2.000 s          | 2.000 s         |
| Lomuto         | Sorted    | 4.437 s             | 2.000 s            | 2.000 s          | 2.000 s         |
```

## 🚩 Performance improvements :

### ▶️ Mergesort on LinkedList : +70% speed

### ▶️ Quicksort on LinkedList : +60% speed

And i still need to work on vectors 👺