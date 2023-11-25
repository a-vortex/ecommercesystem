/*
    menuscreen.hpp
    Author: Yuri Wada
    yuriwada@ufmg.br

    Cria a tela de menu
*/

#pragma once

#include <string>
#include <vector>
#include <iostream>

namespace ecommerce::ui
{

    class Login
    {
    public:
        virtual ~Login() = default;
        virtual Login *next(unsigned option) = 0;
        virtual void render() const;

    protected:
        std::string _title = "Tela de Login";
        std::vector<std::string> _options = {"0 - Sair"};
    };

}