#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../classes/produto.cpp"

TEST_CASE("Testando classe produto")
{

    Produto teste("Produto1", "Testando o produto 1", "2154", "teste", 20.2);

    CHECK(teste.GetName() == "Produto1");
    CHECK_FALSE(teste.GetName() == "Produto1incorreto");

    CHECK(teste.GetDescription() == "Testando o produto 1");
    CHECK_FALSE(teste.GetDescription() == "Descriçaoincorreta");

    CHECK(teste.GetId() == "2154");
    CHECK_FALSE(teste.GetId() == "IDincorreto");

    CHECK(teste.GetType() == "teste");
    CHECK_FALSE(teste.GetType() == "tipoincorreto");
    float price = 20.2;
    CHECK(teste.GetPrice() == price);
    CHECK_FALSE(teste.GetPrice() == 17);
}
