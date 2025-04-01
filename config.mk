# ===========================================================================
#         					 MACCROS
# ===========================================================================

# <============ EXERCISES ============>
EXO_QUICKSORT_MERGESORT		:= 1

# <============== TESTS ==============>
TEST_ON						:= 0

# Test Utils
TEST_LINKED_LISTS			:= 0
TEST_VECTOR_UTILS           := 0

# Test Exercises
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
	UTILS_SRC 	+= $(wildcard utils/linked_lists/*.cpp) $(wildcard utils/vector_utils/*.cpp)
endif

# <============== TESTS ==============>

# Maccro that links TEST maccros to our cpp program
TEST_DEFINES :=

ifeq ($(TEST_LINKED_LISTS),1)
	TEST_SRC        += tests/test_utils.cpp  
	TEST_SRC 		+= $(wildcard tests/linked_lists/*.cpp)
	UTILS_SRC 		+= $(wildcard utils/linked_lists/*.cpp)
endif

ifeq ($(TEST_VECTOR_UTILS),1)
	TEST_SRC 		+= $(wildcard tests/vector_utils/*.cpp)
	UTILS_SRC 		+= $(wildcard utils/vector_utils/*.cpp)
endif

ifeq ($(TEST_QUICKSORT_MERGESORT),1)
	TEST_SRC        += tests/test_utils.cpp  
	TEST_SRC 		+= $(wildcard tests/quicksort_mergesort/*.cpp)
	EXO_SRC 		+= $(wildcard exos/quicksort_mergesort/*.cpp)
	UTILS_SRC 		+= $(wildcard utils/linked_lists/*.cpp) $(wildcard utils/vector_utils/*.cpp)
endif

