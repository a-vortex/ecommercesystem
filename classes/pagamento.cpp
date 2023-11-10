#include "pagamento.hpp"

Pagamento::Pagamento(int numero_pedido, double valor_total, int quantidade_produto,
                     std::string produtos, int id_transacao, id_cliente)
    : numero_pedido(numero_pedido), valor_total(valor_total),
      quantidade_produto(quantidade_produto), produtos(produtos),
      id_transacao(id_transacao), id_cliente(cliente), pagamento_realizado(false) {}

void Pagamento::realiza_pagamento() {
    std::cout << "Pagamento realizado para o pedido " << numero_pedido << "." << std::endl;
    pagamento_realizado = true;
}

void Pagamento::confirma_pagamento() {
    if (pagamento_realizado) {
        std::cout << "Pagamento confirmado para o pedido " << numero_pedido << "." << std::endl;
    } else {
        std::cout << "Pagamento não realizado para o pedido " << numero_pedido << "." << std::endl;
    }
}

std::string Pagamento::status_pagamento(int id_transacao) {
    if (id_transacao == this->id_transacao && pagamento_realizado) {
        return "Pagamento confirmado.";
    } else if (id_transacao == this->id_transacao && !pagamento_realizado) {
        return "Pagamento pendente.";
    } else {
        return "ID de transação inválido.";
    }
}

void Pagamento::novo_preco(const Cupom& cupom) {
    double desconto = cupom.obterDesconto();
    valor_total -= valor_total * desconto;  // Aplica o desconto diretamente
    std::cout << "Novo preço aplicado com sucesso. Novo valor total: " << valor_total << std::endl;
}
