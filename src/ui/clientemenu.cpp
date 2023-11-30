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
        _options.push_back("3 - Editar perfil");
        _options.push_back("4 - Sair");
    }

    Menu
    *ClienteMenu::next(unsigned option)
    {
        switch(option)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
        }
        return nullptr;
    }
}
