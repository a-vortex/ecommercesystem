#include "../../include/ui/loginmenu.hpp"

namespace ecommerce::ui
{
    const std::string LoginMenu::PATHCLIENT = "../../database/user/autenticacaocliente.txt";
    const std::string LoginMenu::PATHADMIN = "../../database/user/autenticacaoadmin.txt";

    LoginMenu::LoginMenu()
    {
        _title = "Menu de Autenticação";
        _options.push_back("1 - Entrar");
        _options.push_back("2 - Cadastrar Cliente");
        _options.push_back("3 - Cadastrar Administrador");
    }

    void
    LoginMenu::cadastrarCliente(const std::string& email, const std::string& senha)
    {
        std::ofstream arquivo(PATHCLIENT, std::ios_base::app);

        if(arquivo.is_open())
        {
            arquivo << email << std::endl;
            arquivo << senha << std::endl;
            arquivo.close();
            std::cout << "Novo cliente cadastrado com sucesso!" << std::endl;
        }
        else
        {
            throw std::runtime_error("Erro ao realizar cadastro!");
        }
    }

    void
    LoginMenu::cadastrarAdmin(const std::string& email, const std::string& senha)
    {
        std::ofstream arquivo(PATHADMIN, std::ios_base::app);
        if(arquivo.is_open())
        {
            arquivo << email << std::endl;
            arquivo << senha << std::endl;
            arquivo.close();
            std::cout << "Administrador cadastrado com sucesso!" << std::endl;
        }
        else
        {
            throw std::runtime_error("Erro ao realizar cadastro!");
        }
    }

    Menu
    *LoginMenu::next(unsigned option)
    {
        auto ler_autenticacao = [] (std::string &email, std::string &senha, char &tipo)
        {
            std::ifstream arquivo;
            std::string path;

            if (tipo == 'c')
            {
                arquivo.open(PATHCLIENT);
                path = PATHCLIENT;
            }
            else if (tipo == 'a')
            {
                arquivo.open(PATHADMIN);
                path = PATHADMIN;
            }

            if (!arquivo.is_open())
            {
                throw std::runtime_error("Erro na abertura do arquivo: " + path);
            }

            std::string linha;
            bool ekey = false;
            bool pkey = false;

            while (std::getline(arquivo, linha))
            {
                if (linha.find(email) != std::string::npos) ekey = true;
                if (linha.find(senha) != std::string::npos) pkey = true;
                if (ekey && pkey)
                {
                    arquivo.close(); // Fechar o arquivo apos encontrar a autenticação
                    return true;
                }
            }

            arquivo.close(); // Fechar o arquivo apos terminar a leitura sem autenticação
            return false;
        };

        switch(option)
        {
            case 1:
            {
                char tipo;
                std::cout << "> Tipo de usuário (c: cliente, a: administrador): ";
                std::cin >> tipo;
                if(tipo != 'a' && tipo != 'c')
                {
                    std::cout << "Tipo de usuário inválido!!" << std::endl;
                }

                std::string email;
                std::string senha;

                if(ler_autenticacao(email, senha, tipo))
                {
                    std::cout << "> Logando: " << email << std::endl;
                }
                break;
            }

            case 2:
            {
                std::string nome;
                std::string endereco;
                unsigned telefone;
                std::string email;
                std::string password;

                std::cout << "> Nome: " << std::endl;
                std::cin >> nome;

                std::cout << "> Endereço: " << std::endl;
                std::cin >> endereco;
                
                std::cout << "> Telefone: " << std::endl;
                std::cin >> telefone;

                std::cout << "> Email: " << std::endl;
                std::cin >> email;

                std::cout << "> Senha: " << std::endl;
                std::cin >> password;

                Cliente cliente(nome, endereco, telefone);
                this->cadastrarCliente(email, password);
                break;
            }

            case 3:
            {
                std::string nome;
                std::string endereco;
                unsigned telefone;
                std::string email;
                std::string password;

                std::cout << "> Nome: " << std::endl;
                std::cin >> nome;

                std::cout << "> Endereço: " << std::endl;
                std::cin >> endereco;
                
                std::cout << "> Telefone: " << std::endl;
                std::cin >> telefone;

                std::cout << "> Email: " << std::endl;
                std::cin >> email;

                std::cout << "> Senha: " << std::endl;
                std::cin >> password;                
            }
        }
    }
}