#include "classes.hpp"
#include <vector>

int main(){
    Produto a_0001 = {
        "Caneta",
        "Escreve coisas",
        "0001",
        "Papelaria",
        1.75
    };
    a_0001.exibe_info();

    std::cout << std::endl;

    Produto a_0002 = {
        "Lapis",
        "Escreve coisas",
        "0002",
        "Papelaria",
        0.50
    };
    a_0002.exibe_info();

    std::cout << std::endl;

    Estoque estoque;
    estoque.adiciona_produto("0001", 10);
    estoque.adiciona_produto("0002", 10);
    estoque.exibe_quantidade("0001");
    estoque.exibe_quantidade("0002");
    estoque.atualiza_quantidade("0002", 15);
    estoque.exibe_quantidade("0002");
    estoque.atualiza_quantidade("0003", 15);
    estoque.exibe_quantidade("0003");

}