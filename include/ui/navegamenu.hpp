// #pragma once

#include "menu.hpp"


namespace ecommerce::ui
{
    class NavegaMenu : public Menu
    {
    private:
        Busca global;
        
    public:
        NavegaMenu();

        Menu *next(unsigned option) override;
    };
}
