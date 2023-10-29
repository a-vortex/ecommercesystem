/*
    Author: Yuri Wada
    yuriwada@ufmg.br

    Controla informacoes sobre a quantidade
    de produtos no estoque do sistema.
*/

#pragma once

#include <iostream>
#include <string>
#include <set>
#include <iomanip>

class Estoque{
private:
    int quantidade_disponivel;
    std::set<std::pair<std::string, int>> _lista_ids;

public:
    // bool operator==(Estoque const &other) const;
    bool adiciona_produto(const std::string& id_produto, int quantidade);
    void atualiza_quantidade(const std::string& id_produto, int quantidade);
    void exibe_quantidade(const std::string& id_produto);
};