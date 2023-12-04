#include "../../include/ui/navegamenu.hpp"
#include "../../include/sys/estoque.hpp"
#include "../../include/sys/produto.hpp"
#include "../../include/sys/busca.hpp"
#include "../../include/ui/menu.hpp"
Busca global;


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
                global.exibe_produtos();
                break;
            }

            case 2:
            {
                std::string pesquisa;
                std::cout << "> Escreva o nome do produto:" << std::endl;

                std::cin >> pesquisa;
                std::cout << "> Produto encontrado: <" << std::endl;
                global.exibe_nome(pesquisa);
                break;
            }
            
            case 3:
            {
                std::string pesquisa;
                std::cout << "> Escreva o tipo do produto:" << std::endl;

                std::getline(std::cin >> std::ws, pesquisa);
                std::cout << "> Lista de todos o produto do tipo escolhido: <" << std::endl;
                global.exibe_tipo(pesquisa);
                break;
            }

            case 4:
            {
                std::string pesquisa;
                std::cout << "> Escreva o preço do produto:" << std::endl;

                std::getline(std::cin >> std::ws, pesquisa);
                float number = std::stof(pesquisa);
                std::cout << "> Lista de todos o produto do preço escolhido: <" << std::endl;
                global.exibe_preco(number);
                break;
            }
        }

        return nullptr;
    }
}
