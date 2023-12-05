#include "../../include/ui/clientemenu.hpp"

#include <iostream>
#include <string>

namespace ecommerce::ui
{
    ClienteMenu::ClienteMenu(Cliente const &client) : _client(client) 
    {
        _title = "Olá, sr(a). " + _client.GetNome();
        _options.push_back("1 - Navegação");
        _options.push_back("2 - Acesso ao Carrinho");
        _options.push_back("3 - Sair");
    }

    Menu *ClienteMenu::next(unsigned option)
    {
        switch (option)
        {
            case 1:
                return new NavegaMenu;

            case 2:
                return new CartAcess(_client);

            case 3:
                return nullptr;
        }
        return nullptr;
    }
}
