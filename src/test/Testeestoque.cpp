#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "test/doctest.h"
#include "sys/header.hpp"

TEST_CASE("Testando classe estoque")
{
    Estoque test;
    Produto produto("Produto1", "Testando o produto 1", "2154", "teste", 20.2);
    CHECK(test.adiciona_produto(produto, 12));
    (test.atualiza_quantidade("2154", 14));
    (test.exibe_quantidade("2154"));
}