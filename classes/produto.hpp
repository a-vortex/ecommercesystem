/*
    produto.hpp
    Author: Yuri Wada
    yuriwada@ufmg.br

    Define um produto e exibe suas informacoes.
    Tambem eh possivel atualizar as informacoes.
*/

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

class Produto{
private:
    std::string nome;
    std::string descricao;
    std::string id_produto;
    std::string tipo;
    float preco;
    
public:

    //Constructor
    Produto(const std::string& nome,
            const std::string& descricao,
            const std::string& id_produto,
            const std::string& tipo,
            float preco);

    void atualiza_info();
    std::map<long int, std::string> associaID();

    template <typename Container>
    static void exibe_info(const std::string &id, const Container &produtos)
    {
        bool produtoEncontrado = false;

        for (auto it = produtos.begin(); it != produtos.end(); ++it)
        {
            if (id == it->GetId())
            { // Use -> para acessar membros de objetos apontados por it
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

    std::string GetId() const;
    std::string GetName() const;
    std::string GetDescription() const;
    std::string GetType() const;
    float GetPrice() const;
};