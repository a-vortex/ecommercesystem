/*
    acessocarrinho.hpp
    Author: M Clara Contarini
    mccontarinid@gmail.com

    Acessa o carrinho
*/

#pragma once

#include "menu.hpp"
#include "../sys/carrinho.hpp"

namespace ecommerce::ui
{
    class CartAcess : public Menu
    {
        public:
            CartAcess();
            /// @brief Permite escolher a tela seguinde na navegação
            /// @param  option Número da opção escolhida
            Menu *next(unsigned option) override;
    };
}