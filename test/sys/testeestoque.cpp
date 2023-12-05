#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../test/doctest.hpp"
#include "../../include/sys/estoque.hpp"
#include "../../include/sys/produto.hpp"

TEST_CASE("Teste de Estoque") 
{
    SUBCASE("Adiciona e Atualiza Produto") 
    {
        Estoque estoque;

        Produto produto1("P001", "Produto 1", 10.0, "Tipo1");
        Produto produto2("P002", "Produto 2", 20.0, "Tipo2");

        REQUIRE(estoque.adiciona_produto(produto1, 5) == true);
        REQUIRE(estoque.adiciona_produto(produto2, 3) == true);

        estoque.atualiza_quantidade("P001", 2);

        CHECK(estoque.return_quantidade("P001") == "7");
    }

    SUBCASE("Exibe Quantidade") 
    {
        Estoque estoque;

        Produto produto1("P001", "Produto 1", 10.0, "Tipo1");

        estoque.adiciona_produto(produto1, 10);

        std::stringstream output;
        std::streambuf* coutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(output.rdbuf());

        estoque.exibe_quantidade("P001");

        std::cout.rdbuf(coutBuffer);

        CHECK(output.str().find("Quantidade do Produto P001: 10") != std::string::npos);
    }

    SUBCASE("Lista de Produtos") 
    {
        Estoque estoque;

        Produto produto1("P001", "Produto 1", 10.0, "Tipo1");
        Produto produto2("P002", "Produto 2", 20.0, "Tipo2");

        estoque.adiciona_produto(produto1, 5);
        estoque.adiciona_produto(produto2, 3);

        auto listaProdutos = estoque.lista_produtos();

        REQUIRE(listaProdutos.size() == 2);
        CHECK(listaProdutos[0] == produto1);
        CHECK(listaProdutos[1] == produto2);
    }

}
