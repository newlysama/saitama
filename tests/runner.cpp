#include <logger/logger.hh>

#ifdef TEST_LINKED_LISTS
#include "linked_lists/runner.cpp"
#endif

#ifdef TEST_QUICKSORT_MERGESORT
#include "quicksort_mergesort/runner.cpp"
#endif

int main() {
    Logger::status("<==== [ TEST SUITE]  ====>\n");

    #ifdef TEST_LINKED_LISTS
    test_linked_lists();
    #endif

    #ifdef TEST_QUICKSORT_MERGESORT
    test_quicksort_mergesort();
    #endif

    Logger::success("<==== [ ALL TESTS COMPLETED ] ====>");
    return 0;
}
