# =========================
#         COLORS
# =========================

COLOR_RESET  = \033[0m
COLOR_GREEN  = \033[1;32m
COLOR_BLUE   = \033[1;34m
COLOR_PURPLE = \033[1;35m
COLOR_RED    = \033[1;31m
COLOR_YELLOW = \033[1;33m

# =========================
#   DETECT TARGET MODE
# =========================

EXO_ON         ?= 1
BENCHMARK_ON   ?= 0
TEST_ON        ?= 0

ifeq ($(MAKECMDGOALS),test)
	EXO_ON := 0
	TEST_ON := 1
endif

ifeq ($(MAKECMDGOALS),benchmark)
	EXO_ON := 0
	BENCHMARK_ON := 1
endif

export EXO_ON
export BENCHMARK_ON
export TEST_ON

# =========================
#         COMPILER
# =========================

CXX       = clang++
CXXFLAGS += -std=c++20 -Wall -Wextra -pedantic
CXXFLAGS += -Wno-sign-compare -Wno-self-move
CXXFLAGS += -Isrc

# =========================
#        FOLDERS
# =========================

BUILD_DIR = build
BIN_DIR   = bin

# =========================
#      SOURCE MACROS
# =========================

EXO_SRC       :=
BENCHMARK_SRC :=
UTILS_SRC     :=
TEST_SRC      :=

include config.mk

EXO_SRC        := $(sort $(EXO_SRC))
BENCHMARK_SRC  := $(sort $(BENCHMARK_SRC))
UTILS_SRC      := $(sort $(UTILS_SRC))
TEST_SRC       := $(sort $(TEST_SRC))

# =========================
#     OBJECTS & BINARY
# =========================

OBJ_EXO        = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(EXO_SRC))
OBJ_BENCHMARK  = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(BENCHMARK_SRC))
OBJ_UTILS      = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(UTILS_SRC))
OBJ_TESTS      = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(TEST_SRC))

EXE_NAME       = $(BIN_DIR)/main
BENCHMARK_NAME = $(BIN_DIR)/benchmark
TEST_NAME      = $(BIN_DIR)/test_runner

# =========================
#         TARGETS
# =========================

all: $(EXE_NAME)

benchmark: $(BENCHMARK_NAME)

test: $(TEST_NAME)

# =========================
#         LINK
# =========================

$(EXE_NAME): $(OBJ_EXO) $(OBJ_UTILS)
	@mkdir -p $(BIN_DIR)
	@echo "$(COLOR_GREEN)[LD]$(COLOR_RESET) $@"
	@$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

$(BENCHMARK_NAME): $(OBJ_BENCHMARK) $(OBJ_EXO) $(OBJ_UTILS)
	@mkdir -p $(BIN_DIR)
	@echo "$(COLOR_GREEN)[LD]$(COLOR_RESET) $@"
	@$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

$(TEST_NAME): $(OBJ_TESTS) $(OBJ_UTILS) $(OBJ_EXO)
	@mkdir -p $(BIN_DIR)
	@echo "$(COLOR_GREEN)[LD]$(COLOR_RESET) $@"
	@$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

# =========================
#       COMPILE RULE
# =========================

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "$(COLOR_BLUE)[CXX]$(COLOR_RESET) $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# =========================
#        RULES
# =========================

run:
	@echo "$(COLOR_YELLOW)Running all executables in $(BIN_DIR)/$(COLOR_RESET)"
	@for exe in $(BIN_DIR)/*; do \
		if [ -x $$exe ]; then \
			echo ""; \
			echo "$(COLOR_PURPLE)> Running $$exe$(COLOR_RESET)"; \
			LD_LIBRARY_PATH=./external/lib ./$$exe || exit $$?; \
		fi; \
	done

run-benchmark:
	@LD_LIBRARY_PATH=./external/lib ./bin/benchmark --benchmark_format=console --benchmark_time_unit=s

valgrind-benchmark:
	@valgrind --tool=massif LD_LIBRARY_PATH=./external/lib ./$(BENCHMARK_NAME) --benchmark_format=console --benchmark_time_unit=s

clean:
	@echo "$(COLOR_RED)[CLEAN]$(COLOR_RESET) Removing build and bin directories..."
	@rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all benchmark test clean run
