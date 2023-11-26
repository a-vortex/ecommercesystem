#include "ui/loginscreen.hpp"
#include "ui/editPerfil.hpp"

#include "include/sys/cliente.hpp" 


#include <iostream>
#include <string>

namespace ecommerce::ui{

    Editperfil::EditPerfil(){

        _title = "Editar Informações";
        _options.push_back("1- Nome");
        _options.push_back("2- Endereço");
        _options.push_back("3- Telefone");
        _options.push_back("4- Forma de Pagamento");

    }
}

namespace ecommerce::ui
{

    Menu *EditPerfil::next(unsigned option)
    {
        switch (option)
        {
        case 1:
        {
            std::string global;
            std::cout << "Digite o seu nome" << std::endl;
            Cliente cliente;
            std::cin >> global;
            cliente.atualiza_usuario(global);

            break;
        }
        case 2:{
            std::cout << "Escreva seu endereço" << std::endl;
            std::cin >> global;
            cliente.atualiza_endereco(global);
            break;
        }
        case 3:{
            std::cout << "Escreva seu telefone" << std::endl;
            std::cin >> global;
            cliente.atualiza_telefone(global);
        }
        case 4:{

            std::cout << "Escreva sua forma de pagamento" << std::endl;
            std::cin >> global;
            cliente.atualiza_forma_pagameto(global);

        }
              
        default:
            break;
        }
        return 0;
    }
}