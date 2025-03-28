# Compiler and flags
CXX       = g++
CXXFLAGS += -std=c++17 -Wall -Wextra -Werror -pedantic
CXXFLAGS += -Wconversion -Wcast-align -Wunused -Wshadow
CXXFLAGS += -Wold-style-cast -Wpointer-arith
CXXFLAGS += -fsanitize=address
CXXFLAGS += -I$(UTILS_DIR)

# Folders
UTILS_DIR = utils
BUILD_DIR = build

# Utils sources and objs
UTILS_SRC = $(wildcard $(UTILS_DIR)/*.cpp)
UTILS_OBJ = $(patsubst $(UTILS_DIR)/%.cpp, $(BUILD_DIR)/utils_%.o, $(UTILS_SRC))

# Exercise to compile
EXO 		?=
EXO_SRC      = $(wildcard $(EXO)/*.cpp)
EXO_OBJ      = $(patsubst $(EXO)/%.cpp, $(BUILD_DIR)/$(EXO)_%.o, $(EXO_SRC))
TARGET       = main
TARGET_PATH  = ./$(TARGET)

all:
ifeq ($(EXO),)
	$(error Merci de spécifier un exercice avec EXO=nom_du_dossier)
endif
	@mkdir -p $(BUILD_DIR)
	$(MAKE) $(TARGET_PATH)

# Link final
$(TARGET_PATH): $(EXO_OBJ) $(UTILS_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile exercise sources
$(BUILD_DIR)/$(EXO)_%.o: $(EXO)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile utils sources
$(BUILD_DIR)/utils_%.o: $(UTILS_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean
