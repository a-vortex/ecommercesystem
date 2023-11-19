#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include "../classes/classes.hpp"

TEST_CASE("Testando classe Busca")
{
    Busca pesquisa;
    Estoque geral;

    Produto teste4("Produto4", "Testando o produto 4", "12345", "Papelaria", 15.00);
    Produto teste5("Produto5", "Testando o produto 5", "12346", "Papelaria", 21.00);

    Produto teste6("Produto6", "Testando o produto 6", "12347", "qualquer", 45.00);
    Produto teste7("Produto7", "Testando o produto 7", "12348", "outroqualquer", 45.00);

    geral.adiciona_produto(teste4, 2);
    geral.adiciona_produto(teste5, 2);
    geral.adiciona_produto(teste6, 2);
    geral.adiciona_produto(teste7, 2);

    std::vector<Produto> tipos;
    tipos.push_back(teste4);
    tipos.push_back(teste5);

    std::vector<Produto> precos;
    precos.push_back(teste6);
    precos.push_back(teste7);

    std::vector<Produto> vecProd = pesquisa.busca_produtos_tipo("Papelaria", geral.lista_produtos());
    CHECK(vecProd.size() == 2);

    std::vector<Produto> vecProd1= pesquisa.busca_produtos_preco(45.00, geral.lista_produtos());
    CHECK(vecProd1.size() == 2);

    std::vector<Produto> vecProd2 = pesquisa.busca_produtos_tipo("Tipofalso", geral.lista_produtos());
    CHECK_FALSE(vecProd2.size() == 3);

    std::vector<Produto> vecProd3 = pesquisa.busca_produtos_preco(40.00, geral.lista_produtos());
    CHECK_FALSE(vecProd3.size() == 3);

    Produto testeName = pesquisa.busca_produtos_nome("Produto4", geral.lista_produtos());
    CHECK_EQ(testeName.GetName(), "Produto4");

    DOCTEST_CHECK_THROWS(pesquisa.busca_produtos_nome("Produto10", geral.lista_produtos()));
}
