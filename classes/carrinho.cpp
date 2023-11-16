#include "carrinho.hpp"

Carrinho::Carrinho()
{
    preço_total = 0;
    quantidade_produto = 0;
}

void
Carrinho::adiciona_produto(Produto produto, unsigned quantidade)
{
    //checar_quantidade(quantidade);
    lista_ids_produtos.push_front(std::make_pair(produto, quantidade));
    preço_total = produto.GetPrice()*quantidade;
    quantidade_produto += quantidade;
}

// void Carrinho::remove_produto(std::string id_produto, unsigned quantidade){

// }