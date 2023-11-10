#pragma once

#include <iostream>
#include <string>
#include "cupom.hpp"
#include "cliente.hpp"

class Pagamento {
public:
    Pagamento(int numero_pedido, double valor_total, int quantidade_produto, std::string produtos,
              int id_transacao, cliente* id_cliente);

    void realiza_pagamento(); 
    void confirma_pagamento();
    std::string status_pagamento(int id_transacao);
    void novo_preco(const Cupom& cupom);

private:
    int numero_pedido;
    double valor_total;
    int quantidade_produto;
    std::string produtos;
    int id_transacao;
    Cliente id_cliente;
    bool pagamento_realizado;
};
