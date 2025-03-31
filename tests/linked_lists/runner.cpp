#include <logger/logger.hh>

// Inclure tous les fichiers de tests
#include "test_empty.cpp"
#include "test_init.cpp"
#include "test_push.cpp"
#include "test_pop.cpp"
#include "test_get.cpp"
#include "test_swap.cpp"
#include "test_split.cpp"
#include "test_merge.cpp"
#include "test_concat.cpp"
#include "test_partition.cpp"

int test_linked_lists() {
    Logger::status("[RUNNING] [ LINKED LISTS TESTS ]\n");

    Logger::status("[RUNNING] TEST_EMPTY:");
    test_empty_on_default_constructed_list();
    test_empty_on_list_after_all_pops();
    test_empty_false_after_push_front();
    test_empty_false_after_push_back();
    Logger::success("[PASSED] TEST_EMPTY\n");

    Logger::status("[RUNNING] TEST_INIT:");
    test_init_from_empty_vector();
    test_init_from_vector_single_element();
    test_init_from_vector_multiple_elements();
    Logger::success("[PASSED] TEST_INIT\n");

    Logger::status("[RUNNING] TEST_PUSH:");
    test_push_front_single_element();
    test_push_front_multiple_elements_order();
    test_push_back_single_element();
    test_push_back_multiple_elements_order();
    test_push_front_and_back_combination();
    Logger::success("[PASSED] TEST_PUSH\n");

    Logger::status("[RUNNING] TEST_POP:");
    test_pop_front_from_list_of_multiple_elements();
    test_pop_back_from_list_of_multiple_elements();
    test_pop_front_on_empty_list_throws();
    test_pop_back_on_empty_list_throws();
    test_pop_back_on_single_element_list();
    test_pop_front_on_single_element_list();
    Logger::success("[PASSED] TEST_POP\n");

    Logger::status("[RUNNING] TEST_GET:");
    test_get_first_element();
    test_get_middle_element();
    test_get_last_element();
    test_get_out_of_bounds_throws();
    Logger::success("[PASSED] TEST_GET\n");

    Logger::status("[RUNNING] TEST_SWAP_VALUES:");
    test_swap_values_two_elements();
    test_swap_values_middle_elements();
    test_swap_values_first_and_last();
    test_swap_values_invalid_indices_throws();
    Logger::success("[PASSED] TEST_SWAP_VALUES\n");

    Logger::status("[RUNNING] TEST_SPLIT:");
    test_split_even_length_list_returns_two_equal_parts();
    test_split_odd_length_list_returns_correct_sizes();
    test_split_empty_list_throws();
    test_split_single_element_list_throws();
    test_split_preserves_order_in_both_parts();
    test_split_at_index_custom();
    Logger::success("[PASSED] TEST_SPLIT\n");

    Logger::status("[RUNNING] TEST_SPLIT_AROUND_PIVOT");
    test_split_around_pivot_middle();
    test_split_around_pivot_zero();
    test_split_around_pivot_last();
    test_split_around_pivot_invalid();
    Logger::success("[PASSED] TEST_SPLIT_AROUND_PIVOT\n");

    Logger::status("[RUNNING] TEST_MERGE:");
    test_merge_two_sorted_lists();
    test_merge_with_one_list_empty();
    test_merge_with_both_lists_empty();
    test_merge_preserves_order_and_elements();
    test_merge_duplicates_are_preserved();
    Logger::success("[PASSED] TEST_MERGE\n");

    Logger::status("[RUNNING] TEST_CONCAT:");
    test_concat_two_non_empty_lists();
    test_concat_with_first_list_empty();
    test_concat_with_second_list_empty();
    test_concat_with_both_empty_returns_empty_list();
    Logger::success("[PASSED] TEST_CONCAT\n");

    Logger::status("[RUNNING] TEST_PARTITION:");
    test_partition_lomuto_basic_case();
    test_partition_lomuto_sorted_list();
    test_partition_lomuto_reverse_list();
    test_partition_hoare_basic_case();
    test_partition_hoare_sorted_list();
    test_partition_hoare_reverse_list();
    Logger::success("[PASSED] TEST_PARTITION\n");

    Logger::success("[ ALL LINKED_LISTS TESTS COMPLETED ]\n");
    return 0;
}
