#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../test/doctest.hpp"
#include "../../include/sys/busca.hpp"
#include "../../include/sys/estoque.hpp"

TEST_CASE("Teste de Busca")
{
    SUBCASE("Exibe Todos os Produtos") 
    {

        std::stringstream output;
        std::streambuf* coutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(output.rdbuf());

        Busca::exibe_produtos();

        std::cout.rdbuf(coutBuffer);

        CHECK(output.str().find("Lista de Todos os Produtos:") != std::string::npos);
    }

    SUBCASE("Exibe Produtos por Tipo") 
    {

        Estoque estoque;

        Produto produto1("P001", "Produto 1", 10.0, "Tipo1");
        Produto produto2("P002", "Produto 2", 20.0, "Tipo2");

        estoque.adiciona_produto(produto1);
        estoque.adiciona_produto(produto2);

        std::stringstream output;
        std::streambuf* coutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(output.rdbuf());

        Busca busca;
        busca.exibe_tipo("Tipo1");

        std::cout.rdbuf(coutBuffer);

        CHECK(output.str().find("Lista de Produtos do Tipo Tipo1:") != std::string::npos);
        CHECK(output.str().find("Produto 1 - Preço: 10.0") != std::string::npos);
    }

}