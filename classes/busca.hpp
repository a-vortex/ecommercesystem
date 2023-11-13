#pragma once;

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include "produto.hpp"

class Busca {
    private:
    std::string id_produto;
    std::string nome;
    std::string tipo;
    float preco_produto;

    public:

    @brief busca o produto no vetor Estoque
    std::vector<Produto> busca_produtos_tipo(tipo);
    std::vector<Produto> busca_produtos_nome(nome);
    std::vector<Produto> busca_produtos_preco(preco);
};