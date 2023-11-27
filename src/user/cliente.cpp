#include "../../include/user/cliente.hpp"

Cliente::Cliente()
{
    std::string coringa;
    std::cout << std::endl;
    std::cout << "Escreva seu nome ";
    std::cin >> coringa;
    atualiza_usuario(coringa);
    std::cout << "Escreva seu endereço ";
    std::cin >> endereco;
    std::cout << "Escreva seu telefone ";
    std::cin >> coringa;
    atualiza_telefone(coringa);
    std::cout << "Escreva sua forma de pagamento ";
    std::cin >> forma_pagamento;
    contador();
}

void
Cliente::atualiza_endereco(std::string novo_endereco)
{
    endereco = novo_endereco;
}

void
Cliente::atualiza_forma_pagameto(std::string nova_forma)
{
    forma_pagamento = nova_forma;
}

std::string
Cliente::GetEndereco()
{
    return endereco;
}

std::string
Cliente::GetPagamento()
{
    return forma_pagamento;
}

