#include "busca.hpp"
#include "estoque.hpp"
#include <iostream>

std::vector<Produto> produtos = Estoque::produtos;

std::vector<Produto> Busca::busca_produtos_tipo(std::string tipo) {

    std::vector<Produto> resultado;

    for(int i = 0; i < produtos.length; i++) {
        if(produtos[i]::tipo == tipo) {
            resultado::push_back(produtos[i]);
        }
    }

    return resultado;
}

std::vector<Produto> Busca::busca_produtos_nome(std::string nome) {

    std::vector<Produto> resultado;

    for(int i = 0; i < produtos.length; i++) {
        if(produtos[i]::nome == nome) {
            resultado::push_back(produtos[i]);
        }
    }

    return resultado;
}

std::vector<Produto> Busca::busca_produtos_preco(float preco) {

    std::vector<Produto> resultado;

    for(int i = 0; i < produtos.length; i++) {
        if(produtos[i]::preco == preco) {
            resultado::push_back(produtos[i]);
        }
    }

    return resultado;
}