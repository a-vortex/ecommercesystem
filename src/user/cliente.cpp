#include "../../include/user/cliente.hpp"

void
Cliente::adicionaHistorico(std::string &nome_produto)
{
    historicopesquisa.push_back(nome_produto);
}

bool
Cliente::GetIsAdmin()
{
    return isAdmin;
}

void Cliente::SetEndereco(const std::string& endereco) {
    _endereco = endereco;
}

void Cliente::SetNome(const std::string& nome) {
    _nome_usuario = nome;
}

void Cliente::SetTelefone(long unsigned telefone) {
    _num_telefone = telefone;
}

void Cliente::SettID(const std::string& ID) {
    _id_usuario = ID;
}