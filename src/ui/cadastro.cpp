#include "../../include/ui/cadastro.hpp"
#include <iostream>
#include "../../src/sys/cliente.cpp" // excluir após teste

namespace ecommerce::ui
{
    Cadastro::Cadastro()
    {
        _title = "Tela de cadastro";
        _options.push_back("1- Cadastro de Cliente");
        _options.push_back("2- Cadastro de Administrador");
    }

}

namespace ecommerce::ui
{

    Menu *Cadastro::next(unsigned option)
    {
        switch (option)
        {
        case 1:
        {
            std::string global;
            std::cout << "Ficamos feliz em ver você aqui, vamos realizar o seu cadastro" << std::endl;
            Cliente cliente;
            std::cout << "Escreva seu nome" << std::endl;
            std::cin >> global;
            cliente.atualiza_usuario(global);
            std::cout << "Escreva seu endereço" << std::endl;
            std::cin >> global;
            cliente.atualiza_endereco(global);
            std::cout << "Escreva seu telefone" << std::endl;
            std::cin >> global;
            cliente.atualiza_telefone(global);
            std::cout << "Escreva sua forma de pagamento" << std::endl;
            std::cin >> global;
            cliente.atualiza_forma_pagameto(global);

            break;
        }

        default:
            break;
        }
        return 0;
    }
}