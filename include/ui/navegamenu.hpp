// #pragma once

#include "menu.hpp"

namespace ecommerce::ui
{
    class NavegaMenu : public Menu
    {
    public:
        NavegaMenu();

        Menu *navegamenunext(unsigned option, std::string pesquisa, Estoque estoque, Busca busca);
    };
}
