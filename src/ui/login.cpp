#include "../../include/ui/login.hpp"

namespace ecommerce::ui
{
    bool
    Login::leArquivo(std::string const &PATH, std::string const &_mail)
    {
        std::ifstream arquivo(PATH);
        if(arquivo.is_open())
        {
            std::string linha;
            while(std::getline(arquivo, linha))
            {
                if(linha.find(_mail) != std::string::npos)
                {
                    std::getline(arquivo, _addr);
                    arquivo >> _phone;
                    arquivo.close();
                    return true;
                }
            }
            arquivo.close();
        }
        std::cerr << "> Erro no Login! <" << std::endl;
        return false;
    }

    std::string
    Login::GetName()
    {
        return _name;
    }   

    std::string
    Login::GetAddr()
    {
        return _addr;
    }   

    std::string
    Login::GetPhone()
    {
        return _phone;
    }   
}