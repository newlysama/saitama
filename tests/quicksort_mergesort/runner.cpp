#include <logger/logger.hh>

#include "test_selector.hh"

#if defined(TEST_MERGE_SORT_LINKED_LISTS) || defined(TEST_MERGE_SORT_VECTORS)
#include "test_merge_sort.cpp"
#endif

#ifdef TEST_QUICK_SORT
#include "test_quick_sort.cpp"
#endif

int main() {
    Logger::status("Running merge_sort tests...");

    // VECTOR-BASED TESTS
    #ifdef TEST_MERGE_SORT_VECTORS
    Logger::status("===> TEST_MERGE_SORT_VECTORS:");
    test_vector_split_even_size();
    test_vector_split_odd_size();
    test_vector_split_empty_throws();
    test_vector_merge_sorted_inputs();
    test_vector_merge_with_duplicates();
    test_vector_merge_sort_unsorted_input();
    test_vector_merge_sort_stability_and_duplicates();
    Logger::success("===> TEST_MERGE_SORT_VECTORS: ALL TESTS PASSED");
    #endif

    // LINKED LIST-BASED TESTS
    #ifdef TEST_MERGE_SORT_LINKED_LISTS
    Logger::status("===> TEST_MERGE_LINKED_LISTS:");
    test_linkedlist_merge_sort_already_sorted();
    test_linkedlist_merge_sort_reverse_order();
    test_linkedlist_merge_sort_with_duplicates();
    test_linkedlist_merge_sort_single_element();
    test_linkedlist_merge_sort_empty_list();
    Logger::success("===> TEST_MERGE_LINKED_LISTS: ALL TESTS PASSED");
    #endif

    std::cout << "\n";
    Logger::success("<==== ALL SELECTED TESTS COMPLETED ====>");
    return 0;
}
