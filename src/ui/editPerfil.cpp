#include "../../include/ui/editperfil.hpp"
#include <iostream>
#include <string>

namespace ecommerce::ui
{

    Editperfil::Editperfil()
    {

        // _title = "Editar Informações";
        // _options.push_back("1- Nome");
        // _options.push_back("2- Endereço");
        // _options.push_back("3- Telefone");
        // _options.push_back("4- Forma de Pagamento");
    }
}

namespace ecommerce::ui
{

    Menu *Editperfil::nextWithCliente(unsigned option, Cliente cliente)
    {
        std::string global;
        switch (option)
        {
        case 1:
        {
            std::cout << "Digite o seu nome" << std::endl;
            std::cin >> global;
            cliente.atualiza_usuario(global);
            std::cout << "Atualizado com sucesso, novo nome: " << cliente.GetNome() << std::endl;
            break;
        }
        case 2:
        {
            std::cout << "Escreva seu endereço" << std::endl;
            std::cin >> global;
            cliente.atualiza_endereco(global);
            std::cout << "Atualizado com sucesso, novo endereço: " << cliente.GetEndereco() << std::endl;
            break;
        }
        case 3:
        {
            std::cout << "Escreva seu telefone" << std::endl;
            std::cin >> global;
            cliente.atualiza_telefone(global);
            std::cout << "Atualizado com sucesso, novo número de telefone: " << cliente.GetNumero() << std::endl;
            break;
        }
        case 4:
        {

            std::cout << "Escreva sua forma de pagamento" << std::endl;
            std::cin >> global;
            cliente.atualiza_forma_pagameto(global);
            std::cout << "Atualizado com sucesso, nova forma de pagamento: " << cliente.GetPagamento() << std::endl;
        }
        default:
            break;
        }

        return 0;
    }
}

namespace ecommerce::ui
{

    Menu *Editperfil::nextWithAdmin(unsigned option, Administrador adm)
    {
        std::string global;
        switch (option)
        {
        case 1:
        {
            std::cout << "Digite o seu nome" << std::endl;
            std::cin >> global;
            adm.atualiza_usuario(global);
            std::cout << "Atualizado com sucesso, novo nome: " << adm.GetNome() << std::endl;

            break;
        }

        case 2:
        {
            std::cout << "Escreva seu telefone" << std::endl;
            std::cin >> global;
            adm.atualiza_telefone(global);
            std::cout << "Atualizado com sucesso, novo número: " << adm.GetNumero() << std::endl;
            break;
        }

        default:
            break;
        }

        return 0;
    }
}

int main()
{
    Administrador cliente;
    ecommerce::ui::Editperfil teste;
    teste.nextWithAdmin(1, cliente);
    // teste.next(2);
    // teste.next(3);
    // teste.next(4);
}