/*
    menuscreen.hpp
    Author: Yuri Wada
            Kauan Valente
    yuriwada@ufmg.br

    Cria a tela de menu
*/

#pragma once

#include "../user/cliente.hpp"
#include "../user/administrador.hpp"
#include "../sys/estoque.hpp"
#include "../sys/busca.hpp"
#include "../sys/produto.hpp"

#include <string>
#include <vector>
#include <iostream>

namespace ecommerce::ui
{

    class Menu
    {
    public:
       
        virtual ~Menu() = default;
        virtual Menu *next(unsigned option) { return nullptr; };
        virtual Menu *nextWithAdmin(unsigned option, Administrador adm) { return nullptr; }
        virtual Menu *nextWithCliente(unsigned option, Cliente cliente) { return nullptr; }
        virtual Menu *nextEditaProduto(unsigned option)
        {
            return nullptr;
        }
        virtual Menu *navegamenunext(unsigned option, Estoque estoque, Busca busca)
        {
            return nullptr;
        };
        Estoque glob;
        virtual void render() const;

    protected:
        std::string _title = "Tela de Login";
        std::vector<std::string> _options;
    };

}