#include "../../include/sys/busca.hpp"
#include <fstream>

const std::string Busca::PATH_BUSCA = "estoque.txt";

void Busca::exibe_produtos() {
    std::fstream arquivo(PATH_BUSCA);
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
void Busca::exibe_tipo(const std::string &tipo) {
    std::fstream arquivo(PATH_BUSCA);
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

   

void Busca::exibe_nome(const std::string &nome) {
    std::fstream arquivo(PATH_BUSCA);
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


void Busca::exibe_preco(int preco) {
    std::fstream arquivo(PATH_BUSCA);
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


