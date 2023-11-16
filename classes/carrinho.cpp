#include "carrinho.hpp"

void Carrinho::adiciona_produto(std::string id_produto, unsigned quantidade){
            checar_quantidade(quantidade);
            lista_ids_produtos.push_front(std::make_pair(id_produto, quantidade));
            preço_total=GetPrice(id_produto)*quantidade;
            quantidade_produto=+quantidade;
        }

void Carrinho::remove_produto(std::string id_produto, unsigned quantidade){

}