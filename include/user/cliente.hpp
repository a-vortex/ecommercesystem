/*
    cliente.hpp
    Author: Kauan Valente
            Yuri Wada
    kauanvalentesv@gmail.com
    yuriwada@ufmg.br

    Define a classe Cliente.
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
    std::vector<std::string> historicopesquisa;
    std::string _name;
    std::string _addr;
    long unsigned _phone;
    bool isAdmin = false;

public:
    using Usuario::Usuario;
    void adicionaHistorico(std::string &nome_produto);
    bool GetIsAdmin();
    
    void SetName(std::string const &name);
    void SetAddr(std::string const &addr);
    void SetPhone(long unsigned const &phone);
};

#endif /* CLIENTE_H */