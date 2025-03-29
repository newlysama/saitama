#include "test_merge_sort.cpp"
#include "test_quick_sort.cpp"

int test_quicksort_mergesort() {
    Logger::status("[RUNNING] [ MERGE SORT TESTS ]\n");

    Logger::status("[RUNNING] TEST_MERGE_SORT_VECTORS:");
    test_vector_split_even_size();
    test_vector_split_odd_size();
    test_vector_split_empty_throws();
    test_vector_merge_sorted_inputs();
    test_vector_merge_with_duplicates();
    test_vector_merge_sort_unsorted_input();
    test_vector_merge_sort_stability_and_duplicates();
    Logger::success("[PASSED] TEST_MERGE_SORT_VECTORS\n");

    Logger::status("[RUNNING] TEST_MERGE_LINKED_LISTS");
    test_linkedlist_merge_sort_already_sorted();
    test_linkedlist_merge_sort_reverse_order();
    test_linkedlist_merge_sort_with_duplicates();
    test_linkedlist_merge_sort_single_element();
    test_linkedlist_merge_sort_empty_list();
    Logger::success("[PASSED] TEST_MERGE_LINKED_LISTS\n");

    Logger::success("[ ALL QUICKSORT_MERGESORT TESTS COMPLETED ]\n");
    return 0;
}
