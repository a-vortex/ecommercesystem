#include "../../include/ui/clientemenu.hpp"

#include <iostream>
#include <string>

namespace ecommerce::ui
{
    ClienteMenu::ClienteMenu() 
    {
        _title = "Olá, sr(a). ";
        //  + _client.GetNome()
        _options.push_back("1 - Navegação");
        _options.push_back("2 - Acesso ao Carrinho");
        _options.push_back("3 - Sair");
    }

    Menu *ClienteMenu::next(unsigned option)
    {
        Estoque estoque;
        switch (option)
        {
        case 1:
        {
            std::cout << "\n\n";
            ui::NavegaMenu navega;
            navega.render();
            unsigned option;
            std::cin >> option;
            navega.navegamenunext(option);
 
        }

        case 2:
            break;

        case 3:
            break;
        }
        return nullptr;
    }
}
