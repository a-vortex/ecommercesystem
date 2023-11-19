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

int main()
{
    Estoque estoque;
    Busca busca;
    Produto p("Produto1", "Testando o produto 1", "2154", "teste", 20.2);
    estoque.adiciona_produto(p, 2);

    std::vector<Produto> produtos_nome = busca.busca_produtos_nome("Produto1", estoque.lista_produtos());
    std::vector<Produto> produtos_tipo = busca.busca_produtos_tipo("teste", estoque.lista_produtos());
    std::vector<Produto> produtos_preco = busca.busca_produtos_preco(20.2, estoque.lista_produtos());

    if (!produtos_nome.empty())
    {
        for (const Produto &imprime : produtos_nome)
        {

            std::cout << imprime.GetName() << std::endl;
            std::cout << imprime.GetDescription() << std::endl;
            std::cout << imprime.GetId() << std::endl;
            std::cout << imprime.GetType() << std::endl;
            std::cout << imprime.GetPrice() << std::endl;
        }
        return 0;
    }

    if (!produtos_tipo.empty())
    {
        for (const Produto &imprime : produtos_tipo)
        {

            std::cout << imprime.GetName() << std::endl;
            std::cout << imprime.GetDescription() << std::endl;
            std::cout << imprime.GetId() << std::endl;
            std::cout << imprime.GetType() << std::endl;
            std::cout << imprime.GetPrice() << std::endl;
        }
        return 0;
    }
    if (!produtos_preco.empty())
    {
        for (const Produto &imprime : produtos_preco)
        {

            std::cout << imprime.GetName() << std::endl;
            std::cout << imprime.GetDescription() << std::endl;
            std::cout << imprime.GetId() << std::endl;
            std::cout << imprime.GetType() << std::endl;
            std::cout << imprime.GetPrice() << std::endl;
        }
        return 0;
    }

    return 0;
}
