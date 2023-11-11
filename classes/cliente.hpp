/*
    cliente.hpp
    Author: Yuri Wada
    yuriwada@ufmg.br

    Define a classe Cliente.
    Realiza operacoes sobre as informacoes.
*/

#pragma once

#include <iostream>
#include <iomanip>
#include <string>

class Cliente{
private:

    std::string nome_usuario;
    std::string endereco;
    std::string num_telefone;
     std::string id_cliente;

public:
void atualiza_usuario( std::string novo_nome);
void atualiza_endereco( std::string novo_endereco);
void atualiza_telefone( std::string novo_telefone);
void historico_pesquisa();// finalizar junto ao Serviço de busca
void historico_carrinho(); // finalizar junto ao Serviço de busca
static  int contador_id;

void imprime(){
    std::cout<<std::endl<<id_cliente;
}
Cliente();

void contador(){
    id_cliente = std::to_string(contador_id);
    contador_id++;
}

};

