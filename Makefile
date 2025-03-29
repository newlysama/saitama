# ===========================
# Compiler and flags
# ===========================
CXX       = g++
CXXFLAGS += -std=c++17 -Wall -Wextra -Werror -pedantic
CXXFLAGS += -Wconversion -Wcast-align -Wunused -Wshadow
CXXFLAGS += -Wold-style-cast -Wpointer-arith
CXXFLAGS += -fsanitize=address
CXXFLAGS += -I$(UTILS_DIR)

# ===========================
# Folders
# ===========================
UTILS_DIR = utils
BUILD_DIR = build

# ===========================
# UTILS SOURCES & OBJECTS
# ===========================
UTILS_SRC = $(shell find $(UTILS_DIR) -name "*.cpp")
UTILS_OBJ = $(patsubst $(UTILS_DIR)/%.cpp,$(BUILD_DIR)/utils_%.o,$(UTILS_SRC))

# ===========================
# EXERCISE BUILD
# ===========================
EXO         ?=
EXO_SRC     = $(wildcard $(EXO)/*.cpp)
EXO_OBJ     = $(patsubst $(EXO)/%.cpp, $(BUILD_DIR)/$(EXO)_%.o, $(EXO_SRC))
TARGET      = main
TARGET_PATH = ./$(TARGET)

# ===========================
# TEST BUILD
# ===========================
TEST        ?=
TEST_SRC    = $(TEST)/runner.cpp
TEST_OBJ    = $(patsubst $(TEST)/%.cpp, $(BUILD_DIR)/$(notdir $(TEST))_%.o, $(TEST_SRC))
TEST_BIN    = test
TEST_PATH   = ./$(TEST_BIN)

# ===========================
# DEFAULT BUILD: EXO
# ===========================
all:
ifeq ($(EXO),)
	$(error Merci de spécifier un exercice avec EXO=nom_du_dossier)
endif
	@mkdir -p $(BUILD_DIR)
	$(MAKE) $(TARGET_PATH)

# Link EXO binary
$(TARGET_PATH): $(EXO_OBJ) $(UTILS_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile exercise source files
$(BUILD_DIR)/utils_%.o: $(UTILS_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ===========================
# TESTING TARGET
# ===========================
test:
ifeq ($(TEST),)
	$(error Merci de spécifier un dossier de test avec TEST=chemin_du_dossier)
endif
	@mkdir -p $(BUILD_DIR)
	$(MAKE) $(TEST_PATH)

# Link test binary
$(TEST_PATH): $(TEST_OBJ) $(UTILS_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile test source files
$(BUILD_DIR)/$(notdir $(TEST))_%.o: $(TEST)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ===========================
# CLEAN
# ===========================
clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(TEST_BIN)

.PHONY: all clean test
