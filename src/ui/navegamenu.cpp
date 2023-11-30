#include "../../include/ui/navegamenu.hpp"
#include "../../include/sys/estoque.hpp"
#include "../../include/sys/produto.hpp"
#include "../../include/sys/busca.hpp"
#include "../../include/ui/menu.hpp"

namespace ecommerce::ui
{

    NavegaMenu::NavegaMenu()
    {
        _title = "Visualizar Produto";
        _options.push_back("1- Visualizar todos os produtos");
        _options.push_back("2- Pesquisar produto por nome");
        _options.push_back("3- Pesquisar produto por tipo");
        _options.push_back("4- Pesquisar produto por preço");
    }

    Menu *NavegaMenu::navegamenunext(unsigned option, Estoque estoque, Busca busca)
    {

        switch (option)
        {
            case 1:
            {

                std::cout << "> Lista de todos os produtos disponíveis: <" << std::endl;
                busca.busca_produtos_todos(estoque.lista_produtos());
                break;
            }

            case 2:
            {
                std::string pesquisa;
                std::cout << "> Escreva o nome do produto:" << std::endl;

                std::cin >> pesquisa;
                std::cout << "> Produto encontrado: <" << std::endl;
                busca.busca_produtos_nome(pesquisa, estoque.lista_produtos()).GetName();
                break;
            }
            
            case 3:
            {
                std::string pesquisa;
                std::cout << "> Escreva o tipo do produto:" << std::endl;

                std::cin >> pesquisa;
                std::cout << "> Lista de todos o produto do tipo escolhido: <" << std::endl;
                busca.busca_produtos_tipo(pesquisa, estoque.lista_produtos());
                break;
            }

            case 4:
            {
                std::string pesquisa;
                std::cout << "> Escreva o preço do produto:" << std::endl;

                std::cin >> pesquisa;
                float number = std::stof(pesquisa);
                std::cout << "> Lista de todos o produto do preço escolhido: <" << std::endl;
                busca.busca_produtos_preco(number, estoque.lista_produtos());
                break;
            }
        }

        return nullptr;
    }
}
