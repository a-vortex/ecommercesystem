PROJECT_NAME := ecommercesystem

CXX = g++
CXXFLAGS = -std=c++17 -Wall

INC_DIR = include

SRC_DIR := src
TEST_DIR := test 
TEST_EXECUTABLES := $(TEST_FILES:$(TEST_DIR)/%.cpp=$(BIN_DIR)/%)

BIN_DIR := bin
BUILD_DIR := build

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*/*.cpp $(SRC_DIR)/*/*/*.cpp)
TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp $(TEST_DIR)/*/*.cpp $(TEST_DIR)/*/*/*.cpp)

DEP_FILES := $(SRC_FILES:.cpp=.d)
DEP_FILES += $(TEST_FILES:.cpp=.d)

OBJ_SRC_FILES := $(SRC_FILES:.cpp=.o)
OBJ_TEST_FILES := $(TEST_FILES:.cpp=.o)

-include $(addprefix $(BUILD_DIR)/,$(DEP_FILES))

run: $(BIN_DIR)/$(PROJECT_NAME)
	@LD_LIBRARY_PATH=$(BUILD_DIR) $(BIN_DIR)/$(PROJECT_NAME)

build: $(BUILD_DIR)/$(PROJECT_NAME)

$(BUILD_DIR)/$(PROJECT_NAME): $(addprefix $(BUILD_DIR)/,$(OBJ_SRC_FILES))
	@echo "🔧 Preparing library ..."
	@mkdir -p $(BUILD_DIR)
	@$(CXX) -shared $^ -o $(BUILD_DIR)/$(PROJECT_NAME)

test: $(TEST_EXECUTABLES)

$(BIN_DIR)/test: $(addprefix $(BUILD_DIR)/,$(OBJ_TEST_FILES))
	@echo "🔧 Preparing test suite ..."
	@mkdir -p $(BIN_DIR)
	@$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "🏛️ Building $< ..."
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -D STORAGE_DIR=\"$(STORAGE_DIR)\" -MMD -MP -c $< -o $@ -fPIC

$(BUILD_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	@echo "🏛️ Building $< ..."
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) $(DOCTEST) -D STORAGE_DIR=\"$(STORAGE_DIR)\" -MMD -MP -c $< -o $@ -fPIC

clean:
	@echo "🧹 Cleaning ..."
	@rm -rf $(BUILD_DIR) $(BIN_DIR)


# INC_DIR := include

# TEST_DIR := src/test
# BIN_DIR := bin
# CXXFLAGS += -Iinclude

# EXECUTABLE = meu_programa

# SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*/*.cpp $(SRC_DIR)/*/*/*.cpp)
# DEP_FILES := $(SRC_FILES:.cpp=.d)
# OBJ_FILES := $(SRC_FILES:.cpp=.o)
# TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)

# TEST_EXECUTABLES := $(TEST_FILES:$(TEST_DIR)/%.cpp=$(BIN_DIR)/%)

# $(BIN_DIR)/compilabusca: $(TEST_DIR)/Testebusca.cpp
#     $(CXX) $(CXXFLAGS) -I$(INC_DIR) $< -o $@

# $(BIN_DIR)/compilaestoque: $(TEST_DIR)/Testeestoque.cpp
#     $(CXX) $(CXXFLAGS) -I$(INC_DIR) $< -o $@

# $(BIN_DIR)/compilapagamento: $(TEST_DIR)/Testepagamento.cpp
#     $(CXX) $(CXXFLAGS) -I$(INC_DIR) $< -o $@

# $(BIN_DIR)/compilacliente: $(TEST_DIR)/Testecliente.cpp
#     $(CXX) $(CXXFLAGS) -I$(INC_DIR) $< -o $@

# $(BIN_DIR)/compilaproduto: $(TEST_DIR)/Testeproduto.cpp
#     $(CXX) $(CXXFLAGS) -I$(INC_DIR) $< -o $@

# -include $(addprefix $(BUILD_DIR)/,$(DEP_FILES))

# run: $(BIN_DIR)/$(PROJECT_NAME)
# 	@LD_LIBRARY_PATH=$(MAIL_LIB_PATH) $(BIN_DIR)/$(PROJECT_NAME)

# build: $(BIN_DIR)/$(PROJECT_NAME)

# # Configuração das regras
# all: $(BIN_DIR)/$(EXECUTABLE)

# # Compilação do programa principal
# $(BIN_DIR)/$(EXECUTABLE): $(OBJ_FILES)
#     $(CXX) $(CXXFLAGS) $^ -o $@

# # Compilação dos arquivos de origem (.cpp) para arquivos objeto (.o)
# $(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
#     $(CXX) $(CXXFLAGS) -I$(INC_DIR) -MMD -c $< -o $@

# # Execução dos testes
# test: $(TEST_EXECUTABLES)

# # Limpeza dos arquivos gerados
# clean:
#     rm -rf $(BUILD_DIR)/* $(BIN_DIR)/*
# cliente

# # Compilação de busca
# testebusca: $(BIN_DIR)/compilabusca: $(TEST_DIR)/Testebusca.cpp
#     $(CXX) $(CXXFLAGS) -I$(INC_DIR) $< -o $@
# # Compilação de cliente
# testecliente: 
#     $(BIN_DIR)/compilacliente: $(TEST_DIR)/Testecliente.cpp
#     $(CXX) $(CXXFLAGS) -I$(INC_DIR) $< -o $@
# # Compilação de estoque
# testestoque: 
#     $(BIN_DIR)/compilacliente: $(TEST_DIR)/Testeestoque.cpp
#     $(CXX) $(CXXFLAGS) -I$(INC_DIR) $< -o $@
# # Compilação de produto
# testeproduto: 
#     $(BIN_DIR)/compilaproduto: $(TEST_DIR)/Testeproduto.cpp
#     $(CXX) $(CXXFLAGS) -I$(INC_DIR) $< -o $@
# # Compilação de pagamento
# testepagamento: 
#     $(BIN_DIR)/compilapagamento: $(TEST_DIR)/Testepagamento.cpp
#     $(CXX) $(CXXFLAGS) -I$(INC_DIR) $< -o $@
# .PHONY: all test clean
