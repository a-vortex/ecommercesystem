#include "../../include/sys/busca.hpp"
#include "../../include/exc/excecao.hpp"

Produto
Busca::busca_produtos_nome(const std::string &nome, const std::vector<Produto> &_lista_de_produtos)
{
    for (const Produto &buscador : _lista_de_produtos)
    {
        if (buscador.GetName() == nome)
        {
            std::cout << buscador.GetName() << std::endl;
            return buscador;
        }
    }
    throw NotFound();
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
            std::cout << buscador.GetName() << std::endl;
            lista_tipos.push_back(buscador);
            produto_encontrado = true;
        }
    }
    if (!produto_encontrado)
    {
        throw NotFound();
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

        if (buscador.GetPrice() == preco)
        {
            std::cout << buscador.GetName() << std::endl;
            lista_preco.push_back(buscador);
            produto_encontrado = true;
        }
    }
    if (!produto_encontrado)
    {
        throw NotFound();
    }

    return lista_preco;
}

std::vector<Produto>
Busca::busca_produtos_todos(const std::vector<Produto> &lista_de_produtos)
{
    std::vector<Produto> lista_completa;
    // bool produto_encontrado = false;

    for (const Produto &buscador : lista_de_produtos)
    {

        std::cout << buscador.GetName() << "-" << buscador.GetId() << std::endl;
    }
    // if (!produto_encontrado)
    // {
    //     std::cout << "Nenhum Produto  encontrado!!" << std::endl;
    // }
    return lista_completa;
}
