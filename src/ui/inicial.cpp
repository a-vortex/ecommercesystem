#include "../../include/ui/inicial.hpp"
#include "loginmenu.cpp"
#include "../user/usuario.cpp"
#include "menu.cpp"

namespace ecommerce::ui
{

    Inicial::Inicial()
    {
        _title = "Editar Informações";
        _options.push_back("1- Opções de acesso");
        _options.push_back("2- Encerrar sistema");
        }

    Menu *Inicial::next(unsigned option)
    {

        switch (option)
        {
        case 1:
        {
            LoginMenu login;
            std::cout << "Seja bem vindo ao nosso ecommerce, como deseja proceder?";
            login.render();
            int option;
            std::cin >> option;
            login.next(option);
        }

        break;
        case 4:
        {

            break;
        default:
            break;
        }

            return nullptr;
        }
    }

}
int main()
{
    ecommerce::ui::Inicial teste;
    teste.next(1);
}