/*
    loginmenu.hpp
    Author: Yuri Wada
    yuriwada@ufmg.br

    Cria a tela de login
*/

#pragma once

#include "menu.hpp"
#include "cadastro.hpp"
#include "login.hpp"
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
    private:
        Cadastro _client;
        Cadastro _admin;
        Login _clientLogin;
        Login _adminLogin;

    public:
        LoginMenu();
        static const std::string PATH_CLIENT;
        static const std::string PATH_ADMIN;
        Menu *next(unsigned option) override;
    };
}