#include "../include/ui/loginmenu.hpp"
#include "../include/user/usuario.hpp"
#include "../include/ui/menu.hpp"

namespace ui = ecommerce::ui;

int main()
{
    ui::LoginMenu login;
    login.render();

    unsigned option;
    std::cin >> option;
    system("clear||cls");

    ui::Menu *menu = login.next(option);
    while (menu != nullptr) {
        menu->render();
        std::cin >> option;
        system("clear||cls");

        ui::Menu *old_menu = menu;
        menu = menu->next(option);

        delete old_menu;
    }
    return 0;
}
