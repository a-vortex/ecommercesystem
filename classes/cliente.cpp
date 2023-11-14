#include "cliente.hpp"

int Cliente::contador_id = 0;
void Cliente::atualiza_usuario(std::string novo_nome)
{
    nome_usuario = novo_nome;
}

void Cliente::atualiza_endereco(std::string novo_endereco)
{
    endereco = novo_endereco;
}

void Cliente::atualiza_telefone(std::string novo_telefone)
{
    num_telefone = novo_telefone;
}

Cliente::Cliente()
{
    std::cout << std::endl;
    std::cout << "Escreva seu nome ";
    std::cin >> nome_usuario;
    std::cout << "Escreva seu endereço ";
    std::cin >> endereco;
    std::cout << "Escreva seu telefone ";
    std::cin >> num_telefone;
    contador();
}
int main()
{
    Cliente p;
    p.imprime();
    Cliente x;
    x.imprime();
}