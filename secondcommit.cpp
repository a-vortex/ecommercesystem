
/*
    Testing codes, failing identification
    Author: Yuri Wada
    yuriwada@ufmg.br

    Edited: M. Clara Contarini
*/

#include <iostream>
#include <vector>

int main(){

    std::vector<int> numbers;
    int x = 0;
    std::cin >> x;
    numbers.resize(x);
    for(auto i = 0; i < x; ++i) numbers[i] = 0;
    for(auto i : numbers) std::cout << numbers[i] << "\t";

    return 0;
}