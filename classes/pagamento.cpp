#include "pagamento.hpp"

pagamento::pagamento(int numero_pedido, double valor_total, int quantidade_produto,
                     std::string produtos, int id_transacao, id_cliente)
    : numero_pedido(numero_pedido), valor_total(valor_total),
      quantidade_produto(quantidade_produto), produtos(produtos),
      id_transacao(id_transacao), id_cliente(cliente), pagamento_realizado(false) {}

void pagamento::realiza_pagamento() {
    std::cout << "Pagamento realizado para o pedido " << numero_pedido << "." << std::endl;
    realiza_pagamento = true;
}

void pagamento::confirma_pagamento() {
    if (realiza_pagamento) {
        std::cout << "Pagamento confirmado para o pedido " << numero_pedido << "." << std::endl;
    } else {
        std::cout << "Pagamento não realizado para o pedido " << numero_pedido << "." << std::endl;
    }
}

std::string pagamento::status_pagamento(int id_transacao) {
    if (id_transacao == this->id_transacao && realiza_pagamento) {
        return "Pagamento confirmado.";
    } else if (id_transacao == this->id_transacao && !realiza_pagamento) {
        return "Pagamento pendente.";
    } else {
        return "ID de transação inválido.";
    }
}

void pagamento::novo_preco(const cupom& cupom) {
    double desconto = cupom.obterDesconto();
    valor_total -= valor_total * desconto; // Aplica o desconto diretamente
    std::cout << "Novo preço aplicado com sucesso. Novo valor total: " << valor_total << std::endl;
}
