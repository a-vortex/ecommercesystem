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
        // auto ler_autenticacao = [] (std::string &email, std::string &senha, char &tipo)
        // {
        //     std::ifstream arquivo;
        //     std::string path;

        //     if (tipo == 'c')
        //     {
        //         arquivo.open(PATH_CLIENT);
        //         path = PATH_CLIENT;
        //     }
        //     else if (tipo == 'a')
        //     {
        //         arquivo.open(PATH_ADMIN);
        //         path = PATH_ADMIN;
        //     }

        //     if (!arquivo.is_open())
        //     {
        //         throw std::runtime_error("> Erro na abertura do arquivo: " + path + " <");
        //     }

        //     std::string linha;
        //     bool ekey = false;
        //     bool pkey = false;

        //     while (std::getline(arquivo, linha))
        //     {
        //         if (linha.find(email) != std::string::npos) ekey = true;
        //         if (linha.find(senha) != std::string::npos) pkey = true;
        //         if (ekey && pkey)
        //         {
        //             std::cout << "> Autenticação bem sucedida <" << std::endl;
        //             arquivo.close(); // Fechar o arquivo apos encontrar a autenticação
        //             return true;
        //         }
        //     }

        //     std::cout << "> Email ou senha invalidos! <" << std::endl;
        //     arquivo.close(); // Fechar o arquivo apos terminar a leitura sem autenticação
        //     return false;
        // };

        switch(option)
        {
            case 1:
            {
                char tipo;
                std::cout << "> Tipo de usuário (c: cliente, a: administrador): ";
                std::cin >> tipo;
                
                if(tipo == 'c')
                {
                    if(_client.Autenticacao(PATH_CLIENT))
                    {
                        std::cout << "> Logando: " << _client.GetMail() << std::endl;
                        std::cout << " erro: " << _client.GetPhone() << std::endl;
                        // Cliente cliente(_client.GetName(), _client.GetAddr(), std::stoul(_client.GetPhone()));
                        // return new ClienteMenu(cliente);
                        break;
                    }
                    std::cout << "> Usuário ou senha inválidos!! <" << std::endl;
                    break;
                }
                else if(tipo == 'a')
                {
                    if(_admin.Autenticacao(PATH_ADMIN))
                    {
                        std::cout << "> Logando: " << _admin.GetMail() << std::endl;
                        Administrador admin(_admin.GetName(), _admin.GetAddr(), std::stoul(_admin.GetPhone()));
                        return new LogadoAdm(admin);
                    }
                    std::cout << "> Usuário ou senha inválidos!! <" << std::endl;
                    break;
                }
                else
                {
                    std::cout << "> Tipo de usuário inválido!! <" << std::endl;
                    return nullptr;
                }
                // return nullptr;
            }

            case 2:
            {
                if(_client.CadastrarUsuario(PATH_CLIENT))
                {
                    std::cout << "\n\n";
                    std::cout << "> Cliente cadastrado com sucesso! <" << std::endl;
                }
                else
                {
                    std::cout << "> Erro no cadastro! <" << std::endl;
                }

                Cliente cliente(_client.GetName(), _client.GetAddr(), std::stoul(_client.GetPhone()));
                return new ClienteMenu(cliente);
            }

            case 3:
            {
                if(_admin.CadastrarUsuario(PATH_ADMIN))
                {
                    std::cout << "\n\n";
                    std::cout << "> Administrador cadastrado com sucesso! <" << std::endl;
                }
                else
                {
                    std::cout << "> Erro no cadastro! <" << std::endl;
                }                
                Administrador admin(_admin.GetName(), _admin.GetAddr(), std::stoul(_admin.GetPhone()));
                return new LogadoAdm(admin);
            }

            case 4:
                return nullptr;

        }
        return nullptr;
    }

}