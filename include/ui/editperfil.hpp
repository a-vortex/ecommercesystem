#pragma once

#include <string>
#include <vector>
#include "menu.hpp"

namespace ecommerce::ui
{
    class Editperfil : public Menu
    {
    private:
        unsigned _choice;

    public:
        Editperfil(unsigned &choice);

        /// @brief Permite editar um informação específica do usuário administrador
        /// @param  option Número da opção escolhida
        /// @param  adm Classe do tipo Administrador
        Menu *nextWithAdmin(unsigned option, Administrador adm) override;

        /// @brief Permite editar um informação específica do usuário cliente
        /// @param  option Número da opção escolhida
        /// @param  adm Classe do tipo Cliente
        Menu *nextWithCliente(unsigned option, Cliente cliente) override;
    };
}
