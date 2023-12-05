PROJECT_NAME := ecommercesystem

CXX = g++
CXXFLAGS = -std=c++17 -Wall

ST_LIB_PATH := ../ecommercesystem/build

INC_DIR = include

SRC_DIR := src
TEST_DIR := test/sys

BIN_DIR := bin
BUILD_DIR := build

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*/*.cpp $(SRC_DIR)/*/*/*.cpp)
TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)

DEP_FILES := $(SRC_FILES:.cpp=.d)
DEP_FILES += $(TEST_FILES:.cpp=.d)

OBJ_SRC_FILES := $(SRC_FILES:.cpp=.o)
OBJ_TEST_FILES := $(TEST_FILES:.cpp=.o)

-include $(addprefix $(BUILD_DIR)/,$(DEP_FILES))

$(BIN_DIR)/inicial: $(addprefix $(BUILD_DIR)/,$(OBJ_SRC_FILES))
	@echo "🔧 Building executable 'inicial' ..."
	@mkdir -p $(BIN_DIR)
	@$(CXX) $(CXXFLAGS) $^ -o $@

run: $(BIN_DIR)/inicial
	@LD_LIBRARY_PATH=$(ST_LIB_PATH) $(BIN_DIR)/inicial

build: $(BUILD_DIR)/$(PROJECT_NAME)

$(BUILD_DIR)/$(PROJECT_NAME): $(addprefix $(BUILD_DIR)/,$(OBJ_SRC_FILES))
	@echo "🔧 Preparing library ..."
	@mkdir -p $(BUILD_DIR)
	@$(CXX) -shared $^ -o $(BUILD_DIR)/$(PROJECT_NAME)

$(BUILD_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "🏛️ Building $< ..."
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -D STORAGE_DIR=\"$(STORAGE_DIR)\" -MMD -MP -c $< -o $@ -fPIC
""
$(BUILD_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	@echo "🔨 Building test object $< ..."
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -D STORAGE_DIR=\"$(STORAGE_DIR)\" -MMD -MP -c $< -o $@ -fPIC

TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)
TEST_FILES += test/sys/testebusca.cpp
TEST_FILES += test/sys/testeestoque.cpp
TEST_FILES += test/sys/testepagamento.cpp
TEST_FILES += test/sys/testeproduto.cpp

TEST_OBJ_FILES := $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/$(TEST_DIR)/%.o,$(TEST_FILES))

DEP_FILES += $(TEST_OBJ_FILES:.o=.d)

TEST_EXECUTABLE := $(BIN_DIR)/test/$(PROJECT_NAME)_test

$(TEST_EXECUTABLE): $(TEST_OBJ_FILES) $(addprefix $(BUILD_DIR)/,$(OBJ_SRC_FILES))
	@echo "🔨 Building test executable $@ ..."
	@mkdir -p $(BIN_DIR)/test
	@$(CXX) $(CXXFLAGS) $^ -o $@ -L$(ST_LIB_PATH)

test: $(TEST_EXECUTABLE)
	@echo "🧪 Running tests ..."
	@LD_LIBRARY_PATH=$(ST_LIB_PATH) $(TEST_EXECUTABLE)

.PHONY: test clean

clean:
	@echo "🧹 Cleaning ..."
	@rm -rf $(BUILD_DIR) $(BIN_DIR)