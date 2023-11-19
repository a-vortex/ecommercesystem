#include <iostream>
#include <string>
#include "cliente.hpp"
#include "cupom.hpp"

/**
 * @brief Classe pagamento: Gerencia informações relacionadas ao pagamento de um pedido.
 * 
 * Author: Brenda Belizário
 * Email: brendaboliveira@ufmg.br
 */
class pagamento {
public:
    /**
     * @brief Construtor da classe pagamento.
     * 
     * @param numero_pedido Número identificador do pedido.
     * @param valor_total Valor total da transação.
     * @param quantidade_produto Quantidade de produtos no pedido.
     * @param produtos Descrição dos produtos no pedido.
     * @param id_transacao Identificador único da transação.
     * @param id_cliente Ponteiro para o objeto Cliente associado à transação.
     */
    pagamento(int numero_pedido, double valor_total, int quantidade_produto, std::string produtos,
              int id_transacao, Cliente *id_cliente);

    /**
     * @brief Simula o processo de realização do pagamento.
     */
    void realiza_pagamento();

    /**
     * @brief Confirma o pagamento, alterando o status interno.
     */
    void confirma_pagamento();

    /**
     * @brief Atualiza o valor total com base em um objeto Cupom.
     * 
     * @param cupom Objeto Cupom contendo as informações do desconto.
     */
    void novo_preco(const cupom &cupom);

    /**
     * @brief Obtém o status do pagamento com base no identificador de transação.
     * 
     * @param id_transacao Identificador único da transação.
     * @return Status atual do pagamento.
     */
    std::string status_pagamento(int id_transacao);

private:
    int numero_pedido; 
    double valor_total; 
    int quantidade_produto; 
    std::string produtos; 
    int id_transacao;
    Cliente *id_cliente;
};