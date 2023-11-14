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

class Cliente
{
private:
    std::string nome_usuario;
    std::string endereco;
    std::string num_telefone;
    std::string id_cliente;

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
    /// @brief
    /// @param
    void historico_pesquisa(); // finalizar junto ao Serviço de busca
    void historico_carrinho(); // finalizar junto ao Serviço de busca
    /// @brief Variável estática para poder criar ids únicos
    static int contador_id;
    /// @brief Variável estática para poder criar ids únicos
    void imprime()
    {
        std::cout << std::endl
                  << id_cliente;
    }
    /// @brief Construtor da classe Cliente
    Cliente();
    /// @brief Criar id para o usuário
    void contador()
    {
        id_cliente = std::to_string(contador_id);
        contador_id++;
    }
};
