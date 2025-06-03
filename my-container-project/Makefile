# =====================================================================
# Makefile for MyContainer Project (Updated for src-only structure)
#
# Usage:
#   make Main      # Build and run the demo (Main.cpp)
#   make test      # Build and run all unit tests
#   make valgrind  # Run unit tests with valgrind for memory leak check
#   make clean     # Remove all build artifacts and binaries
#
# Directory structure:
#   src/    - All header and implementation files (hpp/cpp)
#   tests/  - Unit tests
#
# Notes:
# - All .cpp/.hpp files are in src/.
# - You can add more source files to src/ as needed.
# =====================================================================

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -Isrc
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

# Automatically find all .cpp files in src
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
SRC_OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

MAIN_SRC = $(SRC_DIR)/Main.cpp
MAIN_OBJ = $(BUILD_DIR)/Main.o
MAIN_BIN = Main

TEST_SRC = $(TEST_DIR)/MyContainerTests.cpp
TEST_OBJ = $(BUILD_DIR)/MyContainerTests.o
TEST_BIN = MyContainerTests

all: $(MAIN_BIN)

$(BUILD_DIR):
	@if [ ! -d $(BUILD_DIR) ]; then mkdir -p $(BUILD_DIR); fi

$(MAIN_BIN): $(BUILD_DIR) $(SRC_OBJS) $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(MAIN_OBJ) $(SRC_OBJS)

$(MAIN_OBJ): $(MAIN_SRC) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(BUILD_DIR) $(TEST_OBJ) $(SRC_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_BIN) $(TEST_OBJ) $(SRC_OBJS)
	./$(TEST_BIN)

$(TEST_OBJ): $(TEST_SRC) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

Main: $(MAIN_BIN)
	./$(MAIN_BIN)

valgrind: test
	valgrind --leak-check=full ./$(TEST_BIN)

clean:
	rm -rf $(BUILD_DIR) $(MAIN_BIN) $(TEST_BIN)

.PHONY: all test Main valgrind clean
