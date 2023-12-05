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
        unsigned _opt = 1;
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
                        std::cout << "> Logando: " << _client.GetName() << std::endl;
                        std::cout << "\n\n";
                        Cliente cliente(_client.GetName(), "addr", 12345);
                        return new ClienteMenu(cliente);
                    }
                    std::cout << "> Usuário ou senha inválidos!! <" << std::endl;
                    std::cout << "> Insira nova opção: " << std::endl;
                    std::cout << "1 - Tentar novamente" << std::endl;
                    std::cout << "4 - Encerrar Sistema" << std::endl;
                    std::cin >> _opt;
                    if(_opt != 1 && _opt != 4) 
                    {
                        std::cout << "> Opção inválida!!" << std::endl;
                        return LoginMenu::next(1); 
                    }
                    else
                    {
                        system("clear||cls");
                        return LoginMenu::next(_opt);
                    }
                }

                else if(tipo == "a")
                {
                    if(_admin.Autenticacao(PATH_ADMIN))
                    {
                        std::cout << "> Logando: " << _admin.GetName() << std::endl;
                        std::cout << "\n\n";
                        Administrador admin(_admin.GetName(), "addr", 12345);
                        return new LogadoAdm(admin);
                    }
                    std::cout << "> Usuário ou senha inválidos!! <" << std::endl;
                    std::cout << "> Insira nova opção: " << std::endl;
                    std::cout << "1 - Tentar novamente" << std::endl;
                    std::cout << "4 - Encerrar Sistema" << std::endl;
                    std::cin >> _opt;
                    system("clear||cls");
                    if(_opt != 1 && _opt != 4) 
                    {
                        std::cout << "> Opção inválida!!" << std::endl;
                        return LoginMenu::next(1); 
                    }
                    return LoginMenu::next(_opt);
                }
                std::cout << "> Usuário ou senha inválidos!! <" << std::endl;
                std::cout << "> Insira nova opção: " << std::endl;
                std::cout << "1 - Tentar novamente" << std::endl;
                std::cout << "4 - Encerrar Sistema" << std::endl;
                std::cin >> _opt;
                system("clear||cls");
                if(_opt != 1 && _opt != 4) 
                {
                    std::cout << "> Opção inválida!!" << std::endl;
                    system("clear||cls");
                    return LoginMenu::next(1); 
                }
                return LoginMenu::next(_opt);
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
                return LoginMenu::next(2);
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
                return LoginMenu::next(3);             
            }

            case 4:
                return nullptr;

            default:
            {
                std::cout << "> Opção inválida!! <" << std::endl;
                std::cout << "> Reinicie o sistema <" << std::endl;
                return nullptr;
            }

        }
        return nullptr;
    }
}