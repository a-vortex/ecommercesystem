#include "../../include/sys/produto.hpp"

Produto::Produto(const std::string &nome,
                 const std::string &descricao,
                 const std::string &id_produto,
                 const std::string &tipo,
                 float preco)
{
    this->nome = nome;
    this->descricao = descricao;
    this->id_produto = id_produto;
    this->tipo = tipo;
    this->preco = preco;
}

void Produto::atualiza_info()
{
    std::cout << "Qual tipo de informacao quer alterar? Escolha uma opcao (1 a 4)" << std::endl;
    std::cout << "Para finalizar a operacao, digite 0" << std::endl;
    std::cout << "1. Nome" << std::endl;
    std::cout << "2. Descricao" << std::endl;
    std::cout << "3. Tipo" << std::endl;
    std::cout << "4. Preco" << std::endl;
    unsigned escolha = 5;
    while (std::cin >> escolha && escolha != 0)
    {
        switch (escolha)
        {
        case 1:
            std::cout << "Insira o novo nome: " << std::endl;
            std::cin >> nome;
            break;
        case 2:
            std::cout << "Insira a nova descricao: " << std::endl;
            std::cin >> descricao;
            break;
        case 3:
            std::cout << "Insira o novo tipo: " << std::endl;
            std::cin >> tipo;
            break;
        case 4:
            std::cout << "Insira o novo preco: " << std::endl;
            std::cin >> preco;
            break;
        }
        std::cout << "Escolha nova opcao (1 a 4)" << std::endl;
        std::cout << "Para finalizar a operacao, digite 0" << std::endl;
    }
}

std::map<long int, std::string>
Produto::associaID()
{
    std::map<long int, std::string> produto;
    long int id = std::stol(id_produto);
    produto.insert(std::make_pair(id, nome));
    return produto;
}

std::string Produto::GetId() const
{
    return id_produto;
}

std::string Produto::GetName() const
{
    return nome;
}

std::string Produto::GetDescription() const
{
    return descricao;
}

std::string Produto::GetType() const
{
    return tipo;
}

float Produto::GetPrice() const
{
    return preco;
}