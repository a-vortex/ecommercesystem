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

    class Menu
    {
    public:
        virtual ~Menu() = default;
        virtual Menu *next(unsigned option) = 0;
        virtual void render() const;

    protected:
        std::string _title = "Tela de Login";
        std::vector<std::string> _options = {"0 - Sair"};
    };

}