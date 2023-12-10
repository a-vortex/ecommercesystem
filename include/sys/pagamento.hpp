/*
    pagamento.hpp
    Author: Brenda Belizario
    brendaboliveira@ufmg.br

    Classe pagamento: Gerencia informações relacionadas ao pagamento de um pedido.
*/

#ifndef PAGAMENTO_H
#define PAGAMENTO_H

#include <iostream>
#include <string>
#include "produto.hpp"
#include "../user/cliente.hpp"
#include "estoque.hpp"

class Pagamento
{
public:
    /// @brief Realiza o pagamento do produto
    /// @param produto
    /// @param GetPagamento
    /// @param cliente
    /// @return
    void realiza_pagamento(Produto produto, std::string GetPagamento, Cliente cliente); // adicionar cupom ára receber depois

    /// @brief Atualiza o valor total com base em um objeto Cupom.
    /// @param  produtos Vetor de produtos.
    /// @param  produto produto comprado.
    /// @param  estoque estoque geral.
    void confirma_pagamento(const std::vector<Produto> &produtos, Produto &produto, Estoque &estoque);

    /// @todo Atualiza o valor total com base em um objeto Cupom.
    /// @param cupom Objeto Cupom contendo as informações do desconto.
    // void novo_preco(const cupom &cupom); // a concluir
};

#endif /* PAGAMENTO_H */