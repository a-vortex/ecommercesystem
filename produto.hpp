/*
    produto.hpp
    Author: Yuri Wada
    yuriwada@ufmg.br

    Define um produto e exibe suas informacoes.
    Tambem eh possivel atualizar as informacoes.
*/

#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <map>

class Produto{
private:
    std::string nome;
    std::string descricao;
    std::string id_produto;
    std::string tipo;
    float preco;
    
public:

    /*
        Construtor da Classe Produto
        Associa um nome a um ID de produto
    */
    Produto(const std::string& nome,
            const std::string& descricao,
            const std::string& id_produto,
            const std::string& tipo,
            float preco);

    //exibe informacoes
    void exibe_info();

    //atualiza as informacoes
    void atualiza_info();
};

#endif /*PRODUTO_HPP*/