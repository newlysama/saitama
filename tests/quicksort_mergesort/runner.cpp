#include "test_merge_sort.cpp"
#include "test_quick_sort_lomuto.cpp"
#include "test_quick_sort_hoare.cpp"

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

    Logger::status("[RUNNING] TEST_MERGE_SORT_LINKED_LISTS");
    test_linkedlist_merge_sort_already_sorted();
    test_linkedlist_merge_sort_reverse_order();
    test_linkedlist_merge_sort_with_duplicates();
    test_linkedlist_merge_sort_single_element();
    test_linkedlist_merge_sort_empty_list();
    Logger::success("[PASSED] TEST_MERGE_LINKED_LISTS\n");

    Logger::status("[RUNNING] [ QUICK SORT TESTS ]\n");

    Logger::status("[RUNNING] TEST_QUICKSORT_LOMUTO_VECTOR:");
    test_partition_lomuto_basic();
    test_partition_lomuto_sorted_input();
    test_partition_lomuto_duplicates();
    test_quick_sort_vector_lomuto_sorted_input();
    test_quick_sort_vector_lomuto_reverse_input();
    test_quick_sort_vector_lomuto_with_duplicates();
    test_quick_sort_vector_lomuto_random();
    Logger::success("[PASSED] TEST_QUICKSORT_LOMUTO_VECTOR\n");

    Logger::status("[RUNNING] TEST_QUICKSORT_HOARE_VECTOR:");
    test_partition_hoare_basic();
    test_partition_hoare_sorted();
    test_partition_hoare_duplicates();
    test_quick_sort_vector_hoare_sorted_input();
    test_quick_sort_vector_hoare_reverse_input();
    test_quick_sort_vector_hoare_with_duplicates();
    test_quick_sort_vector_hoare_random();
    Logger::success("[PASSED] TEST_QUICKSORT_HOARE_VECTOR\n");


    Logger::status("[RUNNING] TEST_QUICKSORT_LOMUTO_LINKED_LISTS:");
    test_quick_sort_lomuto_empty_list();
    test_quick_sort_lomuto_single_element();
    test_quick_sort_lomuto_sorted_input();
    test_quick_sort_lomuto_reverse_input();
    test_quick_sort_lomuto_duplicates();
    test_quick_sort_lomuto_random_input();
    Logger::success("[PASSED] TEST_QUICKSORT_LOMUTO_LINKED_LISTS\n");

    Logger::status("[RUNNING] TEST_QUICK_SORT_HOARE_LINKED_LISTS:");
    test_quick_sort_hoare_empty_list();
    test_quick_sort_hoare_single_element();
    test_quick_sort_hoare_sorted_input();
    test_quick_sort_hoare_reverse_input();
    test_quick_sort_hoare_with_duplicates();
    test_quick_sort_hoare_random_input();
    Logger::success("[PASSED] TEST_QUICK_SORT_HOARE\n");

    Logger::success("[ ALL QUICKSORT_MERGESORT TESTS COMPLETED ]\n");
    return 0;
}
