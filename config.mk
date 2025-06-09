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
EXO_QUICKSORT_MERGESORT			:= 1

# BENCHMARK
BENCHMARK_QUICKSORT_MERGESORT	:= 1

# TESTS
# Test Utils
TEST_LINKED_LISTS				:= 1
TEST_VECTOR_UTILS				:= 1

# Test Exercises
TEST_QUICKSORT_MERGESORT		:= 1

# ================================================================
#       			    LINK LIBS/INCLUDES
# ================================================================

CXXFLAGS += -Iexternal/include
LDFLAGS  += -Lexternal/lib -ltbb -ltbbmalloc


# Always include logger
UTILS_SRC += $(wildcard src/utils/logger/*.cpp) $(wildcard src/utils/memory_manager/*.cpp)

# ================================================================
#       			EXERCISES SOURCES
# ================================================================

# QUICKSORT MERGESORT
ifeq ($(EXO_ON),1)

	ifeq ($(EXO_QUICKSORT_MERGESORT),1)
		EXO_SRC		+= src/exos/mains/quicksort_mergesort.cpp
		EXO_SRC		+= $(wildcard src/exos/quicksort_mergesort/*.cpp)
		UTILS_SRC	+= $(wildcard src/utils/vector_utils/*.cpp) $(wildcard src/utils/generator/*.cpp)
	endif

endif

# ================================================================
#       			BENCHMARKS SOURCES
# ================================================================

ifeq ($(BENCHMARK_ON),1)
	CXXFLAGS += -O3
	LDFLAGS  += -lbenchmark -lbenchmark_main -lpthread

	ifeq ($(BENCHMARK_QUICKSORT_MERGESORT),1)
		BENCHMARK_SRC	+= src/benchmarks/quicksort_mergesort/benchmark_runner.cpp
		EXO_SRC			+= $(wildcard src/exos/quicksort_mergesort/*.cpp)
		UTILS_SRC		+= $(wildcard src/utils/vector_utils/*.cpp) $(wildcard src/utils/generator/*.cpp)
	endif

endif

# ================================================================
#       			 TESTS SOURCES
# ================================================================

ifeq ($(TEST_ON),1)
#	Only use fsanitize in tests, since this options drastically reduces perfs.
	CXXFLAGS += -fsanitize=address
	LDFLAGS  += -lgtest -lgtest_main -pthread

	ifeq ($(TEST_LINKED_LISTS),1)
		TEST_SRC	+= $(wildcard src/tests/linked_lists/*.cpp)
	endif

	ifeq ($(TEST_VECTOR_UTILS),1)
		TEST_SRC	+= $(wildcard src/tests/vector_utils/*.cpp)
		UTILS_SRC	+= $(wildcard src/utils/vector_utils/*.cpp)
	endif

	ifeq ($(TEST_QUICKSORT_MERGESORT),1)
		TEST_SRC	+= $(wildcard src/tests/quicksort_mergesort/*.cpp)
		EXO_SRC		+= $(wildcard src/exos/quicksort_mergesort/*.cpp)
		UTILS_SRC	+= $(wildcard src/utils/vector_utils/*.cpp)
	endif

endif