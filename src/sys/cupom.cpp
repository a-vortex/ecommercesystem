#include "../../include/sys/cupom.hpp"

Cupom::Cupom(Produto& disc, float discount)
{
    /*
        Gera um ID aleatorio para o cupom
    */
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1000000, 999999999);
    unsigned cupomRandomID = dis(gen);
    id_cupom = std::to_string(cupomRandomID);

    id_produto = disc.GetId();
    preco = 0.0;
    this->discount = discount;
}

void
Cupom::altera_preco(Produto& disc)
{
    // preco = disc.GetPrice() * ((100 - discount)/100);
}