#include "../../include/sys/produto.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

const std::string Produto::PATH_PRODUTO = "estoque.txt";

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

void Produto::atualiza_info( std::string nome_produto )
{
    std::cout << "Qual tipo de informacao quer alterar? Escolha uma opcao (1 a 4)" << std::endl;
    std::cout << "Para finalizar a operacao, digite 0" << std::endl;
    std::cout << "1. Nome" << std::endl;
    std::cout << "2. Preco" << std::endl;
    std::cout << "3. Tipo" << std::endl;
    std::cout << "0. sair" << std::endl;

    unsigned escolha = 5;
    while (std::cin >> escolha && escolha != 0)
    {   
        std::fstream arquivo(PATH_PRODUTO);
        std::string global;
        switch (escolha)
        {
        case 1:
        {
            std::cout << "Insira o novo nome: " << std::endl;
            std::string linha;
            std::getline(std::cin >> std::ws, global);

            if (arquivo.is_open()) {
                while (getline(arquivo, linha)) {
                    if (linha.find(nome_produto) != std::string::npos) {
                       arquivo <<global << "  ";
                    }
                }
                arquivo.close();
            } else {
                std::cout << "Não foi possível editar o nome." << std::endl;
            }
        }

        case 2:
        {
                std::cout << "Insira o novo preco: " << std::endl;
                std::string novoPreco;
                std::getline(std::cin >> std::ws, novoPreco);

                if (arquivo.is_open()) {
                    std::string linha;
                    while (getline(arquivo, linha)) {
                        std::istringstream iss(linha);
                        std::ostringstream novaLinha;
                        std::string palavra;
                        size_t contador = 0;

                        while (iss >> palavra) {
                            ++contador;
                            if (contador == 4) {
                                novaLinha << std::setw(palavra.length()) << novoPreco;
                            } else {
                                novaLinha << std::setw(palavra.length()) << palavra;
                            }
                            novaLinha << " ";
                        }

arquivo.seekp(static_cast<std::streamoff>(arquivo.tellg()) - static_cast<std::streamoff>(linha.length()) - 1);
                        arquivo << std::left << std::setw(linha.length()) << novaLinha.str() << std::endl;
                    }

                    arquivo.close();
                    std::cout << "Edicao concluida com sucesso!" << std::endl;
                } else {
                    std::cout << "Nao foi possivel abrir o arquivo." << std::endl;
                }
            break;
        }

        case 3:
        {
                std::cout << "Insira o novo tipo: " << std::endl;
                std::string novo;
                std::getline(std::cin >> std::ws, novo);

                if (arquivo.is_open()) {
                    std::string linha;
                    while (getline(arquivo, linha)) {
                        std::istringstream iss(linha);
                        std::ostringstream novaLinha;
                        std::string palavra;
                        size_t contador = 0;

                        while (iss >> palavra) {
                            ++contador;
                            if (contador == 5) {
                                novaLinha << std::setw(palavra.length()) << novo;
                            } else {
                                novaLinha << std::setw(palavra.length()) << palavra;
                            }
                            novaLinha << " ";
                        }

arquivo.seekp(static_cast<std::streamoff>(arquivo.tellg()) - static_cast<std::streamoff>(linha.length()) - 1);
                        arquivo << std::left << std::setw(linha.length()) << novaLinha.str() << std::endl;
                    }

                    arquivo.close();
                    std::cout << "Edicao concluida com sucesso!" << std::endl;
                } else {
                    std::cout << "Nao foi possivel abrir o arquivo." << std::endl;
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