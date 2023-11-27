#include "../../include/user/usuario.hpp"

int Usuario::contador_id;

void Usuario::atualiza_usuario(std::string novo_nome)
{
    nome_usuario = novo_nome;
}

void Usuario::atualiza_telefone(std::string novo_telefone)
{
    num_telefone = novo_telefone;
}

void Usuario::contador()
{
    id_usuario = std::to_string(contador_id);
    contador_id++;
}

bool Usuario::confirma_acesso()
{
    isAdmin = true;
    return 0;
}

std::string
Usuario::GetNome()
{
    return nome_usuario;
}

std::string
Usuario::GetNumero()
{
    return num_telefone;
}

std::string
Usuario::GetID()
{
    return id_usuario;
}

bool Usuario::GetisAdmin()
{
    return isAdmin;
}
