#ifndef PAGAMENTO_H
#define PAGAMENTO_H

#include <iostream>
#include <string>
#include "produto.hpp"
#include "cliente.hpp"
#include "estoque.hpp"

/**
 * @brief Classe pagamento: Gerencia informações relacionadas ao pagamento de um pedido.
 *
 * Author: Brenda Belizário
 * Email: brendaboliveira@ufmg.br
 */

class Pagamento
{
public:
    /// @brief Confirma o pagamento, alterando o status interno.
    bool realiza_pagamento(Produto produto, std::string GetPagamento, Cliente cliente); // adicionar cupom ára receber depois

    /// @brief Atualiza o valor total com base em um objeto Cupom.
    /// @param  produtos Vetor de produtos.
    /// @param  produto produto comprado.
    /// @param  estoque estoque geral.
    void confirma_pagamento(const std::vector<Produto> &produtos, Produto &produto, Estoque &estoque);

    /// @brief Atualiza o valor total com base em um objeto Cupom.
    ///@param cupom Objeto Cupom contendo as informações do desconto.
    // void novo_preco(const cupom &cupom); // a concluir

private:
};

#endif /* PAGAMENTO_H */