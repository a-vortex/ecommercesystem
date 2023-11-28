#include "../../include/ui/inicial.hpp"
#include "loginmenu.cpp"
#include "../user/usuario.cpp"
#include "menu.cpp"

namespace ecommerce::ui
{

    Inicial::Inicial()
    {
        _title = "Editar Informações";
        _options.push_back("1- Login");
        _options.push_back("2- Realizar cadastro");
        _options.push_back("3- Encerrar sistema");
    }

    Menu *Inicial::next(unsigned option)
    {

        switch (option)
        {
        case 1:
        {
            LoginMenu login;
            std::cout << "Vamos realizar seu login!";
            login.next();
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
}