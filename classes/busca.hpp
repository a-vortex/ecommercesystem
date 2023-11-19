#ifndef BUSCA_H
#define BUSCA_H

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include "classes.hpp"

class Busca
{
private:
    std::vector<std::string> id_produto;
    std::vector<std::string> nome;
    std::vector<float> preco_produto;

public:
    std::vector<std::tuple<std::string, std::string, float>> nome_tipo_preco;

    Produto busca_produtos_nome(const std::string nome, const std::vector<Produto> &_lista_de_produtos);
    std::vector<Produto> busca_produtos_tipo(const std::string tipo, const std::vector<Produto> &_lista_de_produtos);
    std::vector<Produto> busca_produtos_preco(float preco, const std::vector<Produto> &_lista_de_produtos);
};

#endif /* BUSCA_H */