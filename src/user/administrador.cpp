#include "../../include/user/administrador.hpp"

Admnistrador::Admnistrador()
{
    isAdmin();
    std::string coringa;
    std::cout << std::endl;
    std::cout << "Escreva seu nome ";
    std::cin >> coringa;
    atualiza_usuario(coringa);
    std::cout << "Escreva seu telefone ";
    std::cin >> coringa;
    atualiza_telefone(coringa);
    contador();
}

void
Admnistrador::isAdmin()
{
    std::cout << "Escreva o código de acesso:" << std::endl;
    std::cin >> codigo_escrito;
    if (codigo_escrito == codigo_acesso)
    {
        confirma_acesso();
    }
    else
    {
        std::cout << "Código incorreto, acesso como administrador negado" << std::endl;
    }
}

std::string
Admnistrador::Get_codigo_escrito()
{
    return codigo_escrito;
}
