#include "../../include/ui/cadastro.hpp"

namespace ecommerce::ui
{
    auto contemApenasdigitos = [] (const std::string& str)
    {
        for(char c : str)
        {
            if(!std::isdigit(c))
            {
                return false;
            }
        }
        return true;
    };

    bool
    Cadastro::CadastrarUsuario(std::string const &PATH)
    {
        std::cout << "> Nome: " << std::endl;
        std::getline(std::cin >> std::ws, _name);

        std::cout << "> Endereço: " << std::endl;
        std::getline(std::cin >> std::ws, _addr);
                
        std::cout << "> Telefone: " << std::endl;
        std::getline(std::cin >> std::ws, _phone);

        while(!contemApenasdigitos(_phone))
        {
            std::cout << "> Numero de telefone inválido. Por favor, insira novamente. <" << std::endl;
            std::getline(std::cin >> std::ws, _phone);
        }

        std::cout << "> Email: " << std::endl;
        std::cin >> _mail;

        std::cout << "> Senha: " << std::endl;
        std::cin >> _pass;
        
        std::ofstream arquivo(PATH, std::ios_base::app);

        if(arquivo.is_open())
        {
            arquivo << _mail << std::endl;
            arquivo << _pass << std::endl;
            arquivo.close();
            return true;
        }
        return false;
    }

    bool
    Cadastro::Autenticacao(std::string const &PATH)
    {
        std::string email;
        std::string senha;

        std::cout << "> Email: " << std::endl;
        std::cin >> email;
                
        std::cout << "> Senha: " << std::endl;
        std::cin >> senha;

        std::ifstream arquivo(PATH);
        if(arquivo.is_open())
        {
            std::string linha;

            bool ekey = false;
            bool pkey = false;

            while(std::getline(arquivo, linha))
            {
                if(linha.find(email) != std::string::npos) ekey = true;
                if(linha.find(senha) != std::string::npos) pkey = true;
                if(ekey && pkey)
                {
                    arquivo.close();
                    return true;
                }
            }
        }

        return false;
    }

    std::string
    Cadastro::GetName()
    {
        return _name;
    }

    std::string
    Cadastro::GetAddr()
    {
        return _addr;
    }

    std::string
    Cadastro::GetPhone()
    {
        return _phone;
    }

    std::string
    Cadastro::GetMail()
    {
        return _mail;
    }
}
