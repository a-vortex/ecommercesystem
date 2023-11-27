/*
    cliente.hpp
    Author: Yuri Wada
    yuriwada@ufmg.br

    Define a classe Cliente.
    Realiza operacoes sobre as informacoes.
*/

#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <iomanip>
#include <string>
#include "usuario.hpp"

class Cliente : public Usuario
{
private:
    std::string endereco;
    std::string forma_pagamento;

public:
    Cliente();
    void atualiza_endereco(std::string novo_endereco);
    void atualiza_forma_pagameto(std::string nova_forma);
    std::string GetEndereco();
    std::string GetPagamento();
};

#endif /* CLIENTE_H */