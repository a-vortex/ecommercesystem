#include "../../include/user/usuario.hpp"

Usuario::Usuario(std::string nome, 
                std::string endereco, 
                unsigned telefone)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1000000, 999999999);
    unsigned usuarioID = dis(gen);
    _id_usuario = std::to_string(usuarioID);

    _nome_usuario = nome;
    _endereco = endereco;
    _num_telefone = telefone;
}

void
Usuario::atualiza_nomeusuario(std::string novo_nome)
{
    _nome_usuario = novo_nome;
}

void
Usuario::atualiza_endereco(std::string novo_endereco)
{
    _endereco = novo_endereco;
}

void 
Usuario::atualiza_telefone(unsigned novo_telefone)
{
    _num_telefone = novo_telefone;
}

std::string
Usuario::GetNome()
{
    return _nome_usuario;
}

std::string
Usuario::GetEndereco()
{
    return _endereco;
}

unsigned
Usuario::GetTelefone()
{
    return _num_telefone;
}

std::string
Usuario::GetID()
{
    return _id_usuario;
}

std::vector<std::string>
Usuario::GetHistorico()
{
    return historicopesquisa;
}

bool
Usuario::GetIsAdmin()
{
    return _isAdmin;
}
