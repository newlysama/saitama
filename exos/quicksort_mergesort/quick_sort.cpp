// #include "quick_sort.hh"

// /*
//  *  ============================= LINKED LISTS =============================
// */

// // Lomuto

// void _quick_sort_lomuto(LinkedList& list, size_t low, size_t high) {
//     if (low >= high) return;

//     size_t pivot_index = list.partition_lomuto(low, high);

//     if (pivot_index > 0) {
//         _quick_sort_lomuto(list, low, pivot_index - 1);
//     }
//     _quick_sort_lomuto(list, pivot_index + 1, high);
// }

// void quick_sort_lomuto(LinkedList& list) {
//     if (list.size <= 1) return;

//     _quick_sort_lomuto(list, 0, list.size - 1);
// }

// // Hoare

// void _quick_sort_hoare(LinkedList& list, size_t low, size_t high) {
//     if (low >= high) {
//         return;
//     }

//     size_t pivot_index = list.partition_hoare(low, high);

//     _quick_sort_hoare(list, low, pivot_index);
//     _quick_sort_hoare(list, pivot_index + 1, high);
// }

// void quick_sort_hoare(LinkedList& list) {
//     if (list.size <= 1) {
//         return;
//     }

//     _quick_sort_hoare(list, 0, list.size - 1);
// }

// /*
//  *  ============================= VECTORS =============================
// */

// // Lomuto

// void _quick_sort_lomuto(std::vector<size_t>& list, size_t low, size_t high) {

//     if (list.size() <= 1 || low >= high) {
//         return;
//     }

//     size_t pivot_index = VectorUtils::partition_lomuto(list, low, high);

//     if (pivot_index > 0)
//         _quick_sort_lomuto(list, low, pivot_index - 1);
//     _quick_sort_lomuto(list, pivot_index + 1, high);
// }

// void quick_sort_lomuto(std::vector<size_t>& list) {
//     _quick_sort_lomuto(list, 0, list.size() - 1);
// }

// // Hoare

// void _quick_sort_hoare(std::vector<size_t>& list, size_t low, size_t high) {
//     if (list.size() <= 1) return;

//     if (low < high) {
//         size_t pivot_index = VectorUtils::partition_hoare(list, low, high);

//         _quick_sort_hoare(list, low, pivot_index);
//         _quick_sort_hoare(list, pivot_index + 1, high);
//     }
// }

// void quick_sort_hoare(std::vector<size_t>& list) {
//     _quick_sort_hoare(list, 0, list.size() - 1);
// }
