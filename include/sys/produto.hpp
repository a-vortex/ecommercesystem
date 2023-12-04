/*
    produto.hpp
    Author: Yuri Wada
    yuriwada@ufmg.br

    Define um produto e exibe suas informacoes.
    Tambem eh possivel atualizar as informacoes.
*/

#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

class Produto
{
private:
    std::string nome;
    std::string descricao;
    std::string id_produto;
    std::string tipo;
    std::string preco;

public:
    static const std::string PATH_PRODUTO;

    /// @brief Construtor sobrecarregado
    Produto(const std::string &nome,
            const std::string &descricao,
            const std::string &tipo,
            const std::string preco);

    /// @brief Construtor de copia
    /// @param other produto a ser copiado
    Produto(const Produto &other)
    {
        this->nome = other.nome;
        this->descricao = other.descricao;
        this->id_produto = other.id_produto;
        this->tipo = other.tipo;
        this->preco = other.preco;
    }

    /// @brief Atualiza as informacoes do produto
    static void atualiza_info(std::string nome_produto);

    /// @brief Associa um ID a um nome, dentro de um tipo map
    /// @return um tipo Map com um ID e nome
    std::map<long int, std::string> associaID();

    /// @brief Exibe as informacoes de um determinado produto de um conteiner de produtos
    /// @tparam Container
    /// @param id ID do produto
    /// @param produtos Conteiner de produtos
    template <typename Container>
    static void exibe_info(const std::string &id, const Container &produtos);

    /// @brief Getters
    /// @return ID, nome, descricao, tipo e preco do produto
    std::string GetId() const;
    std::string GetName() const;
    std::string GetDescription() const;
    std::string GetType() const;
    std::string GetPrice() const;
};

#endif /* PRODUTO_H */