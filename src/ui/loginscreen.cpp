#include "../../include/ui/loginscreen.hpp"

namespace ecommerce::ui
{
    void
    Login::render() const
    {
        std::string border(_title.size() + 5, '=');
        std::cout << border << '\n';
        std::cout << "|| " << _title << '\n';
        std::cout << border << "\n\n";
 
        for (std::string opt : _options)
        {
            std::cout << opt << '\n';
        }
 
        std::cout << std::endl << "> Opção: ";
    }
}