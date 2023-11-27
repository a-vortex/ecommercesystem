#include "../../include/ui/navegamenu.hpp"
#include "menu.cpp"

namespace ecommerce::ui
{

    NavegaMenu::NavegaMenu()
    {
        _title = "Editar Informações";
        _options.push_back("1- Visualizar todos os produtos");
        _options.push_back("2- Pesquisar produto por nome");
        _options.push_back("3- Pesquisar produto por tipo");
        _options.push_back("4- Pesquisar produto por preço");
    }

    Menu *NavegaMenu::navegamenunext(unsigned option, std::string pesquisa, Estoque estoque, Busca busca)
    {

        switch (option)
        {
        case 1:
        {
            std::cout << "Segue lista de todos os produtos disponíveis!" << std::endl;
            busca.busca_produtos_todos(estoque.lista_produtos());
        }

        break;
        case 2:
        {
            std::cout << "Segue o produto:" << std::endl;
            busca.busca_produtos_nome(pesquisa, estoque.lista_produtos()).GetName();
        }
        break;
        case 3:
        {
            float number = std::stof(pesquisa);
            std::cout << "Segue lista de todos o produto do tipo escolhido!" << std::endl;
            busca.busca_produtos_preco(number, estoque.lista_produtos());
        }

        break;
        case 4:
        {
            std::cout << "Segue lista de todos o produto do preço escolhido!" << std::endl;
            busca.busca_produtos_tipo(pesquisa, estoque.lista_produtos());
        }
        break;
        default:
            break;
        }

        return nullptr;
    }
}
