#include "../include/ui/inicial.hpp"
#include "../include/ui/loginmenu.hpp"
#include "../include/user/usuario.hpp"
#include "../include/ui/menu.hpp"

namespace ui = ecommerce::ui;
// {

//     // Inicial::Inicial()
//     // {
//     //     _title = "Editar Informações";
//     //     _options.push_back("1- Opções de acesso");
//     //     _options.push_back("2- Encerrar sistema");
//     //     }

//     Menu *Inicial::next(unsigned option)
//     {

//         switch (option)
//         {
//         case 1:
//         {
//             LoginMenu login;
//             login.render();
//             int option;
//             std::cin >> option;
//             login.next(option);
//             break;
//         }

//         case 4:
//         {

//             break;
//         }
//         default:
//             break;

//             return nullptr;
//         }
//         return nullptr;
//     }

// }
int main()
{
    ui::LoginMenu login;
    login.render();

    unsigned option;
    std::cin >> option;

    ui::Menu *menu = login.next(option);
    while (menu != nullptr) {
        menu->render();
        std::cin >> option;

        ui::Menu *old_menu = menu;
        menu = menu->next(option);

        delete old_menu;
    }
    return 0;
}