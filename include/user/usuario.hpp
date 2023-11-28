/*
    usuario.hpp
    Author: Kauan Valente
            Yuri Wada
    kauanvalentesv@gmail.com
    yuriwada@ufmg.br

    Define a classe Usuario.
*/

#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <random>

class Usuario
{
private:
    std::string _nome_usuario;
    std::string _endereco;
    unsigned _num_telefone;
    std::string _id_usuario;
    std::vector<std::string> historicopesquisa;

public:

    /// @brief Construtor padrao
    /// Cria ID unico para cada usuario
    Usuario(std::string nome, 
            std::string endereco, 
            unsigned telefone);

    /// @brief Atualiza nome do usuário
    /// @param novo_nome Nome atualizado
    void atualiza_nomeusuario(std::string novo_nome);

    /// @brief Atualiza endereço do usuário
    /// @param novo_endereco Endereço atualizado
    void atualiza_endereco(std::string novo_endereco);

    /// @brief Atualiza telefone do usuário
    /// @param novo_telefone Número de telefone atualizado
    void atualiza_telefone(unsigned novo_telefone);

    /// @brief getters
    std::string GetNome();
    std::string GetEndereco();
    unsigned GetTelefone();
    std::string GetID();
    std::vector<std::string> GetHistorico();
};

#endif /* USUARIO_H */