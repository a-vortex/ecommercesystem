#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"
#include "sys/header.hpp"

TEST_CASE("Testando classe estoque")
{
    Produto produto("Produto1", "Testando o produto 1", "2154", "teste", 20.2);
    Produto produto1("Produto2", "Testando o produto 1", "2sd3d", "teste", 25.2);
    Estoque estoque;
    estoque.adiciona_produto(produto, 3);
    estoque.adiciona_produto(produto1, 2);
    Pagamento pagamento;
    Cliente cliente;
    if (pagamento.realiza_pagamento(produto, cliente.GetPagamento(), cliente) == true)
    {
        pagamento.confirma_pagamento(estoque.lista_produtos(), produto, estoque);
    }

    CHECK(estoque.GetQuantidade(produto.GetId()) == 2);
}
