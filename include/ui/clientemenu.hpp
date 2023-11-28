#pragma once

#include "menu.hpp"
#include "../user/cliente.hpp"

#include <string>

namespace ecommerce::ui
{
    class ClienteMenu : public Menu
    {
    private:
        Cliente const &_client;
    
    public:
        ClienteMenu(Cliente const &client);
        Menu *next(unsigned option) override;
    };
}