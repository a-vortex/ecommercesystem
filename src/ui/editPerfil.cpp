#include "../../include/ui/editperfil.hpp"
#include <iostream>
#include <string>

namespace ecommerce::ui
{
    Editperfil::Editperfil(unsigned &choice) : _choice(choice)
    {
            _title = "Editar Perfil";
            _options.push_back("1 - Editar nome");
            _options.push_back("2 - Editar Endereço");
            _options.push_back("3 - Editar numero de telefone");
    }
        
    Menu *Editperfil::nextWithCliente(unsigned option, Cliente cliente)
    {
        std::string generica;
        switch (option)
        {
            case 1:
            {
                std::cout << "Digite o seu nome" << std::endl;
                std::cin >> generica;
                cliente.atualiza_nomeusuario(generica);
                std::cout << "Atualizado com sucesso, novo nome: " << cliente.GetNome() << std::endl;
                break;
            }

            case 2:
            {
                std::cout << "Escreva seu endereço" << std::endl;
                std::cin >> generica;
                cliente.atualiza_endereco(generica);
                std::cout << "Atualizado com sucesso, novo endereço: " << cliente.GetEndereco() << std::endl;
                break;
            }

            case 3:
            {
                std::cout << "Escreva seu telefone" << std::endl;
                std::cin >> generica;
                cliente.atualiza_telefone(std::stoul(generica));
                std::cout << "Atualizado com sucesso, novo número de telefone: " << cliente.GetTelefone() << std::endl;
                break;
            }

        }

        return 0;
    }


    Menu *Editperfil::nextWithAdmin(unsigned option, Administrador adm)
    {
        std::string generica;
        switch (option)
        {
            case 1:
            {
                std::cout << "Digite o seu nome" << std::endl;
                std::cin >> generica;
                adm.atualiza_nomeusuario(generica);
                std::cout << "Atualizado com sucesso, novo nome: " << adm.GetNome() << std::endl;

                break;
            }

            case 2:
            {
                std::cout << "Escreva seu telefone" << std::endl;
                std::cin >> generica;
                adm.atualiza_telefone(std::stoul(generica));
                std::cout << "Atualizado com sucesso, novo número: " << adm.GetTelefone() << std::endl;
                break;
            }
        }

        return 0;
    }
}