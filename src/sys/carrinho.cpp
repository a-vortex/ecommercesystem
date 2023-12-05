#include "../../include/sys/carrinho.hpp"

const std::string Carrinho::PATH_CARRINHO = "carrinho.txt";

Carrinho::Carrinho()
{
    preco_total = 0;
    quantidade_produto = 0;
}

void 
Carrinho::adiciona_produto(Produto produto, unsigned quantidade)
{
    bool existe=false;
    for (auto it = lista_ids_produtos.begin(); it != lista_ids_produtos.end(); ++it)
    {
        if (produto.GetId() == it->first.GetId())
        {
            it->second+=quantidade;
            existe=true;
            break;
        }
    }
    if (!existe)
    {
        lista_ids_produtos.push_front(std::make_pair(produto, quantidade));
    }
    preco_total += std::stof(produto.GetPrice())*quantidade;
    quantidade_produto += quantidade;
}

void 
Carrinho::remove_produto(Produto produto, unsigned quantidade)
{

    for (auto it = lista_ids_produtos.begin(); it != lista_ids_produtos.end(); ++it)
    {
        if (produto.GetId() == it->first.GetId())
        {
            if (it->second<quantidade)
            {
                std::cout<< "Quantidade invalida para remocao"<< std::endl;
                break; 
            }
            else if (it->second>quantidade)
            {
                it->second-=quantidade;
            }
            else
            {
                lista_ids_produtos.erase(it);
            }
            preco_total-=std::stof(produto.GetPrice())*quantidade;
            quantidade_produto-=quantidade;
            break;
        }
    }
}

std::list<std::pair<Produto, unsigned>> 
Carrinho::GetList() const
{
    return lista_ids_produtos;
}

float 
Carrinho::GetTotalPrice() const
{
    return preco_total;
}

unsigned 
Carrinho::GetProductQuantity() const
{
    return quantidade_produto;
}
