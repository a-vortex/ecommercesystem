#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <iomanip>
#include <string>

class Usuario
{
private:
    std::string nome_usuario;
    std::string num_telefone;
    std::string id_usuario;
    bool isAdmin;
    bool login;

public:
    /// @brief Atualiza nome do usuário
    /// @param novo_nome Nome atualizado
    void atualiza_usuario(std::string novo_nome);

    /// @brief Atualiza endereço do usuário
    /// @param novo_endereco Endereço atualizado
    void atualiza_endereco(std::string novo_endereco);

    /// @brief Atualiza telefone do usuário
    /// @param novo_telefone Número de telefone atualizado
    void atualiza_telefone(std::string novo_telefone);

    /// @brief Atualiza forma de pagamento
    /// @param nova_forma Número de telefone atualizado
    void atualiza_forma_pagameto(std::string nova_forma);

    /// @todo finalizar junto ao Serviço de busca
    void historico_pesquisa();

    /// @brief Variável estática para poder criar ids únicos
    static int contador_id;

    /// @brief Variável estática para poder criar ids únicos
    void imprime()
    {
        std::cout << std::endl
                  << id_usuario;
    }
    /// @brief Criar id para o usuário
    void contador();

    bool confirma_acesso();
    /// @brief getters
    std::string GetNome();
    std::string GetEndereco();
    std::string GetNumero();
    std::string GetID();
    std::string GetPagamento();
    bool GetisAdmin();
};

#endif /* USUARIO_H */