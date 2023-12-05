#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../test/doctest.hpp"
#include "../../include/sys/produto.hpp"
#include "../../include/sys/estoque.hpp"
#include "../../include/sys/pagamento.hpp"
#include "../../include/user/cliente.hpp"

TEST_CASE("Teste de Pagamento") 
{
    SUBCASE("Realiza Pagamento") 
    {
        Pagamento pagamento;
        Cliente cliente("John Doe", "john@gmail.com", "123456789");
        Estoque estoque;

        Produto produto("P001", "Produto 1", 10.0, "Tipo1");

        estoque.adiciona_produto(produto, 5);

        std::stringstream output;
        std::streambuf* coutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(output.rdbuf());

        bool pagamentoEfetuado = pagamento.realiza_pagamento(produto, "Cartao", cliente);

        std::cout.rdbuf(coutBuffer);

        CHECK(pagamentoEfetuado == true);
    }

    SUBCASE("Confirma Pagamento") {
        Pagamento pagamento;
        Cliente cliente("John Doe", "john@gmail.com", "123456789");
        Estoque estoque;

        Produto produto("P001", "Produto 1", 10.0, "Tipo1");

        estoque.adiciona_produto(produto, 5);

        pagamento.realiza_pagamento(produto, "Cartao", cliente);

        auto listaProdutos = estoque.lista_produtos();

        pagamento.confirma_pagamento(listaProdutos, produto, estoque);

        CHECK(estoque.return_quantidade("P001") == "4");
    }

}
