#pragma once

#include "menu.hpp"

namespace ecommerce::ui
{
    class LoginMenu : public Menu
    {
    public:
        LoginMenu();

        Menu *next(unsigned option) override;
    };
}