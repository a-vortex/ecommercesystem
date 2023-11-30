#include "../../include/sys/estoque.hpp"
#include "produto.cpp"
#include <iostream>
#include <fstream>
#include <string>


const std::string Estoque::PATH_ESTOQUE = "../../../estoque.txt";

bool Estoque::adiciona_produto(const Produto &produto, int quantidade)
{
    std::ofstream arquivo(PATH_ESTOQUE, std::ios_base::app);
      if(arquivo.is_open())
        {
            arquivo << produto.GetName() << "-" << produto.GetId() << "-" << quantidade<< "-" << std::endl;
            arquivo.close();
            std::cout << "> Novo produto adicionado ao estoque! <" << "\n\n";
        }
         else
        {
            throw std::runtime_error("> Erro ao realizar cadastro! <");
        }
    bool inserted = _lista_ids.insert(std::make_pair(produto.GetId(), quantidade)).second;
    produtos.push_back(produto);
    return inserted;
}

void Estoque::atualiza_quantidade(const std::string &id_produto, int quantidade)
{
        std::fstream arquivo(PATH_ESTOQUE);
    std::string teste;
    std::stringstream buffer; // Buffer para armazenar o conteúdo do arquivo

    while (arquivo >> teste) {
        if (teste == id_produto) {
            buffer << "nova_palavra "; // Substitui a palavra
        } else {
            buffer << teste << " - ";
        }
    }

    arquivo.close(); 
    std::ofstream arquivo_saida(PATH_ESTOQUE); 
    arquivo_saida << buffer.str(); 
    arquivo_saida.close(); 

    std::cout << "Palavra alterada com sucesso!\n";

   
}

void Estoque::exibe_quantidade(const std::string &id_produto)
{
    bool flag = false;
    for (auto it = _lista_ids.begin(); it != _lista_ids.end(); ++it)
    {
        const std::string &key = it->first;
        if (key == id_produto)
        {
            std::cout << std::left << std::setw(20) << "ID do Produto: " << id_produto << std::endl;
            std::cout << std::left << std::setw(20) << "Quantidade: " << it->second << std::endl;
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        std::cout << "Produto nao encontrado: " << id_produto << std::endl;
    }
}

std::vector<Produto>
Estoque::lista_produtos()
{
    return produtos;
}

int Estoque::GetQuantidade(const std::string &id_produto)
{
    for (auto it = _lista_ids.begin(); it != _lista_ids.end(); ++it)
    {
        const std::string &key = it->first;

        if (key == id_produto)
        {
            return it->second;
            break;
        }
    }
    throw std::runtime_error("Produto nao encontrado");
}

int main(){
    Estoque test;
    test.atualiza_quantidade("aaa", 1);
    // Produto produto("Produto1", "Testando o produto 1", "2154", "teste", 20.2);
    // (test.adiciona_produto(produto, 12));
    // (test.atualiza_quantidade("2154", 14));
    // (test.exibe_quantidade("2154"));

}