/*
    cliente.hpp
    Author: Yuri Wada
    yuriwada@ufmg.br

    Define a classe Cliente.
    Realiza operacoes sobre as informacoes.
*/

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <iostream>
#include <iomanip>
#include <string>
#include "usuario.hpp"

class Administrador : public Usuario
{
private:
    std::string codigo_acesso = "1124";
    std::string codigo_escrito;

public:
    Administrador();
    void isAdmin();
    std::string Get_codigo_escrito();
};

#endif /* ADMINISTRADOR_H */