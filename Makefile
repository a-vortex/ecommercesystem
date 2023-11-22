PROJECT_NAME := ecommercesystem

CXX = g++
CXXFLAGS = -std=c++17 -Wall

INC_DIR := include

SRC_DIR = src
TEST_DIR = test
BIN_DIR := bin
BUILD_DIR = build
CXXFLAGS += -Iinclude

EXECUTABLE = meu_programa

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*/*.cpp $(SRC_DIR)/*/*/*.cpp)
DEP_FILES := $(SRC_FILES:.cpp=.d)
OBJ_FILES := $(SRC_FILES:.cpp=.o)
TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)

TEST_EXECUTABLES := $(TEST_FILES:$(TEST_DIR)/%.cpp=$(BIN_DIR)/%)

$(BIN_DIR)/test_arquivo1: $(TEST_DIR)/Testebusca.cpp
    $(CXX) $(CXXFLAGS) -I$(INC_DIR) -Iinclude $< -o $@

$(BIN_DIR)/test_arquivo2: $(TEST_DIR)/Testecliente.cpp
    $(CXX) $(CXXFLAGS) -I$(INC_DIR) -Iinclude $< -o $@

-include $(addprefix $(BUILD_DIR)/,$(DEP_FILES))

run: $(BIN_DIR)/$(PROJECT_NAME)
	@LD_LIBRARY_PATH=$(MAIL_LIB_PATH) $(BIN_DIR)/$(PROJECT_NAME)

build: $(BIN_DIR)/$(PROJECT_NAME)

# Configuração das regras
all: $(BIN_DIR)/$(EXECUTABLE)

# Compilação do programa principal
$(BIN_DIR)/$(EXECUTABLE): $(OBJ_FILES)
    $(CXX) $(CXXFLAGS) $^ -o $@

# Compilação dos arquivos de origem (.cpp) para arquivos objeto (.o)
$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
    $(CXX) $(CXXFLAGS) -I$(INC_DIR) -MMD -c $< -o $@

# Execução dos testes
test: $(TEST_EXECUTABLES)

# Limpeza dos arquivos gerados
clean:
    rm -rf $(BUILD_DIR)/* $(BIN_DIR)/*

.PHONY: all test clean
