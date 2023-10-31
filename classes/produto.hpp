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

    static bool exibe_info(const std::string& id, const std::vector<Produto>& produtos)
    {
        for (const Produto &produto : produtos)
        {
            if (id == produto.GetId())
            {
                std::cout << std::left << std::setw(20) << "Nome: " << produto.GetName() << std::endl;
                std::cout << std::left << std::setw(20) << "Descricao: " << produto.GetDescription() << std::endl;
                std::cout << std::left << std::setw(20) << "ID do Produto: " << produto.GetId() << std::endl;
                std::cout << std::left << std::setw(20) << "Tipo: " << produto.GetType() << std::endl;
                std::cout << std::left << std::setw(20) << "Preco: " << produto.GetPrice() << std::endl;
                return true;
            }
        }
        return false;
    }
    std::string GetId() const;
    std::string GetName() const;
    std::string GetDescription() const;
    std::string GetType() const;
    float GetPrice() const;
};