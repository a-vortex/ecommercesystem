#pragma once

#include "menu.hpp"

namespace ecommerce::ui
{
    class LoginMenu : public Login
    {
    public:
        LoginMenu();

        Login *next(unsigned option) override;
    };
}