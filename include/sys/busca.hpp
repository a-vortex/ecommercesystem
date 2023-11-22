#ifndef BUSCA_H
#define BUSCA_H

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include "produto.hpp"

class Busca
{
private:
    std::vector<std::string> id_produto;
    std::vector<std::string> nome;
    std::vector<float> preco_produto;

public:

    /// @brief Faz a busca do produto com o nome especificado
    ///        em uma determinada lista
    /// @param nome do produto que quer pesquisar
    /// @param _lista_de_produtos onde o produto esta inserido
    /// @return o produto especifiado
    Produto busca_produtos_nome(const std::string& nome, const std::vector<Produto> &_lista_de_produtos);

    /// @brief Faz a busca dos produtos com tipo determinado
    /// @param tipo do produto que quer pesquisar
    /// @param _lista_de_produtos onde o produto esta inserido
    /// @return uma lista de produtos com o tipo especificado
    std::vector<Produto> busca_produtos_tipo(const std::string tipo, const std::vector<Produto> &_lista_de_produtos);

    /// @brief Faz a busca dos produtos com preco determinado
    /// @param preco do produto que quer pesquisar
    /// @param _lista_de_produtos onde o produto esta inserido
    /// @return uma lista de produtos com o preco especificado
    std::vector<Produto> busca_produtos_preco(float preco, const std::vector<Produto> &_lista_de_produtos);
};

#endif /* BUSCA_H */