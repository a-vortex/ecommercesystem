/*
    carrinho.hpp
    Author: M. Clara Contarini
    mccontarinid@gmail.com

    Cria uma lista com as compras do cliente
*/
#pragma once
#include <iostream>
#include <list>
#include <string>
#include "produto.hpp"
class carrinho{
    private:
        std::list<std::pair<std::string ,int>> lista_ids_produtos;
        float preço_total;
        unsigned quantidade_produto;
        std::string id_cliente;
    public:
        /// @brief adiciona um produto ao carrinho
        /// @param id_produto produto a ser adicionado
        /// @param quantidade quantidade do produto a ser adicionada
        void adiciona_produto(std::string id_produto, int quantidade);
        
        /// @brief remove um produto do carrinho
        /// @param id_produto produto a ser removido
        /// @param quantidade quantidade do produto a ser removida
        void remove_produto(std::string id_produto, int quantidade);
        
        /// @brief 
        void fecha_carrinho();
        
        /// @brief  
        void edita_carrinho();

};