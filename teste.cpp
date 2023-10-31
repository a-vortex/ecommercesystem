#include "classes/classes.hpp"
#include <vector>

int main(){
    std::vector<Produto> produtos;
    Produto a_0001 = {
        "Caneta",
        "Escreve coisas",
        "0001",
        "Papelaria",
        1.75
    };

    Produto a_0002 = {
        "Lapis",
        "Escreve coisas",
        "0002",
        "Papelaria",
        0.50
    };

    produtos.push_back(a_0001);
    produtos.push_back(a_0002);

    Produto::exibe_info("0001", produtos);

    std::cout << std::endl;

    Produto::exibe_info("0002", produtos);

    std::cout << std::endl;

    Produto a_0003 = {
        "Borracha",
        "Apaga coisas",
        "0003",
        "Papelaria",
        1.50
    };

    Estoque estoque;
    estoque.adiciona_produto(a_0001, 10);
    estoque.adiciona_produto(a_0002, 10);
    std::cout << std::endl;
    estoque.exibe_quantidade("0001");
    estoque.exibe_quantidade("0002");
    std::cout << std::endl;
    estoque.atualiza_quantidade("0002", 15);
    estoque.exibe_quantidade("0002");
    std::cout << std::endl;
    estoque.atualiza_quantidade("0003", 15);
    estoque.exibe_quantidade("0003");
    estoque.adiciona_produto(a_0003, 20);

    //Produto::exibe_info("0001", estoque);

}