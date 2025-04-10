# 🚩 **BENCHMARK RESULTS**</br>

## Benchmark result for quicksort and mergesort algorithms, tested on 2M sized lists</br>

### 🚩 [ NOTE ] :

I've been running theese benchmarks on previous implementations of vectors and linked lists.
It's a good occasion to see how we improved performance over time.

**no MM    :** For "no memory managment". A time where I wasn't doing any sort of custom memory managment 😎   
**PMR      :** For "pmr::monotic_buffer_resource" implementation, a library allowing, among other things, to pre-allocate a chunk of memory to work on.   
**Bump     :** For "custom bump allocator" implementation, a simple (but fully custom) memory managment system (very effective as you will see).   
**Scalable :** For "tbb::scalable_allocator" implementation, which stands for oneTBB scalable allocator, used to manager my vectors memory.   

```text
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|    Algorithm     | List Type |     LinkedList     |    LinkedList      |   LinkedList     | Perf. Impr |    Vectors     |    Vectors     |   Vectors     |  Perf Impr. |
|                  |           |      (no MM)       |      (PMR)         |     (Bump)       |     LL     |    (no MM)     |     (PMR)      |  (Scalable)   |   Vectors   |
|------------------|:---------:|:------------------:|:------------------:|:----------------:|:----------:|:--------------:|:--------------:|:-------------:|:-----------:|
|   MergeSort      |  Random   |     9.012 s        |     2.577 s        |    0.558 s       |   x16.2    |    3.336 s     |    6.835 s     |   0.576 s     |    x5.8     |
|   MergeSort      | Reversed  |     7.821 s        |     2.263 s        |    0.602 s       |   x13.0    |    3.024 s     |    6.538 s     |   0.847 s     |    x3.6     |
|   MergeSort      |  Sorted   |     8.823 s        |     3.010 s        |    0.516 s       |   x17.1    |    3.024 s     |    6.538 s     |   0.851 s     |    x3.5     |
| QuickSort Hoare  |  Random   |     5.538 s        |     1.999 s        |    0.841 s       |   x6.6     |    2.002 s     |    2.001 s     |   0.747 s     |    x2.7     |
| QuickSort Hoare  | Reversed  |     4.428 s        |     1.999 s        |    0.601 s       |   x7.4     |    2.001 s     |    2.000 s     |   0.694 s     |    x2.9     |
| QuickSort Hoare  |  Sorted   |     4.436 s        |     2.000 s        |    0.615 s       |   x7.2     |    2.000 s     |    2.000 s     |   0.690 s     |    x2.9     |
| QuickSort Lomuto |  Random   |     5.112 s        |     1.998 s        |    1.358 s       |   x3.8     |    2.002 s     |    2.001 s     |   0.753 s     |    x2.7     |
| QuickSort Lomuto | Reversed  |     4.227 s        |     1.999 s        |    1.280 s       |   x3.3     |    2.001 s     |    2.000 s     |   0.694 s     |    x2.9     |
| QuickSort Lomuto |  Sorted   |     4.223 s        |     2.000 s        |    1.264 s       |   x3.3     |    2.000 s     |    2.000 s     |   0.710 s     |    x2.8     |
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
```