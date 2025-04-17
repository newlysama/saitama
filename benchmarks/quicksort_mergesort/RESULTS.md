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
-----------------------------------------------------------------------------------------------------------------------------------------------
|    Algorithm     | List Type |     LinkedList     |    LinkedList      |   LinkedList     |    Vectors     |    Vectors     |   Vectors     |
|                  |           |      (no MM)       |      (PMR)         |     (Bump)       |    (no MM)     |     (PMR)      |  (Scalable)   |
|------------------|:---------:|:------------------:|:------------------:|:----------------:|:--------------:|:--------------:|:-------------:|
|   MergeSort      |  Random   |     4.501 s        |     2.577 s        |    0.558 s       |    23.053 s    |    6.835 s     |   0.576 s     |
|   MergeSort      | Reversed  |     5.735 s        |     2.263 s        |    0.602 s       |    53.078 s    |    6.538 s     |   0.847 s     |
|   MergeSort      |  Sorted   |     6.772 s        |     3.010 s        |    0.516 s       |    37.552 s    |    6.538 s     |   0.851 s     |
| QuickSort Hoare  |  Random   |     26.531 s       |     4.038 s        |    0.841 s       |    0.638 s     |    0.817 s     |   0.747 s     |
| QuickSort Hoare  | Reversed  |     33.232 s       |     3.185 s        |    0.601 s       |    0.714 s     |    0.690 s     |   0.694 s     |
| QuickSort Hoare  |  Sorted   |     28.564 s       |     3.243 s        |    0.615 s       |    0.717 s     |    0.632 s     |   0.690 s     |
| QuickSort Lomuto |  Random   |     29.341 s       |     6.246 s        |    1.358 s       |    0.626 s     |    0.923 s     |   0.753 s     |
| QuickSort Lomuto | Reversed  |     37.445 s       |     5.760 s        |    1.280 s       |    0.723 s     |    0.591 s     |   0.694 s     |
| QuickSort Lomuto |  Sorted   |     33.647 s       |     5.728 s        |    1.264 s       |    0.719 s     |    0.811 s     |   0.710 s     |
-----------------------------------------------------------------------------------------------------------------------------------------------
```