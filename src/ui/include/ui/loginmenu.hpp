/*
    loginmenu.hpp
    Author: Yuri Wada
    yuriwada@ufmg.br

    Cria a tela de login
*/

#pragma once

#include "menu.hpp"
#include "../../include/user/administrador.hpp"
#include "../../include/user/cliente.hpp"
#include "../../include/user/usuario.hpp"
#include "../../include/exc/excfuncoes.hpp"

#include <iostream>
#include <fstream>
#include <stdexcept>

namespace ecommerce::ui
{
    class LoginMenu : public Menu
    {
    public:
        LoginMenu();

        static const std::string PATH_CLIENT;
        static const std::string PATH_ADMIN;
        void cadastrarCliente(const std::string& email, const std::string& senha);
        void cadastrarAdmin(const std::string& email, const std::string& senha);
        Menu *next(unsigned option) override;
    };
}