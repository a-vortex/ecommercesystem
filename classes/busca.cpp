#include "busca.hpp"

std::vector<Produto>
Busca::busca_produtos_nome(const std::string nome, const std::vector<Produto> &_lista_de_produtos)
{
    bool produto_encontrado = false;
    std::vector<Produto> lista_nome;
    for (const Produto &buscador : _lista_de_produtos)
    {
        if (buscador.GetName() == nome)
        {
            lista_nome.push_back(buscador);
            produto_encontrado = true;
        }
    }
    if (!produto_encontrado)
    {
        std::cout << "Produto nao encontrado!!" << std::endl;
    }
    return lista_nome;
}

std::vector<Produto>
Busca::busca_produtos_tipo(const std::string tipo, const std::vector<Produto> &_lista_de_produtos)
{
    bool produto_encontrado = false;
    std::vector<Produto> lista_tipos;
    for (const Produto &buscador : _lista_de_produtos)
    {
        if (buscador.GetType() == tipo)
        {
            lista_tipos.push_back(buscador);
            produto_encontrado = true;
        }
    }
    if (!produto_encontrado)
    {
        std::cout << "Produto nao encontrado!!" << std::endl;
    }
    return lista_tipos;
}

std::vector<Produto>
Busca::busca_produtos_preco(float preco, const std::vector<Produto> &lista_de_produtos)
{
    std::vector<Produto> lista_preco;
    bool produto_encontrado = false;

    for (const Produto &buscador : lista_de_produtos)
    {

        if (buscador.GetPrice() <= preco)
        {
            lista_preco.push_back(buscador);
            produto_encontrado = true;
        }
    }
    if (!produto_encontrado)
    {
        std::cout << "Produto nao encontrado!!" << std::endl;
    }

    return lista_preco;
}
