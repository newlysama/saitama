# ===========================================================================
#         					 MACCROS
# ===========================================================================

# <============ EXERCISES ============>
EXO_QUICKSORT_MERGESORT		:= 0

# <============== TESTS ==============>
TEST_ON						:= 1
TEST_LINKED_LISTS			:= 1
TEST_QUICKSORT_MERGESORT	:= 0




# ===========================================================================
#       					SOURCES INIT
# ===========================================================================

# Always include logger
UTILS_SRC += $(wildcard utils/logger/*.cpp)

# <============ EXERCISES ============>

ifeq ($(EXO_QUICKSORT_MERGESORT),1)
#  Don't include main.cpp if we are in testing mod, so we don't have 2 mains definitions
	ifneq ($(TEST_ON), 1)
		EXO_SRC += exos/main/quicksort_mergesort.cpp
	endif

	EXO_SRC		+= $(wildcard exos/quicksort_mergesort/*.cpp)
	UTILS_SRC 	+= $(wildcard utils/linked_lists/*.cpp) utils/tools.cpp
	CXXFLAGS += -O2 -lbenchmark -lpthread
endif

# <============== TESTS ==============>

# Maccro that links TEST maccros to our cpp program
TEST_DEFINES :=

ifeq ($(TEST_LINKED_LISTS),1)
	TEST_SRC 		+= tests/runner.cpp
	TEST_DEFINES 	+= -DTEST_LINKED_LISTS
	UTILS_SRC 		+= $(wildcard utils/linked_lists/*.cpp)
endif

ifeq ($(TEST_QUICKSORT_MERGESORT),1)
	TEST_SRC 		+= tests/runner.cpp
	TEST_DEFINES 	+= -DTEST_QUICKSORT_MERGESORT
	EXO_SRC 		+= $(wildcard exos/quicksort_mergesort/*.cpp)
	UTILS_SRC 		+= $(wildcard utils/linked_lists/*.cpp)
endif

