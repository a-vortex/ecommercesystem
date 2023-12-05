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

void
Cliente::SetName(std::string const &name)
{
    _name = name;
}

void
Cliente::SetAddr(std::string const &addr)
{
    _addr = addr;
}

void
Cliente::SetPhone(long unsigned const &phone)
{
    _phone = phone;
}