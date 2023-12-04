#include "../../include/ui/loginmenu.hpp"
#include "../../include/ui/clientemenu.hpp"
#include "../../include/ui/LogadoAdm.hpp"

namespace ecommerce::ui
{
    const std::string LoginMenu::PATH_CLIENT = "autenticacaocliente.txt";
    const std::string LoginMenu::PATH_ADMIN = "autenticacaoadmin.txt";
    LoginMenu::LoginMenu()
    {
        _title = "Bem-vindo ao Sistema de E-commerce";
        _options.push_back("1 - Login");
        _options.push_back("2 - Cadastrar Cliente");
        _options.push_back("3 - Cadastrar Administrador");
        _options.push_back("4 - Encerrar Sistema");
    }

    Menu
    *LoginMenu::next(unsigned option)
    {
        switch(option)
        {
            case 1:
            {
                std::string tipo;
                std::cout << "> Tipo de usuário (c: cliente, a: administrador): ";
                std::getline(std::cin >> std::ws, tipo);
                
                if(tipo == "c")
                {
                    if(_client.Autenticacao(PATH_CLIENT))
                    {
                        std::cout << "> Logando: " << _client.GetMail() << std::endl;
                        std::cout << "\n\n";
                        _clientLogin.leArquivo(PATH_CLIENT, _client.GetMail());
                        Cliente cliente(_clientLogin.GetName(), _clientLogin.GetAddr(), std::stoul(_clientLogin.GetPhone()));
                        return new ClienteMenu(cliente);
                    }
                    std::cout << "> Usuário ou senha inválidos!! <" << std::endl;
                    return nullptr;
                }

                else if(tipo == "a")
                {
                    if(_admin.Autenticacao(PATH_ADMIN))
                    {
                        std::cout << "> Logando: " << _admin.GetMail() << std::endl;
                        std::cout << "\n\n";
                        _adminLogin.leArquivo(PATH_ADMIN, _admin.GetMail());
                        Administrador admin(_adminLogin.GetName(), _adminLogin.GetAddr(), std::stoul(_adminLogin.GetPhone()));
                        return new LogadoAdm(admin);
                    }
                    std::cout << "> Usuário ou senha inválidos!! <" << std::endl;
                    return nullptr;
                }

                std::cout << "> Tipo de usuário inválido!! <" << std::endl;
                return nullptr;
            }

            case 2:
            {
                if(_client.CadastrarUsuario(PATH_CLIENT))
                {
                    std::cout << "> Cliente cadastrado com sucesso! <" << std::endl;
                    std::cout << "\n\n";
                    Cliente cliente(_client.GetName(), _client.GetAddr(), std::stoul(_client.GetPhone()));
                    return new ClienteMenu(cliente);
                }

                std::cout << "> Erro no cadastro! <" << std::endl;
                return nullptr;
            }

            case 3:
            {
                if(_admin.CadastrarUsuario(PATH_ADMIN))
                {
                    std::cout << "> Administrador cadastrado com sucesso! <" << std::endl;
                    std::cout << "\n\n";
                    Administrador admin(_admin.GetName(), _admin.GetAddr(), std::stoul(_admin.GetPhone()));
                    return new LogadoAdm(admin);
                }

                std::cout << "> Erro no cadastro! <" << std::endl;
                return nullptr;             
            }

            case 4:
                return nullptr;

        }
        return nullptr;
    }
}