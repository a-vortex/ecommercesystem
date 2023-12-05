#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../test/doctest.hpp"
#include "../../include/sys/carrinho.hpp"

TEST_CASE("Teste de Carrinho")
{
    SUBCASE("Adiciona e Remove Produto")
    {
        Carrinho carrinho;

        Produto produto1("P001", "Produto 1", 10.0);
        Produto produto2("P002", "Produto 2", 20.0);

        carrinho.adiciona_produto(produto1, 3);
        carrinho.adiciona_produto(produto2, 2);

        REQUIRE(carrinho.GetProductQuantity() == 5);

        carrinho.remove_produto(produto1, 1);

        REQUIRE(carrinho.GetProductQuantity() == 4);
    }

    SUBCASE("Verifica Preço Total")
    {
        Carrinho carrinho;

        Produto produto1("P001", "Produto 1", 10.0);
        Produto produto2("P002", "Produto 2", 20.0);

        carrinho.adiciona_produto(produto1, 3);
        carrinho.adiciona_produto(produto2, 2);

        REQUIRE(carrinho.GetTotalPrice() == 70.0);
    }

    SUBCASE("Verifica Lista de Produtos")
    {
        Carrinho carrinho;

        Produto produto1("P001", "Produto 1", 10.0);
        Produto produto2("P002", "Produto 2", 20.0);

        carrinho.adiciona_produto(produto1, 3);
        carrinho.adiciona_produto(produto2, 2);

        auto listaProdutos = carrinho.GetList();
        REQUIRE(listaProdutos.size() == 2);

    }
}
