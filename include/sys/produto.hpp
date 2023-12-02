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
    float preco;

public:
    /// @brief Construtor sobrecarregado
    Produto(const std::string &nome,
            const std::string &descricao,
            const std::string &id_produto,
            const std::string &tipo,
            float preco);

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
    void atualiza_info( std::string nome_produto);

    /// @brief Associa um ID a um nome, dentro de um tipo map
    /// @return um tipo Map com um ID e nome
    std::map<long int, std::string> associaID();

    /// @brief Exibe as informacoes de um determinado produto de um conteiner de produtos
    /// @tparam Container
    /// @param id ID do produto
    /// @param produtos Conteiner de produtos
    template <typename Container>
    static void exibe_info(const std::string &id, const Container &produtos)
    {
        bool produtoEncontrado = false;

        for (auto it = produtos.begin(); it != produtos.end(); ++it)
        {
            if (id == it->GetId())
            {
                std::cout << "Produto encontrado:" << std::endl;
                std::cout << std::left << std::setw(20) << "Nome: " << it->GetName() << std::endl;
                std::cout << std::left << std::setw(20) << "Descrição: " << it->GetDescription() << std::endl;
                std::cout << std::left << std::setw(20) << "ID do Produto: " << it->GetId() << std::endl;
                std::cout << std::left << std::setw(20) << "Tipo: " << it->GetType() << std::endl;
                std::cout << std::left << std::setw(20) << "Preço: " << it->GetPrice() << std::endl;
                produtoEncontrado = true;
                break;
            }
        }
        if (!produtoEncontrado)
        {
            std::cout << "Produto não encontrado: " << id << std::endl;
        }
    }

    /// @brief Getters
    /// @return ID, nome, descricao, tipo e preco do produto
    std::string GetId() const;
    std::string GetName() const;
    std::string GetDescription() const;
    std::string GetType() const;
    float GetPrice() const;
     static const  std::string PATH_PRODUTO;
};

#endif /* PRODUTO_H */