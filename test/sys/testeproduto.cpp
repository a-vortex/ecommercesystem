#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../test/doctest.hpp"
#include "../../include/sys/produto.hpp"

TEST_CASE("Teste de Produto") 
{
    SUBCASE("Construtor e Getters") 
    {
        Produto produto("Produto 1", "Descrição 1", "Tipo1", "10.0");

        CHECK(produto.GetName() == "Produto 1");
        CHECK(produto.GetDescription() == "Descrição 1");
        CHECK(produto.GetType() == "Tipo1");
        CHECK(produto.GetPrice() == "10.0");
    }

    SUBCASE("Atualiza Informações") 
    {

        std::stringstream output;
        std::streambuf* coutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(output.rdbuf());

        Produto::atualiza_info("Produto 1");

        std::cout.rdbuf(coutBuffer);

        CHECK(output.str().find("Informações atualizadas para o produto: Produto 1") != std::string::npos);
    }

    SUBCASE("Associa ID") 
    {
        Produto produto("Produto 1", "Descrição 1", "Tipo1", "10.0");

        auto idMap = produto.associaID();

        REQUIRE(idMap.size() == 1);
        CHECK(idMap[1] == "Produto 1");
    }

    SUBCASE("Exibe Informações") 
    {
        Produto produto("Produto 1", "Descrição 1", "Tipo1", "10.0");

        std::stringstream output;
        std::streambuf* coutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(output.rdbuf());

        produto.exibe_info("P001", std::vector<Produto>{produto});

        std::cout.rdbuf(coutBuffer);

        CHECK(output.str().find("Nome: Produto 1, Descrição: Descrição 1, Tipo: Tipo1, Preço: 10.0") != std::string::npos);
    }

}
