#pragma once

#include "menu.hpp"
#include "../user/cliente.hpp"
#include "../sys/estoque.hpp"
#include "../sys/produto.hpp"
#include "navegamenu.hpp"
#include "acessocarrinho.hpp"


#include <string>

namespace ecommerce::ui
{
    class ClienteMenu : public Menu
    {
    private:
        Cliente &_client;
    
    public:
        ClienteMenu(Cliente &client);
        Menu *next(unsigned option) override;
    };
}