#include "../../include/ui/acessocarrinho.hpp"
#include "../../include/sys/produto.hpp"

namespace ecommerce::ui
{
    CartAcess::CartAcess(Cliente const &client) : _cliente(client)
    {
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
                std::ifstream arquivo(estoque);
                if (!arquivo.is_open()){
                    ///@todo tratamento de exceção
                    std::cout<< "Erro ao verificar estoque" << std::endl;
                    return new CartAcess(_cliente);
                }

                unsigned quantidade;
                std::string nome, descricao, id, tipo, preco;

                std::cout << "> Digite o produto que deseja adicionar:" << std::endl;
                std::cin >> nome;
                std::cout << "> Digite a quantidade que deseja adicionar:" << std::endl;
                std::cin >> quantidade;

                std::string linha;
                bool produto_encontrado=false;
                while (std::getline(arquivo, linha)){
                    if (linha.find(nome) == 0){
                        std::istringstream iss(linha);
                        iss >> nome >> descricao >> id >> tipo >> preco;
                        produto_encontrado=true;
                        break;
                    }
                }
                if (!produto_encontrado) {
                    // @todo tratamento de exceção
                    std::cout << "Erro ao procurar produto" << std::endl;
                    return new CartAcess(_cliente);
                }
                Produto prod(nome, descricao, tipo, preco);
                Carrinho cart;
                cart.adiciona_produto(prod, quantidade);

                arquivo.close();
                return new CartAcess(_cliente);
            }


            case 2:
            {
                std::ifstream arquivo(carrinho);
                if (!arquivo.is_open()){
                    ///@todo tratamento de exceção
                    std::cout<< "Erro ao verificar Carrinho" << std::endl;
                    return new CartAcess(_cliente);
                }

                std::string nome, descricao, id, tipo, preco;
                std::cout<< "> Digite o produto que deseja remover:";
                std::cin>> nome;
                unsigned quantidade;
                std::cout<< "> Digite a quantidade que deseja remover:";
                std::cin>> quantidade;

                std::string linha;
                bool produto_encontrado=false;
                while (std::getline(arquivo, linha)){
                    if (linha.find(nome) == 0){
                        std::istringstream iss(linha);
                        iss >> nome >> descricao >> id >> tipo >> preco;
                        produto_encontrado=true;
                        break;
                    }
                }
                if (!produto_encontrado) {
                    // @todo tratamento de exceção
                    std::cout << "Erro ao procurar produto" << std::endl;
                    return new CartAcess(_cliente);
                }
                Produto prod(nome, descricao, tipo, preco);
                Carrinho cart;
                cart.remove_produto(prod, quantidade);

                arquivo.close();
                return new CartAcess(_cliente);
            }

            case 3:
            {
                ///@todo acesso ao pagamento
                std::cout<< "Erro: Função ainda não implementada" << std::endl;
                return nullptr;
            }

            case 4:
            {
                return new ClienteMenu(_cliente);
            }

        }
    return nullptr;
    }
}
