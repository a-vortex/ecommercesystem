#include "../../include/ui/LogadoAdm.hpp"
#include "../../include/user/usuario.hpp"
#include "../../include/ui/menu.hpp"
#include "../../include/ui/navegamenu.hpp"

Estoque glob;
namespace ecommerce::ui
{

    LogadoAdm::LogadoAdm(Administrador const &admin) : _admin(admin)
    {
        _title = "Olá, sr(a). " + _admin.GetNome();
        _options.push_back("1- Adiciona produto");
        _options.push_back("2- Editar produto");
        _options.push_back("3- Editar estoque");
        _options.push_back("4- Navegação");
    }

    Menu *LogadoAdm::nextEditaProduto(unsigned option)
    {
        Busca busca;
        NavegaMenu navega;

        switch (option)
        {
            case 1:
            {
                std::string nome;
                std::string descricao;
                std::string id_produto;
                std::string tipo;
                float preco;

                std::cout << "> Informe os dados do novo produto:" << std::endl;
                std::cout << "> Nome:" << std::endl;
                std::cin >> nome;

                std::cout << "> Descrição:" << std::endl;
                std::cin >> descricao;

                std::cout << "> ID do Produto:" << std::endl;
                std::cin >> id_produto;

                std::cout << "> Tipo:" << std::endl;
                std::cin >> tipo;

                std::cout << "> Preço:" << std::endl;
                std::cin >> preco;
                break;
            }

            case 2:
            {
                std::cout << "> Qual produto deseja editar?: " << std::endl;
                navega.navegamenunext(1, glob, busca);
                std::string nome;
                std::cin >> nome;
                break;
            }

            case 3:
            {
                std::cout << "> Qual produto deseja editar? " << std::endl;
                navega.navegamenunext(1, glob, busca);
                int quantidade;
                std::string ID;
                std::cout << "> Escreva o ID correspondente: " << std::endl;
                std::cin >> ID;
                std::cout << "> Escreva a nova quantidade " << std::endl;
                std::cin >> quantidade;
                glob.atualiza_quantidade(ID, quantidade);
                break;
            }

            case 4:
            {
                navega.render();
                int opcao;
                std::cin >> opcao;
                navega.navegamenunext(opcao, glob, busca);
                break;
            }
        
            default:
                return nullptr;

        }
        
        return nullptr;
    }

}