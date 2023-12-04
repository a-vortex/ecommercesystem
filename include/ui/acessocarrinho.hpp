/*
    acessocarrinho.hpp
    Author: M Clara Contarini
    mccontarinid@gmail.com

    Acessa o carrinho
*/

#pragma once

#include "menu.hpp"
#include "../sys/carrinho.hpp"
#include "../sys/produto.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

namespace ecommerce::ui
{
    class CartAcess : public Menu
    {
        public:
            static const std::string PATH_ESTOQUE;
            static const std::string PATH_CARRINHO;
            
            CartAcess();
            /// @brief Permite escolher a tela seguinde na navegação
            /// @param  option Número da opção escolhida
            Menu *next(unsigned option) override;
    };
}