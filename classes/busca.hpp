#pragma once

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <tuple>
#include "produto.hpp"

class Busca
{
private:
    std::vector<std::string> id_produto;
    std::vector<std::string> nome;
    std::vector<float> preco_produto;

public:
    std::vector<std::tuple<std::string, std::string, float>> nome_tipo_preco;

    void busca_produtos_nome(std::string nome);
    void busca_produtos_tipo(std::string tipo);
    void busca_produtos_preco(float preco);
};