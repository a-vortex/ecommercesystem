#pragma once

#include <string>
#include <iostream>
#include <fstream>

namespace ecommerce::ui
{
    class Login
    {
    private:
        std::string _name;
        std::string _addr;
        std::string _phone;
    
    public:
        bool leArquivo(std::string const &PATH, std::string const &_mail);
        std::string GetName();
        std::string GetAddr();
        std::string GetPhone();
    };
}