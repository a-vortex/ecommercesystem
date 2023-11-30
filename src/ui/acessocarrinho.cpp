#include "../../include/ui/acessocarrinho.hpp"
#include <iostream>

namespace ecommerce::ui
{
    CartAcess::CartAcess(){
        _title = "Carrinho De Compras";
        _options.push_back("1- Adicionar Produto");
        _options.push_back("2- Remover Produto");
        _options.push_back("3- Prosseguir com a compra");
        _options.push_back("4- Voltar ao Menu");
    }
    Menu *CartAcess::next(unsigned option)
    {
        switch (option)
        {
            case 1:
            {
                unsigned quantidade;
                std::string objeto;
                std::cout<< std::endl << "> Digite o produto e a quantidade que deseja adicionar:";

                /// @todo instanciar/buscar produto em arquivo estoque para passagem de parâmetro
                std::cin >> objeto >> quantidade;

                // Produto produto();
                // marquinhos->adiciona_produto(produto, quantidade);
                // CartAcess proximo;
                // proximo.render();
                break;
            }
            case 2:
            {
                ///@todo
                break;
            }
            case 3:
            {
                ///@todo acesso ao pagamento
                break;
            }
            case 4:
            {
                ///@todo retorna ao menu cliente
                break;
            }
        }
    return nullptr;
    }
}
