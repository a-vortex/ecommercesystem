#include "../../include/ui/LogadoAdm.hpp"
#include "../../include/user/usuario.hpp"
#include "../../include/ui/menu.hpp"
#include "../../include/ui/navegamenu.hpp"

Estoque glob;
namespace ecommerce::ui
{

    LogadoAdm::LogadoAdm() 
    {
        _title = "Olá, sr(a). ";
        //  + _admin.GetNome();
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
            std::string preco;
            int quantidade;

          
            std::cout << "Informe os dados do novo produto:" << std::endl;
            std::cout << "Nome:" << std::endl;
            std::getline(std::cin >> std::ws, nome);
          
            std::cout << "descrição:" << std::endl;
            std::getline(std::cin >> std::ws, descricao);
          
            std::cout << "id_produto:" << std::endl;
            std::getline(std::cin >> std::ws, id_produto);
          
            std::cout << "tipo:" << std::endl;
            std::getline(std::cin >> std::ws, tipo);
          
            std::cout << "preço:" << std::endl;
            std::getline(std::cin >> std::ws, preco);
            Produto produto_adiciona(nome, descricao , id_produto, tipo, preco);
            std::cout << "Quantidade disponível: ";
            std::cin >> quantidade;
            glob.adiciona_produto(produto_adiciona,quantidade );



            break;
        }

            case 2:
            {
                std::cout << "> Qual produto deseja editar?: " << std::endl;
                navega.navegamenunext(1);
                std::string nome;
                std::getline(std::cin >> std::ws, nome);
                break;
            }

            case 3:
            {
                std::cout << "> Qual produto deseja editar? " << std::endl;
                navega.navegamenunext(1);
                int quantidade;
                std::string ID;
                std::cout << "> Escreva o ID correspondente: " << std::endl;
                std::getline(std::cin >> std::ws, ID);
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
                navega.navegamenunext(opcao);
                break;
            }
                  
        
            default:
                return nullptr;

        }
           std::cout << "\n\n";
           ui::LogadoAdm adm;
           adm.render();
           unsigned option;
           std::cin >> option;
           adm.nextEditaProduto(option);
        
        return nullptr;
    }

}