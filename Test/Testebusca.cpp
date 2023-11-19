#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../classes/estoque.hpp"
#include "../classes/busca.hpp"

TEST_CASE("Testando classe Busca")
{
    Busca pesquisa;
    Estoque geral;
    Produto teste("Produto1", "Testando o produto 1", "2154", "teste", 20.2);
    Estoque geral2;
    geral2.adiciona_produto(teste, 2);
    // geral.lista_produtos() = pesquisa.busca_produtos_nome("Produto1", geral.lista_produtos());
    Produto teste2 = geral.lista_produtos(1);
    // CHECK(geral.lista_produtos(1) == geral2.lista_produtos(1));
}
