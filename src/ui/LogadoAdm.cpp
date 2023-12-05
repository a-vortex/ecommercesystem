#include "../../include/ui/LogadoAdm.hpp"
#include "../../include/user/usuario.hpp"
#include "../../include/ui/menu.hpp"
#include "../../include/ui/navegamenu.hpp"

namespace ecommerce::ui
{

    LogadoAdm::LogadoAdm(Administrador const &admin) : _admin(admin)
    {
        _title = "Olá, sr(a) " + _admin.GetNome();
        _options.push_back("1- Adiciona produto");
        _options.push_back("2- Editar produto");
        _options.push_back("3- Editar estoque");
        _options.push_back("4- Navegação");
        _options.push_back("5- Sair");
    }

    Menu *LogadoAdm::nextEditaProduto(unsigned option)
    {
        switch (option)
        {
            case 1:
            {
                std::string nome;
                std::string descricao;
                std::string tipo;
                std::string preco;
                int quantidade;

                std::cout << "> Informe os dados do novo produto:" << std::endl;
                std::cout << "> Nome:" << std::endl;
                std::getline(std::cin >> std::ws, nome);
          
                std::cout << "> Descrição:" << std::endl;
                std::getline(std::cin >> std::ws, descricao);
          
                std::cout << "> Tipo:" << std::endl;
                std::getline(std::cin >> std::ws, tipo);
          
                std::cout << "> Preço:" << std::endl;
                std::getline(std::cin >> std::ws, preco);

                Produto produto_adiciona(nome, descricao, tipo, preco);

                std::cout << "> Quantidade disponível: ";
                std::cin >> quantidade;

                glob.adiciona_produto(produto_adiciona, quantidade);

                return nullptr;
            }

            case 2:
            {
                std::cout << "> Qual produto deseja editar?: " << std::endl;
                Busca::exibe_produtos();

                std::string nome;
                std::getline(std::cin >> std::ws, nome);

                Produto::atualiza_info(nome);
                
                return nullptr;
            }

            case 3:
            {
                std::cout << "> Qual produto deseja adicionar? " << std::endl;
                Busca::exibe_produtos();
            
                int quantidade;
                std::string ID;
                std::cout << "> Escreva o ID correspondente: " << std::endl;
                std::getline(std::cin >> std::ws, ID);

                std::cout << "> Escreva a nova quantidade " << std::endl;
                std::cin >> quantidade;

                glob.atualiza_quantidade(ID, quantidade);

                return nullptr;
            }

            case 4:
            {
                return new NavegaMenu;
            }
            
            case 5:
            {
                return nullptr;
            }

            default:
            {
                std::cout << "> Opção inválida! <" << std::endl;
                std::cout << "> Insira novamente: " << std::endl;
                return new LogadoAdm(_admin);
            }

        }
    }

}