/*
    acessocarrinho.hpp
    Author: M Clara Contarini
    mccontarinid@gmail.com

    Acessa o carrinho
*/

#pragma once

#include "menu.hpp"
#include "clientemenu.hpp"
#include "../sys/carrinho.hpp"
#include "../sys/produto.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

namespace ecommerce::ui
{
    class CartAcess : public Menu
    {
        private:
            Cliente _cliente;
        public:
            std::string estoque=Estoque::PATH_ESTOQUE;
            std::string carrinho=Carrinho::PATH_CARRINHO;
            
            CartAcess(Cliente const &client);
            /// @brief Permite escolher a tela seguinde na navegação
            /// @param  option Número da opção escolhida
            Menu *next(unsigned option) override;
    };
}