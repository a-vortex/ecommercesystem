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