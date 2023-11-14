#include "busca.hpp"
#include "estoque.hpp"
#include "produto.hpp"
#include "produto.cpp"
#include <iostream>
#include <tuple>

void Busca::busca_produtos_tipo(std::string tipo)
{
    bool produto_encontrado = false;

    for (const std::tuple<std::string, std::string, float> &buscador : nome_tipo_preco)
    {
        if (std::get<1>(buscador) == tipo)
        {
            std::cout << std::endl;
            std::cout << "Produto encontrado, nome:" << std::get<0>(buscador) << std::endl;
            produto_encontrado = true;
        }
        if(!produto_encontrado)
        {
            std::cout << "Produto não encontrado." << std::endl;
        }
    }
}

void Busca::busca_produtos_nome(std::string nome)
{
    bool produto_encontrado = false;

    for (const std::tuple<std::string, std::string, float> &buscador : nome_tipo_preco)
    {

        if (std::get<0>(buscador) == nome)
        {
            std::cout << std::endl;
            std::cout << "Produto encontrado, tipo:" << std::get<1>(buscador) << std::endl;
            std::cout << "Preço:" << std::get<2>(buscador) << std::endl;
            produto_encontrado = true;
        }
        if(!produto_encontrado)
        {
            std::cout << "Produto não encontrado." << std::endl;
        }
    }
}

void Busca::busca_produtos_preco(float preco)
{
    bool produto_encontrado = false;

    for (const std::tuple<std::string, std::string, float> &buscador : nome_tipo_preco)
    {

        if (std::get<2>(buscador) == preco)
        {
            std::cout << std::endl;
            std::cout << "Produto encontrado, nome:" << std::get<0>(buscador) << std::endl;
            produto_encontrado = true;
        }
        if(!produto_encontrado)
        {
            std::cout << "Produto não encontrado." << std::endl;
        }
    }
}

int main()
{
    Busca busca;
    Produto p("Produto1", "Testando o produto 1", "2154", "teste", 20.2);
    busca.nome_tipo_preco.push_back(std::make_tuple(p.GetName(), p.GetType(), p.GetPrice()));
    busca.busca_produtos_tipo("tipofalso");
}
