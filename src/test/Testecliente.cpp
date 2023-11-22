#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "test/doctest.h"
#include "sys/header.hpp"

TEST_CASE("Testando classe Cliente")
{
    Cliente cliente;
    // atualiza_usuario testes
    cliente.atualiza_usuario("Kauan");
    CHECK(cliente.GetNome() == "Kauan");
    CHECK_FALSE(cliente.GetNome() != "Kauan");
    // atualiza_endereço testes
    cliente.atualiza_endereco("Novo");
    CHECK(cliente.GetEndereco() == "Novo");
    CHECK_FALSE(cliente.GetEndereco() != "Novo");
    // atualiza_numero testes
    cliente.atualiza_telefone("54254566");
    CHECK(cliente.GetNumero() == "54254566");
    CHECK_FALSE(cliente.GetNumero() != "54254566");
    // testa se o ID é único.
    Cliente cliente1;
    CHECK_FALSE(cliente.GetID() == cliente1.GetID());
    Cliente cliente2;
    CHECK_FALSE(cliente1.GetID() == cliente2.GetID());
}
