# ================================================================
#       				MODES CHECKING
# ================================================================

# Check that exactly 1 mode is specified (if for some reason we mess with the Makefile)
MODES := $(EXO_ON) $(BENCHMARK_ON) $(TEST_ON)

ACTIVE_MODE_COUNT := $(words $(filter 1,$(MODES)))

ifeq ($(ACTIVE_MODE_COUNT),0)
$(error Please select a building mode in config.mk.)
else ifneq ($(ACTIVE_MODE_COUNT),1)
$(error Too much building modes activated in config.mk: please select only one.)
endif



# ================================================================
#       			    SOURCES SELECTION
# ================================================================

# EXERCISE
EXO_QUICKSORT_MERGESORT		  := 1

# BENCHMARK
BENCHMARK_QUICKSORT_MERGESORT := 1

# TESTS
# Test Utils
TEST_LINKED_LISTS			  := 1
TEST_VECTOR_UTILS             := 1

# Test Exercises
TEST_QUICKSORT_MERGESORT	  := 1


# Always include logger
UTILS_SRC += $(wildcard utils/logger/*.cpp)

# ================================================================
#       			EXERCISES SOURCES
# ================================================================

# QUICKSORT MERGESORT
ifeq ($(EXO_ON),1)

	ifeq ($(EXO_QUICKSORT_MERGESORT),1)
		EXO_SRC   += exos/mains/quicksort_mergesort.cpp
		EXO_SRC   += $(wildcard exos/quicksort_mergesort/*.cpp)
		UTILS_SRC += $(wildcard utils/linked_lists/*.cpp) $(wildcard utils/vector_utils/*.cpp) $(wildcard utils/tools/*.cpp)
	endif

endif

# ================================================================
#       			BENCHMARKS SOURCES
# ================================================================

ifeq ($(BENCHMARK_ON),1)

	ifeq ($(BENCHMARK_QUICKSORT_MERGESORT),1)
		BENCHMARK_SRC += $(wildcard benchmarks/quicksort_mergesort/*.cpp)
		EXO_SRC		  += $(wildcard exos/quicksort_mergesort/*.cpp)
		UTILS_SRC 	  += $(wildcard utils/linked_lists/*.cpp) $(wildcard utils/vector_utils/*.cpp) $(wildcard utils/tools/*.cpp)
	endif

endif

# ================================================================
#       			 TESTS SOURCES
# ================================================================

ifeq ($(TEST_ON),1)

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

endif

