/*
    cupom.hpp
    Author: M. Clara Contarini
    mccontarinid@gmail.com

    cria cupons que modificam o valor de um produto
*/
#pragma once
#include "produto.hpp"
#include "cliente.hpp"

class cupom{
    private:    
        std::string id_produto;
        float preço;
        std::string id_cupom;
    public:
        /// @brief altera o preço do produto de acordo com o cupom 
        void altera_preço();

        /// @brief gera um cupom para ser usado no sistema
        /// @param desconto porcentagem de desconto do cupom 
        /// @param quantidade quantidade de cupons disponíveis
        void gera_novo_cupom(unsigned desconto, unsigned quantidade);
};