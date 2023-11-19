#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include "../classes/estoque.hpp"
#include "../classes/busca.hpp"

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

    std::vector<Produto> teste = pesquisa.busca_produtos_tipo("Papelaria", geral.lista_produtos());
    for (const Produto &buscador : teste)
    {
        std::cout << "Nome: " << buscador.GetName() << std::endl;
    }
}
