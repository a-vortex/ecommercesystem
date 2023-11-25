#include "../../include/sys/pagamento.hpp"

bool 
Pagamento::realiza_pagamento(Produto produto, std::string GetPagamento, Cliente cliente)
{
    if (GetPagamento != " ")
    {
        std::cout << "Pagamento realizado com sucesso o valor de: " << produto.GetPrice() << std::endl
                  << "de acordo com a forma de pagamento:"
                  << cliente.GetPagamento() << std::endl;
        return true;
    }
    else
    {
        std::cout << "Nenhuma forma de pagamento cadastrada" << std::endl;
        return false;
    }
}

void 
Pagamento::confirma_pagamento(const std::vector<Produto> &produtos, Produto &produto, Estoque &estoque)
{
    for (const Produto &buscador : produtos)
    {
        if (buscador.GetName() == produto.GetName())
        {
            int novo_valor = estoque.GetQuantidade(produto.GetId());
            estoque.atualiza_quantidade(produto.GetId(), novo_valor - 1); // Correção: adição dos parênteses para chamar a função GetId
        }
    }
}

// std::string Pagamento::status_pagamento(int id_transacao)
// {
//     if (id_transacao == this->id_transacao && realiza_pagamento)
//     {
//         return "Pagamento confirmado.";
//     }
//     else if (id_transacao == this->id_transacao && !realiza_pagamento)
//     {
//         return "Pagamento pendente.";
//     }
//     else
//     {
//         return "ID de transação inválido.";
//     }
// }

// void Pagamento::novo_preco(const cupom &cupom)
// {
//     double desconto = cupom.obterDesconto();
//     valor_total -= valor_total * desconto; // Aplica o desconto diretamente
//     std::cout << "Novo preço aplicado com sucesso. Novo valor total: " << valor_total << std::endl;
// }
