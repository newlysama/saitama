# =========================
#         MACCROS
# =========================

# Exercises
EXO_QUICKSORT_MERGESORT  := 1

# Tests ===> ONLY 1 TEST MACCRO ON AT THE TIME (otherwise, mulitple runner.cpp's, so multiple main definition)
TEST_LINKED_LISTS 	     := 0
TEST_QUICKSORT_MERGESORT := 1

# =========================
#       SOURCES INIT
# =========================

# Always include logger
UTILS_SRC += $(wildcard utils/logger/*.cpp)

# <============ EXERCISES ============>

ifeq ($(EXO_QUICKSORT_MERGESORT),1)
#  Don't include main.cpp if we are in testing mod, so we don't have 2 mains definitions
	ifneq ($(or $(TEST_LINKED_LISTS), $(TEST_QUICKSORT_MERGESORT)), 1)
		EXO_SRC += exos/main/quicksort_mergesort.cpp
	endif

	EXO_SRC   += $(wildcard exos/quicksort_mergesort/*.cpp)
	EXO_SRC   += exos/main/quicksort_mergesort.cpp
	UTILS_SRC += $(wildcard utils/linked_lists/*.cpp)
endif

# <============== TESTS ==============>

ifeq ($(TEST_LINKED_LISTS),1)
	UTILS_SRC += $(wildcard utils/linked_lists/*.cpp)
	TEST_SRC  += tests/linked_lists/runner.cpp
endif

ifeq ($(TEST_QUICKSORT_MERGESORT),1)
	EXO_SRC   += $(wildcard exos/quicksort_mergesort/*.cpp)
	UTILS_SRC += $(wildcard utils/linked_lists/*.cpp)
	TEST_SRC  += tests/quicksort_mergesort/runner.cpp
endif
