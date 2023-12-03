/*
    busca.hpp
    Author: Kauan Valente da Silva
    kauanvalentesv@gmail.com

    Cria os mecanismos de busca do sistema.
*/

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
   
    /// @brief Exibe todos os produtos existentes
    /// @return imprime na tela uma lista
    void exibe_produtos();

    /// @brief Exibe todos os produtos existentes de um tipo
    /// @param  tipo do produto a ser exibido
    /// @return imprime na tela uma lista
    void exibe_tipo(const std::string &tipo);

    /// @brief Exibe todos os produto de um preco
    /// @param  preco do produto a ser exibido
    /// @return imprime na tela uma lista
    void exibe_preco(const int preco);

    /// @brief Exibe todos os produtos existentes de um tipo
    /// @param  nome do produto a ser exibido
    /// @return imprime na tela uma lista
    void exibe_nome(const std::string &nome);

    static const  std::string PATH_BUSCA;

};

#endif /* BUSCA_H */