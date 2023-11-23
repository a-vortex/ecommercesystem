#pragma once

#include <string>
#include <vector>
#include "menu.hpp"
#include "../../include/sys/header.hpp"

namespace ecommerce::ui
{

    class Cadastro : public Menu
    {
    public:
        Cadastro();
        Menu *next(unsigned option) override;
    };

}
