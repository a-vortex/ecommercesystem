#include "../../include/sys/estoque.hpp"
// #include "produto.cpp"
#include <iostream>
#include <fstream>
#include <string>

const std::string Estoque::PATH_ESTOQUE = "estoque.txt";

bool
Estoque::adiciona_produto(const Produto &produto, int quantidade)
{
    std::ofstream arquivo(PATH_ESTOQUE, std::ios_base::app);

    if(arquivo.is_open())
    {   
        arquivo<<std::endl;
        arquivo << produto.GetName() << " " <<produto.GetId()   << " " << quantidade<< "   "<< produto.GetPrice()<< "    "<<produto.GetType()<< " "<< std::endl;
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

void
Estoque::atualiza_quantidade(const std::string &id_produto, int quantidade)
{
    std::fstream arquivo(PATH_ESTOQUE);
  
    std::string palavra;
    std::stringstream buffer; // Buffer para armazenar as palavras temporariamente
    int conta = 0;
    std::string numeroString = std::to_string(quantidade);

    while (arquivo >> palavra)
    {
        if (arquivo.is_open())
        {
            if(palavra == id_produto)
            {
                arquivo <<" "<< numeroString << "  ";
            }        
            conta++;
        }
    }

    if (!buffer.str().empty())
    {
        std::cout << buffer.str(); 
    }
    arquivo.close(); 
}

void
Estoque::exibe_quantidade(const std::string &id_produto)
{
    std::fstream arquivo(PATH_ESTOQUE);
    std::string palavra;
    std::stringstream buffer; 
    bool achou = false;
    bool imprimirProxima = false;
    std::string proximaPalavra;

    if (arquivo.is_open())
    {
        while (arquivo >> palavra)
        {
            if (achou)
            {
                proximaPalavra = palavra; 
                imprimirProxima = true;
                achou = false; 
            }

            if (palavra == id_produto)
            {
                achou = true; 
            }

            if (imprimirProxima)
            {
                std::cout << proximaPalavra << std::endl;
                break; 
            }
        }
        arquivo.close(); 
    }
    else
    {
    std::cerr << "Erro ao abrir o arquivo." << std::endl;
    }
}

std::string
Estoque::return_quantidade(const std::string &id_produto)
{
    std::fstream arquivo(PATH_ESTOQUE);
    std::string palavra;
    std::stringstream buffer; 
    bool achou = false;
    bool imprimirProxima = false;
    std::string proximaPalavra;
        
    if (arquivo.is_open())
    {
        while (arquivo >> palavra)
        {
            if (achou)
            {
                proximaPalavra = palavra; 
                imprimirProxima = true;
                achou = false; 
            }

            if (palavra == id_produto)
            {
                achou = true; 
            }

            if (imprimirProxima)
            {
                return proximaPalavra;
            }
        }
        arquivo.close(); 
    }
    return "> Erro ao abrir arquivo";
}

std::vector<Produto>
Estoque::lista_produtos()
{
    return produtos;
}