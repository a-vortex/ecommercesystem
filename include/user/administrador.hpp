/*
    administrador.hpp
    Author: Kauan Valente
    kauanvalentesv@gmail.com

    Define a classe Administrador.
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
    bool isAdmin = true;

public:
    using Usuario::Usuario;
    bool GetIsAdmin();
};

#endif /* ADMINISTRADOR_H */