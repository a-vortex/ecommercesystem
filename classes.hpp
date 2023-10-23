/* 
    First attempt to create the signatures
    Author: M. Clara Contarini
    mccontarinid@gmail.com

*/
#pragma once
#include <iostream>
#include <string>

class produto{
    private:
    std::string nome;
    std::string descricao;
    std::string id_produto;
    float preco;
    
    public:
    void exibe_info();
};
class cliente{
    private:
    std::string nome_usuario;
    std::string endereco;
    std::string num_telefone;
};