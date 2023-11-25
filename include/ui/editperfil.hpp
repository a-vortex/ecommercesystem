#pragma once

#include <string>
#include <vector>
#include "menu.hpp"
#include "../../include/sys/header.hpp"

namespace ecommerce::ui
{

    class Editperfil : public Menu
    {
    public:

        /// @brief Constroi um menu para editar perfil
        Editperfil();


        Menu *next(unsigned option) override;
    };

}