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
    bool isAdmin = false;

public:
    using Usuario::Usuario;
    void adicionaHistorico(std::string &nome_produto);
    bool GetIsAdmin();

      /// @brief setters
    void SetEndereco(const std::string& endereco);
    void SetNome(const std::string& nome);
    void SetTelefone(long unsigned telefone);
    void SettID(const std::string& ID);
};

#endif /* CLIENTE_H */