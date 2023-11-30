#include "../../include/sys/carrinho.hpp"
#include "../../include/sys/busca.hpp"
#include "../../include/sys/estoque.hpp"
#include "../../include/sys/produto.hpp"
#include "../../include/exc/excecao.hpp"
#include "../../include/ui/loginmenu.hpp"

namespace ui = ecommerce::ui;

Busca busca;
Carrinho carrinho;
Estoque estoque;
ui::LoginMenu loginmenu;


namespace ecommerce::funcoes
{

    Produto 
    busca_produtos_nome(const std::string &nome, const std::vector<Produto> &_lista_de_produtos)
    {
        try
        {
            busca.busca_produtos_nome(nome, _lista_de_produtos);
        } 
        catch(NotFound const &e)
        {
            std::cout << "ERRO: " << e.what() << std::endl;
        }
    }

    std::vector<Produto>
    busca_produtos_tipo(const std::string tipo, const std::vector<Produto> &_lista_de_produtos)
    {
        try
        {
            busca.busca_produtos_tipo(tipo, _lista_de_produtos);
        }
        catch(NotFound const &e)
        {
            std::cout << "ERRO: " << e.what() << std::endl;
        }
    }

    std::vector<Produto>
    busca_produtos_preco(float preco, const std::vector<Produto> &lista_de_produtos)
    {
        try
        {
            busca.busca_produtos_preco(preco, lista_de_produtos);
        }
        catch(NotFound const &e)
        {
            std::cout << "ERRO: " << e.what() << std::endl;
        }
    }

    void
    remove_produto(Produto produto, unsigned quantidade)
    {
        try
        {
            carrinho.remove_produto(produto, quantidade);
        }
        catch(InvalidInput const &e)
        {
            std::cout << "ERRO: " << e.what() << std::endl;
        }
    }

    void
    atualiza_quantidade(const std::string &id_produto, int quantidade)
    {
        try 
        {
            estoque.atualiza_quantidade(id_produto, quantidade);
        }
        catch(NotFound const &e)
        {
            std::cout << "ERRO: " << e.what() << std::endl;
        }
    }

    void
    exibe_quantidade(const std::string &id_produto)
    {
        try 
        {
            estoque.exibe_quantidade(id_produto);
        }
        catch(NotFound const &e)
        {
            std::cout << "ERRO: " << e.what() << std::endl;
        }
    }

    int
    GetQuantidade(const std::string &id_produto)
    {
        try 
        {
            estoque.GetQuantidade(id_produto);
        }
        catch(NotFound const &e)
        {
            std::cout << "ERRO: " << e.what() << std::endl;
        }
    }

    void
    cadastrarCliente(const std::string& email, const std::string& senha)
    {
        try
        {
            loginmenu.cadastrarCliente(email, senha);
        }
        catch(ErrorFile const &e)
        {
            std::cout << "ERRO: " << e.what() << std::endl;
        }
    }

    void
    cadastrarAdmin(const std::string& email, const std::string& senha)
    {
        try
        {
            loginmenu.cadastrarAdmin(email, senha);
        }
        catch(ErrorFile const &e)
        {
            std::cout << "ERRO: " << e.what() << std::endl;
        }
    }

    

}