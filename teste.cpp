#include "classes.hpp"

int main(){
    Produto a_0001 = {
        "Caneta",
        "Escreve coisas",
        "12345",
        "Papelaria",
        1.75
    };
    a_0001.exibe_info();
    a_0001.atualiza_info();
    a_0001.exibe_info();
}