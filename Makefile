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
    $(CXX) $(CXXFLAGS) -I$(INC_DIR)  $< -o $@

$(BIN_DIR)/test_arquivo2: $(TEST_DIR)/Testecliente.cpp
    $(CXX) $(CXXFLAGS) -I$(INC_DIR)  $< -o $@

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
cliente

# Compilação de busca
busca: $(BIN_DIR)/compiladobusca : $(SRC_DIR)/busca.cpp
    $(CXX) $(CXXFLAGS) -I$(INC_DIR) $< -o $@
# Compilação de carrinho
carrinho: 
    $(BIN_DIR)/compiladocarrinho : $(SRC_DIR)/carrinho.cpp
    $(CXX) $(CXXFLAGS) -I$(INC_DIR) $< -o $@
# Compilação de cupom
cupom: 
    $(BIN_DIR)/compiladocupom : $(SRC_DIR)/cupom.cpp
    $(CXX) $(CXXFLAGS) -I$(INC_DIR) $< -o $@
# Compilação de cliente
cliente: 
    $(BIN_DIR)/compiladocliente : $(SRC_DIR)/cliente.cpp
    $(CXX) $(CXXFLAGS) -I$(INC_DIR) $< -o $@
# Compilação de estoque
estoque: 
    $(BIN_DIR)/compiladocliente : $(SRC_DIR)/estoque.cpp
    $(CXX) $(CXXFLAGS) -I$(INC_DIR) $< -o $@
# Compilação de produto
produto: 
    $(BIN_DIR)/compiladoproduto : $(SRC_DIR)/produto.cpp
    $(CXX) $(CXXFLAGS) -I$(INC_DIR) $< -o $@
# Compilação de pagamento
pagamento: 
    $(BIN_DIR)/compiladopagamento : $(SRC_DIR)/pagamento.cpp
    $(CXX) $(CXXFLAGS) -I$(INC_DIR) $< -o $@
.PHONY: all test clean
