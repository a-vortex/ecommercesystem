#include "../../include/sys/produto.hpp"

#include <iostream>
#include <string>
#include <type_traits>

Produto::Produto(const std::string &nome,
                 const std::string &descricao,
                 const std::string &id_produto,
                 const std::string &tipo,
                 const std::string preco)
{
    this->nome = nome;
    this->descricao = descricao;
    this->id_produto = id_produto;
    this->tipo = tipo;
    this->preco = preco;
    std::cout << "Produto criado com sucesso" << std::endl;
}

void Produto::atualiza_info(std::vector<Produto> produtos, std::string nome_produto)
{
    std::cout << "Qual tipo de informacao quer alterar? Escolha uma opcao (1 a 4)" << std::endl;
    std::cout << "Para finalizar a operacao, digite 0" << std::endl;
    std::cout << "1. Nome" << std::endl;
    std::cout << "2. Descricao" << std::endl;
    std::cout << "3. Tipo" << std::endl;
    std::cout << "4. Preco" << std::endl;
    std::cout << "0. sair" << std::endl;

    unsigned escolha = 5;
    while (std::cin >> escolha && escolha != 0)
    {
        switch (escolha)
        {
        case 1:
        {
            std::cout << "Insira o novo nome: " << std::endl;
            for (auto it = produtos.begin(); it != produtos.end(); ++it)
            {
                if (nome_produto == it->GetName())
                {
                    std::getline(std::cin >> std::ws, nome);
                }
            }
            break;
        }

        case 2:
        {
            std::cout << "Insira a nova descricao: " << std::endl;

            for (auto it = produtos.begin(); it != produtos.end(); ++it)
            {
                if (nome_produto == it->GetName())
                {
                    std::getline(std::cin >> std::ws, descricao);
                }
            }
            break;
        }

        case 3:
        {
            std::cout << "Insira o novo tipo: " << std::endl;
            for (auto it = produtos.begin(); it != produtos.end(); ++it)
            {
                if (nome_produto == it->GetName())
                {
                    std::getline(std::cin >> std::ws, tipo);
                }
            }
            break;
        }

        case 4:
        {
            std::cout << "Insira o novo preco (utilize ponto ao invés de vírgula): " << std::endl;
            for (auto it = produtos.begin(); it != produtos.end(); ++it)
            {
                if (nome_produto == it->GetName())
                {
                    while(!eFloat(preco))
                    {
                        std::cout << "Preço inválido, insira novamente (utilize ponto ao invès de vírgula): " << std::endl;
                        std::getline(std::cin >> std::ws, preco);
                    }
                }
            break;
        }

            {

                break;
            default:
                break;
            }
            break;
        }
        // std::cout << "Escolha nova opcao (1 a 4)" << std::endl;
        // std::cout << "Para finalizar a operacao, digite 0" << std::endl;
        }
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

std::string
Produto::GetId() const
{
    return id_produto;
}

std::string
Produto::GetName() const
{
    return nome;
}

std::string
Produto::GetDescription() const
{
    return descricao;
}

std::string
Produto::GetType() const
{
    return tipo;
}

std::string Produto::GetPrice() const
{
    return preco;
}

auto eFloat = [] (const auto& str)
{
    return std::is_floating_point<std::string(str)>value;
};
