#include "test_selector.hh"

#ifdef TEST_EMPTY
#include "test_empty.cpp"
#endif

#ifdef TEST_INIT
#include "test_init.cpp"
#endif

#ifdef TEST_PUSH
#include "test_push.cpp"
#endif

#ifdef TEST_POP
#include "test_pop.cpp"
#endif

#ifdef TEST_GET
#include "test_get.cpp"
#endif

#ifdef TEST_SPLIT
#include "test_split.cpp"
#endif

#ifdef TEST_MERGE
#include "test_merge.cpp"
#endif

int main() {
    Logger::status("Running test runner...");

    #ifdef TEST_EMPTY
    Logger::status("➤ TEST_EMPTY:");
    test_empty_on_default_constructed_list();
    test_empty_on_list_after_all_pops();
    test_empty_false_after_push_front();
    test_empty_false_after_push_back();
    Logger::success("➤ TEST_EMPTY: ALL TESTS PASSED");
    #endif

    #ifdef TEST_INIT
    Logger::status("➤ TEST_INIT:");
    test_init_from_empty_vector();
    test_init_from_vector_single_element();
    test_init_from_vector_multiple_elements();
    Logger::success("➤ TEST_INIT: ALL TESTS PASSED");
    #endif

    #ifdef TEST_PUSH
    Logger::status("➤ TEST_PUSH:");
    test_push_front_single_element();
    test_push_front_multiple_elements_order();
    test_push_back_single_element();
    test_push_back_multiple_elements_order();
    test_push_front_and_back_combination();
    Logger::success("➤ TEST_PUSH: ALL TESTS PASSED");
    #endif

    #ifdef TEST_POP
    Logger::status("➤ TEST_POP:");
    test_pop_front_from_list_of_multiple_elements();
    test_pop_back_from_list_of_multiple_elements();
    test_pop_front_on_empty_list_returns_nullptr();
    test_pop_back_on_empty_list_returns_nullptr();
    test_pop_back_on_single_element_list();
    test_pop_front_on_single_element_list();
    Logger::success("➤ TEST_POP: ALL TESTS PASSED");
    #endif

    #ifdef TEST_GET
    Logger::status("➤ TEST_GET:");
    test_get_first_element();
    test_get_middle_element();
    test_get_last_element();
    test_get_out_of_bounds_returns_nullptr();
    Logger::success("➤ TEST_GET: ALL TESTS PASSED");
    #endif

    #ifdef TEST_SPLIT
    Logger::status("➤ TEST_SPLIT:");
    test_split_even_length_list_returns_two_equal_parts();
    test_split_odd_length_list_returns_correct_sizes();
    test_split_empty_list_returns_nullptr();
    test_split_single_element_list_returns_nullptr();
    test_split_preserves_order_in_both_parts();
    Logger::success("➤ TEST_SPLIT: ALL TESTS PASSED");
    #endif

    #ifdef TEST_MERGE
    Logger::status("➤ TEST_MERGE:");
    test_merge_two_sorted_lists();
    test_merge_with_one_list_empty();
    test_merge_with_both_lists_empty_returns_nullptr();
    test_merge_preserves_order_and_elements();
    test_merge_duplicates_are_preserved();
    Logger::success("➤ TEST_MERGE: ALL TESTS PASSED");
    #endif

    std::cout << "\n";
    Logger::success("✅ ALL SELECTED TESTS COMPLETED");
    return 0;
}
