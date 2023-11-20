#include "cliente.hpp"

int Cliente::contador_id = 0;
Cliente::Cliente()
{
    std::cout << std::endl;
    std::cout << "Escreva seu nome ";
    std::cin >> nome_usuario;
    std::cout << "Escreva seu endereço ";
    std::cin >> endereco;
    std::cout << "Escreva seu telefone ";
    std::cin >> num_telefone;
    std::cout << "Escreva sua forma de pagamento ";
    std::cin >> forma_pagamento;
    contador();
}
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
void Cliente::atualiza_forma_pagameto(std::string nova_forma)
{
    forma_pagamento = nova_forma;
}

std::string Cliente::GetNome()
{
    return nome_usuario;
}
std::string Cliente::GetEndereco()
{
    return endereco;
}
std::string Cliente::GetNumero()
{
    return num_telefone;
}
std::string Cliente::GetID()
{
    return id_cliente;
}

std::string Cliente::GetPagamento()
{
    return forma_pagamento;
}