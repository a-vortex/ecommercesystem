/*
    Author: Yuri Wada
    yuriwada@ufmg.br

    Controla informacoes sobre a quantidade
    de produtos no estoque do sistema.
*/

#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <iostream>
#include <string>
#include <set>
#include <iomanip>
#include <fstream>
#include "produto.hpp"

class Estoque
{
private:
    std::set<std::pair<std::string, int>> _lista_ids;
    std::vector<Produto> produtos;

public:
    static const std::string PATH_ESTOQUE;
    
    /// @brief Constroi lista de produtos com base no que já existe np arquivo;
    // Estoque();
    /// @brief Adiciona um produto ao estoque
    /// @param produto Produto a ser adicionado
    /// @param quantidade Quantidade inserida no estoque
    /// @return true se foi adicionado, false se nao
    bool adiciona_produto(const Produto &produto, int quantidade);

    /// @brief Atualiza a quantidade de um determinado produto no estoque
    /// @param id_produto ID do produto a ser editado
    /// @param quantidade Quantidade a ser atualizada
    void atualiza_quantidade(const std::string &id_produto, int quantidade);

    /// @brief Exibe quantos produtos associados a um ID tem disponiveis
    /// @param id_produto ID do produto a ser pesquisado
    void exibe_quantidade(const std::string &id_produto);

    /// @brief Exibe quantos produtos associados a um ID tem disponiveis
    /// @param id_produto ID do produto a ser pesquisado
    /// @return A quantidade de produtos
    std::string return_quantidade(const std::string &id_produto);



    /// @brief Lista de produtos do estoque
    /// @return a lista de produtos
    std::vector<Produto> lista_produtos();
};

#endif /* ESTOQUE_H */