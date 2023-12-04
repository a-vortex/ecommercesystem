#pragma once

#include "menu.hpp"
#include "../user/cliente.hpp"
#include "../sys/estoque.hpp"
#include "../sys/produto.hpp"
#include "navegamenu.hpp"

#include <string>

namespace ecommerce::ui
{
    class ClienteMenu : public Menu
    {
    private:
        // Cliente const &_client;
    
    public:
        // ClienteMenu(Cliente const &client);
        ClienteMenu();
        Menu *next(unsigned option) override;
    };
}