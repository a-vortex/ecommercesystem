#include "../../include/ui/editaprodutomenu.hpp"
#include "../sys/produto.cpp"
#include "../sys/estoque.cpp"
#include "../user/usuario.cpp"
// #include "menu.cpp"
#include "navegamenu.cpp"

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
        }
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
    ecommerce::ui::EditaProduto teste;
    teste.nextEditaProduto(1);
}