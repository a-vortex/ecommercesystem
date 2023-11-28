#pragma once

#include <string>
#include <vector>
#include "menu.hpp"

namespace ecommerce::ui
{
    class EditaProduto : public Menu
    {
    public:
        EditaProduto();
        /// @brief Permite editar ou adicionar um produto
        /// @param  option Número da opção escolhida
        /// @param  produto Classe do tipo produto
        Menu *nextEditaProduto(unsigned option) override;
    };
}
