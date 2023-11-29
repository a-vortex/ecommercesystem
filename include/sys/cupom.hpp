/*
    cupom.hpp
    Author: M. Clara Contarini
    mccontarinid@gmail.com

    cria cupons que modificam o valor de um produto
*/

#ifndef CUPOM_H
#define CUPOM_H

#include <random>
#include "produto.hpp"

class Cupom
{
private:
    std::string id_produto;
    std::string id_cupom;
    float preco;
    float discount;

public:
    /// @brief Construtor padrao
    Cupom(Produto &disc, float discount);

    /// @brief altera o preço do produto de acordo com o cupom
    void altera_preco(Produto &disc);

    /// @todo gera um cupom para ser usado no sistema
    // /// @param desconto porcentagem de desconto do cupom
    // /// @param quantidade quantidade de cupons disponíveis
    // void gera_novo_cupom(unsigned desconto, unsigned quantidade);
};

#endif /* CUPOM_H */