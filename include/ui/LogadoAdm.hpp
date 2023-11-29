#pragma once

#include <string>
#include <vector>
#include "menu.hpp"

namespace ecommerce::ui
{
    class LogadoAdm : public Menu
    {
    public:
        LogadoAdm();
        /// @brief Permite editar ou adicionar um produto
        /// @param  option Número da opção escolhida
        /// @param  produto Classe do tipo produto
        Menu *nextEditaProduto(unsigned option) override;
    };
}
