# =========================
#   DETECT TARGET MODE
# =========================

# Default mode : EXO

EXO_ON			?= 1
BENCHMARK_ON	?= 0
TEST_ON			?= 0

ifeq ($(MAKECMDGOALS),test)
	EXO_ON := 0
	TEST_ON := 1
endif

ifeq ($(MAKECMDGOALS),benchmark)
	EXO_ON := 0
	BENCHMARK_ON := 1
endif

# Declare modes to config.mk
export EXO_ON
export BENCHMARK_ON
export TEST_ON

# =========================
#         COMPILER
# =========================

CXX			= g++
CXXFLAGS 	+= -std=c++17 -Wall -Wextra -Werror -pedantic
CXXFLAGS 	+= -Wconversion -Wcast-align -Wunused -Wshadow
CXXFLAGS 	+= -Wold-style-cast -Wpointer-arith
CXXFLAGS 	+= -fsanitize=address
CXXFLAGS 	+= -I.

# =========================
#        FOLDERS
# =========================

BUILD_DIR = build
BIN_DIR   = bin

# =========================
#      SOURCE MACROS
# =========================

EXO_SRC   	  :=
BENCHMARK_SRC :=
UTILS_SRC 	  :=
TEST_SRC  	  :=

include config.mk

# =========================
#  REMOVE DUPLICATES
# =========================

EXO_SRC			:= $(sort $(EXO_SRC))
BENCHMARK_SRC	:= $(sort $(BENCHMARK_SRC))
UTILS_SRC		:= $(sort $(UTILS_SRC))
TEST_SRC		:= $(sort $(TEST_SRC))

# =========================
#     OBJECTS & BINARY
# =========================

OBJ_EXO			= $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(EXO_SRC))
OBJ_BENCHMARK	= $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(BENCHMARK_SRC))
OBJ_UTILS		= $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(UTILS_SRC))
OBJ_TESTS		= $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(TEST_SRC))

EXE_NAME		= $(BIN_DIR)/main
BENCHMARK_NAME	= $(BIN_DIR)/benchmark
TEST_NAME		= $(BIN_DIR)/test_runner

# =========================
#         TARGETS
# =========================

all: $(EXE_NAME)

benchmark : $(BENCHMARK_NAME)

test: $(TEST_NAME)

# =========================
#         LINK
# =========================

$(EXE_NAME): $(OBJ_EXO) $(OBJ_UTILS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BENCHMARK_NAME): $(OBJ_BENCHMARK) $(OBJ_EXO) $(OBJ_UTILS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -O2 -lbenchmark -lpthread $^ -o $@

$(TEST_NAME): $(OBJ_TESTS) $(OBJ_UTILS) $(OBJ_EXO)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -lgtest -lgtest_main -pthread -o $@

# =========================
#       COMPILE RULE
# =========================

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# =========================
#        RULES
# =========================

# Run all executables in bin/
run:
	@echo "Running all executables in $(BIN_DIR)/"
	@for exe in $(BIN_DIR)/*; do \
		if [ -x $$exe ]; then \
			echo ""; \
			echo "Running $$exe:"; \
			./$$exe || exit $$?; \
		fi; \
	done

# Force seconds as benchmark time unit
run-benchmark:
	./bin/benchmark --benchmark_format=console --benchmark_time_unit=s

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all test clean run
