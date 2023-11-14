#include "busca.hpp"
#include "estoque.hpp"
#include "produto.hpp"
#include "produto.cpp"
#include "cliente.hpp"
#include "cliente.cpp"
#include <iostream>
#include <tuple>

Cliente cliente;
void Busca::busca_produtos_tipo(std::string tipo)
{
    bool produto_encontrado = false;

    for (const std::tuple<std::string, std::string, float> &buscador : nome_tipo_preco)
    {
        if (std::get<1>(buscador) == tipo)
        {
            std::cout << std::endl;
            std::cout << "Lista de produtos do tipo:" << std::get<1>(buscador) << std::endl;
            std::cout << "tipo:" << std::get<1>(buscador) << std::endl;
            std::cout << "preço:" << std::get<2>(buscador) << std::endl;
            produto_encontrado = true;
            cliente.historico.push_back(std::get<0>(buscador));
        }
        if (!produto_encontrado)
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
            std::cout << "Produto " << std::get<0>(buscador) << " encontrado" << std::endl;
            std::cout << "tipo:" << std::get<1>(buscador) << std::endl;
            std::cout << "preço:" << std::get<2>(buscador) << std::endl;
            produto_encontrado = true;
            cliente.historico.push_back(std::get<0>(buscador));
        }
        if (!produto_encontrado)
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

        if (std::get<2>(buscador) <= preco)
        {
            std::cout << std::endl;
            std::cout << "Produto com o preços iguais e menores que:" << std::get<2>(buscador) << std::endl
                      << "nome:" << std::get<0>(buscador) << std::endl;
            std::cout << "tipo:" << std::get<1>(buscador) << std::endl;
            produto_encontrado = true;
            cliente.historico.push_back(std::get<0>(buscador));
        }
        if (!produto_encontrado)
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
    busca.busca_produtos_tipo("teste");
    busca.busca_produtos_nome("Produto1");
    busca.busca_produtos_preco(20.2);
    cliente.historico_pesquisa();
}
