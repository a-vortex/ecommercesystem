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
#include "../user/cliente.hpp"
#include "../user/administrador.hpp"
#include "../sys/estoque.hpp"
#include "../sys/busca.hpp"
#include "../sys/produto.hpp"
// #include "../../src/sys/estoque.cpp"
// #include "../../src/sys/busca.cpp"

namespace ecommerce::ui
{

    class Menu
    {
    public:
        virtual ~Menu() = default;
        virtual Menu *next(unsigned option) { return nullptr; };
        virtual Menu *nextWithAdmin(unsigned option, Administrador adm) { return nullptr; }
        virtual Menu *nextWithCliente(unsigned option, Cliente cliente) { return nullptr; }

        virtual void render() const;

    protected:
        std::string _title = "Tela de Login";
        std::vector<std::string> _options = {"0 - Sair"};
    };

}