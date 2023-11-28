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


    Menu *Editperfil::nextWithCliente(unsigned option, Cliente cliente)
    {
        std::string global;
        switch (option)
        {
            case 1:
            {
                std::cout << "Digite o seu nome" << std::endl;
                std::cin >> global;
                cliente.atualiza_nomeusuario(global);
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
                cliente.atualiza_telefone(std::stoul(global));
                std::cout << "Atualizado com sucesso, novo número de telefone: " << cliente.GetTelefone() << std::endl;
                break;
            }

        }

        return 0;
    }


    Menu *Editperfil::nextWithAdmin(unsigned option, Administrador adm)
    {
        std::string global;
        switch (option)
        {
        case 1:
        {
            std::cout << "Digite o seu nome" << std::endl;
            std::cin >> global;
            adm.atualiza_nomeusuario(global);
            std::cout << "Atualizado com sucesso, novo nome: " << adm.GetNome() << std::endl;

            break;
        }

        case 2:
        {
            std::cout << "Escreva seu telefone" << std::endl;
            std::cin >> global;
            adm.atualiza_telefone(std::stoul(global));
            std::cout << "Atualizado com sucesso, novo número: " << adm.GetTelefone() << std::endl;
            break;
        }

        default:
            break;
        }

        return 0;
    }
}