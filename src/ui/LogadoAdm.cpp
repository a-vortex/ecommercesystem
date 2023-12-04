#include "../../include/ui/LogadoAdm.hpp"
#include "../../include/user/usuario.hpp"
#include "../../include/ui/menu.hpp"
#include "../../include/ui/navegamenu.hpp"

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
        Produto teste4("Produto4", "Testando o produto 4", "12345", "Papelaria", "15.00");
        Produto teste5("Produto5", "Testando o produto 5", "12346", "Papelaria", "21.00");

        Produto teste6("Produto6", "Testando o produto 6", "12347", "qualquer", "45.00");
        Produto teste7("Produto7", "Testando o produto 7", "12348", "outroqualquer", "45.00");

        glob.adiciona_produto(teste4, 2);
        glob.adiciona_produto(teste5, 2);
        glob.adiciona_produto(teste6, 2);
        glob.adiciona_produto(teste7, 2);

        switch (option)
        {
        case 1:
        {
            std::string nome;
            std::string descricao;
            std::string id_produto;
            std::string tipo;
            std::string preco;
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
            Produto teste(nome, descricao, id_produto, tipo, preco);
            break;
        }

        case 2:
        {
            std::cout << ">Qual produto deseja editar?: " << std::endl;
            navega.navegamenunext(1, glob, busca);
            std::string nome;
            std::cin >> nome;
            teste4.atualiza_info(glob.lista_produtos(), nome);
            break;
        }
        case 3:
        {
            std::cout << "Qual produto deseja editar? " << std::endl;
            navega.navegamenunext(1, glob, busca);
            int quantidade;
            std::string ID;
            std::cout << "Escreva o ID correspondente: " << std::endl;
            std::cin >> ID;
            std::cout << "Escreva a nova quantidade " << std::endl;
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
        }
            {

                break;
            default:
                break;
            }

            return nullptr;
        }
        return nullptr;
    }

}