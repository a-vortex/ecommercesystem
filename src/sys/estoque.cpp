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
        {   arquivo<<std::endl;
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

void Estoque::atualiza_quantidade(const std::string &id_produto, int quantidade)
{
    std::fstream arquivo(PATH_ESTOQUE);
  
    std::string palavra;
    std::stringstream buffer; // Buffer para armazenar as palavras temporariamente
    int conta = 0;
    std::string numeroString = std::to_string(quantidade);

    while (arquivo >> palavra) {
        if (arquivo.is_open()) {

            if(palavra == id_produto){
            arquivo <<" "<< numeroString << "  ";

            }        
        conta++;
        }

    }

    if (!buffer.str().empty()) {
        std::cout << buffer.str(); 
    }

    arquivo.close(); 
}


   

 


void Estoque::exibe_quantidade(const std::string &id_produto)
{
    std::fstream arquivo(PATH_ESTOQUE);
    std::string palavra;
    std::stringstream buffer; 
bool achou = false;
bool imprimirProxima = false;
std::string proximaPalavra;
    if (arquivo.is_open()) {
        
 if (arquivo.is_open()) {
    while (arquivo >> palavra) {
        if (achou) {
            proximaPalavra = palavra; 
            imprimirProxima = true;
            achou = false; 
        }

        if (palavra == id_produto) {
            achou = true; 
        }

        if (imprimirProxima) {
            std::cout << proximaPalavra << std::endl;
            break; 
        }
    }
    arquivo.close(); 
} else {
    std::cerr << "Erro ao abrir o arquivo." << std::endl;
}

    }

}


void Estoque::exibe_produtos() {
    std::fstream arquivo(PATH_ESTOQUE);
    std::string linha;

    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {
            std::cout << linha << std::endl;
        }
        arquivo.close();
    } else {
        std::cout << "Não foi possível abrir o arquivo." << std::endl;
    }
}
void Estoque::exibe_tipo(const std::string &tipo) {
    std::fstream arquivo(PATH_ESTOQUE);
    std::string linha;

    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {
            if (linha.find(tipo) != std::string::npos) {
                std::cout << linha << std::endl;
            }
        }
        arquivo.close();
    } else {
        std::cout << "Não foi possível abrir o arquivo." << std::endl;
    }
}

   

void Estoque::exibe_nome(const std::string &nome) {
    std::fstream arquivo(PATH_ESTOQUE);
    std::string linha;

    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {
            if (linha.find(nome) != std::string::npos) {
                std::cout << linha << std::endl;
            }
        }
        arquivo.close();
    } else {
        std::cout << "Não foi possível abrir o arquivo." << std::endl;
    }
}


void Estoque::exibe_preco(int preco) {
    std::fstream arquivo(PATH_ESTOQUE);
    std::string linha;
    std::string numeroString = std::to_string(preco);

    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {
            if (linha.find(numeroString) != std::string::npos) {
                std::cout << linha << std::endl;
            }
        }
        arquivo.close();
    } else {
        std::cout << "Não foi possível abrir o arquivo." << std::endl;
    }
}

std::vector<Produto>
Estoque::lista_produtos()
{
    return produtos;
}


int main(){
    Estoque test;
    // test.atualiza_quantidade("5964", 232);
    // Produto produto("Produto3", "Testando o produto 1", "5964", "teste", 20.2);
    //  test.exibe_quantidade("5964");
    // (test.adiciona_produto(produto, 145));
    test.exibe_nome("aaa");


}