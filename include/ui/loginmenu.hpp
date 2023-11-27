#pragma once

#include "menu.hpp"
#include "../../include/user/administrador.hpp"
#include "../../include/user/cliente.hpp"
#include "../../include/user/usuario.hpp"

#include <iostream>
#include <fstream>
#include <stdexcept>

namespace ecommerce::ui
{
    class LoginMenu : public Menu
    {
    public:
        LoginMenu();

        static const std::string PATHCLIENT;
        static const std::string PATHADMIN;
        void cadastrarCliente(const std::string& email, const std::string& senha);
        void cadastrarAdmin(const std::string& email, const std::string& senha);
        Menu *next(unsigned option) override;
    };
}