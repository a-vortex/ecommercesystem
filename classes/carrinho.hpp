/*
    carrinho.hpp
    Author: M. Clara Contarini
    mccontarinid@gmail.com

    Cria uma lista com as compras do cliente
*/
#include "produto.hpp"
#include "estoque.hpp"
#include "cliente.hpp"

class carrinho
{
private:
    std::string lista_ids_produtos;
    float preço_produto;
    unsigned quantidade_produto;
    std::string id_cliente;

public:
    /// @brief adiciona um produto ao carrinho
    /// @param id_produto produto a ser adicionado
    /// @param quantidade quantidade do produto a ser adicionada
    void adiciona_produto(std::string id_produto, int quantidade);

    /// @brief remove um produto do carrinho
    /// @param id_produto produto a ser removido
    /// @param quantidade quantidade do produto a ser removida
    void remove_produto(std::string id_produto, int quantidade);

    /// @brief
    void fecha_carrinho();

    /// @brief
    void edita_carrinho();
};