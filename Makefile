# =========================
#         COMPILER
# =========================

CXX       = g++
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
#    SOURCES MACCROS
# =========================

EXO_SRC   :=
UTILS_SRC :=
TEST_SRC  :=

include config.mk

# Delete doublons
EXO_SRC   := $(sort $(EXO_SRC))
UTILS_SRC := $(sort $(UTILS_SRC))
TEST_SRC  := $(sort $(TEST_SRC))

# =========================
#      OBJ FILES
# =========================

OBJ_EXO   = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(EXO_SRC))
OBJ_UTILS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(UTILS_SRC))
OBJ_TESTS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(TEST_SRC))

ALL_OBJ = $(OBJ_EXO) $(OBJ_UTILS)

# =========================
#        BINARIES
# =========================

EXE_NAME   = $(BIN_DIR)/main
TEST_NAME  = $(BIN_DIR)/test_runner

# =========================
#          RULES
# =========================

all: $(EXE_NAME)

test: $(TEST_NAME)

# =========================
#          LINK
# =========================

$(EXE_NAME): $(ALL_OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(TEST_NAME): $(OBJ_TESTS) $(OBJ_UTILS) $(OBJ_EXO)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# =========================
#         COMPILE
# =========================

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# =========================
#          RUN
# =========================

run:
	@echo "Running all executables in $(BIN_DIR)/"
	@for exe in $(BIN_DIR)/*; do \
		if [ -x $$exe ]; then \
			echo ""; \
			echo "Running $$exe:"; \
			./$$exe || exit $$?; \
		fi; \
	done

# =========================
#        CLEAN
# =========================

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all test clean
