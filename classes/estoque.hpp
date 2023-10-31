/*
    Author: Yuri Wada
    yuriwada@ufmg.br

    Controla informacoes sobre a quantidade
    de produtos no estoque do sistema.
*/

#pragma once

#include <iostream>
#include <string>
#include <set>
#include <iomanip>

class Estoque{
private:
    std::set<std::pair<std::string, int>> _lista_ids;

public:
    /// @brief Adiciona um produto ao estoque
    /// @param id_produto ID do produto a ser adicionado
    /// @param quantidade Inteiro que determina a quantidade do produto no estoque
    /// @return true se o produto foi adicionado com sucesso, false se nao foi
    bool adiciona_produto(const std::string& id_produto, int quantidade);

    /// @brief Atualiza a quantidade de um determinado produto no estoque
    /// @param id_produto ID do produto a ser editado
    /// @param quantidade Quantidade a ser atualizada
    void atualiza_quantidade(const std::string& id_produto, int quantidade);

    /// @brief Exibe quantos produtos associados a um ID tem disponiveis
    /// @param id_produto ID do produto a ser pesquisado
    void exibe_quantidade(const std::string& id_produto);
};