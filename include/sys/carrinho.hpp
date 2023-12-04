/*
    carrinho.hpp
    Author: M. Clara Contarini
    mccontarinid@gmail.com

    Cria uma lista com as compras do cliente
*/

#ifndef CARRINHO_H
#define CARRINHO_H

#include <iostream>
#include <list>
#include <string>
#include "produto.hpp"

class Carrinho
{
private:
    std::list<std::pair<Produto, unsigned>> lista_ids_produtos;
    float preco_total;
    unsigned quantidade_produto;
    // std::string id_cliente;

public:
    static const  std::string PATH_CARRINHO;

    /// @brief Constructor
    Carrinho();
    ~Carrinho() = default;

    /// @brief adiciona um produto ao carrinho
    /// @param id_produto produto a ser adicionado
    /// @param quantidade quantidade do produto a ser adicionada
    void adiciona_produto(Produto produto, unsigned quantidade);

    /// @brief remove um produto do carrinho
    /// @param id_produto produto a ser removido
    /// @param quantidade quantidade do produto a ser removida
    void remove_produto(Produto produto, unsigned quantidade);

    /// @brief para pegar a lista
    /// @return a lista de produtos com suas quantidades
    std::list<std::pair<Produto, unsigned>> GetList() const;

    /// @brief para pegar o preço total
    /// @return o preço total
    float GetTotalPrice() const;

    /// @brief para pegar a quantidade de produtos
    /// @return quantidade de produtos
    unsigned GetProductQuantity() const;
};

#endif /* CARRINHO_H */