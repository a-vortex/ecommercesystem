#include "../../include/ui/editaprodutomenu.hpp"
#include "../../include/user/usuario.hpp"
// #include "menu.cpp"
#include "../../include/ui/navegamenu.hpp"

namespace ecommerce::ui
{

    EditaProduto::EditaProduto()
    {
        _title = "Editar Informações ou adicionar novo produto";
        _options.push_back("1- Adiciona produto");
        _options.push_back("2- Encerrar sistema");
    }

    Menu *EditaProduto::nextEditaProduto(unsigned option)
    {
        Busca busca;
        NavegaMenu navega;
        Produto teste4("Produto4", "Testando o produto 4", "12345", "Papelaria", 15.00);
        Produto teste5("Produto5", "Testando o produto 5", "12346", "Papelaria", 21.00);

        Produto teste6("Produto6", "Testando o produto 6", "12347", "qualquer", 45.00);
        Produto teste7("Produto7", "Testando o produto 7", "12348", "outroqualquer", 45.00);

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
            float preco;
            std::cout << "Informe os dados do novo produto:" << std::endl;
            std::cout << "Nome:" << std::endl;
            std::cin >> nome;
            std::cout << "descrição:" << std::endl;
            std::cin >> descricao;
            std::cout << "id_produto:" << std::endl;
            std::cin >> id_produto;
            std::cout << "tipo:" << std::endl;
            std::cin >> tipo;
            std::cout << "preço:" << std::endl;
            std::cin >> preco;
            Produto teste(nome, descricao, id_produto, tipo, preco);
        }

        break;
        case 2:
        {
            std::cout << "Qual produto deseja editar?: " << std::endl;
            navega.navegamenunext(1, "n care", glob, busca);
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
// int main()
// {
//     ecommerce::ui::EditaProduto teste;
//     ecommerce::ui::NavegaMenu navega;
//     teste.nextEditaProduto(2);
// }