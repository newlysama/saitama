# =========================
#         COMPILER
# =========================

CXX       = g++
CXXFLAGS :=
CXXFLAGS += -std=c++17 -Wall -Wextra -Werror -pedantic
CXXFLAGS += -Wconversion -Wcast-align -Wunused -Wshadow
CXXFLAGS += -Wold-style-cast -Wpointer-arith
CXXFLAGS += -fsanitize=address
CXXFLAGS += -Iutils -Iexos

# =========================
#        FOLDERS
# =========================

BUILD_DIR = build
BIN_DIR   = bin

# =========================
#      SOURCE MACROS
# =========================

EXO_SRC   	 :=
UTILS_SRC 	 :=
TEST_SRC  	 :=
TEST_DEFINES :=

include config.mk

# =========================
#  REMOVE DUPLICATES
# =========================

EXO_SRC   := $(sort $(EXO_SRC))
UTILS_SRC := $(sort $(UTILS_SRC))
TEST_SRC  := $(sort $(TEST_SRC))

# =========================
#     OBJECTS & BINARY
# =========================

OBJ_EXO    = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(EXO_SRC))
OBJ_UTILS  = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(UTILS_SRC))
OBJ_TESTS  = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(TEST_SRC))

EXE_NAME   = $(BIN_DIR)/main
TEST_NAME  = $(BIN_DIR)/test_runner

# =========================
#         TARGETS
# =========================

all: $(EXE_NAME)

test: $(TEST_NAME)

run:
	@echo "Running all executables in $(BIN_DIR)/"
	@for exe in $(BIN_DIR)/*; do \
		if [ -x $$exe ]; then \
			echo ""; \
			echo "Running $$exe:"; \
			./$$exe || exit $$?; \
		fi; \
	done

run-benchmark:
	./bin/main --benchmark_format=console --benchmark_time_unit=s

# =========================
#         LINK
# =========================

$(EXE_NAME): $(OBJ_EXO) $(OBJ_UTILS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(TEST_NAME): $(OBJ_TESTS) $(OBJ_UTILS) $(OBJ_EXO)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(TEST_DEFINES) $^ -o $@

# =========================
#       COMPILE RULE
# =========================

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(TEST_DEFINES) -c $< -o $@



clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all test clean run
