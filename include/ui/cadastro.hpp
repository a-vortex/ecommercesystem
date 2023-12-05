#pragma once

#include <string>
#include <iostream>
#include <fstream>

namespace ecommerce::ui
{
    class Cadastro
    {
    private:
        std::string _name;
        std::string _addr;
        std::string _phone;
        std::string _mail;
        std::string _pass;
        
    public:
        // static const std::string PATH_CLIENT;
        // static const std::string PATH_ADMIN;
        bool CadastrarUsuario(std::string const &PATH);
        bool Autenticacao(std::string const &PATH);

        std::string GetName();
        std::string GetAddr();
        std::string GetPhone();
        std::string GetMail();
    };
}