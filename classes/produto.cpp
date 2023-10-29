#include "produto.hpp"

Produto::Produto(const std::string& nome,
                 const std::string& descricao,
                 const std::string& id_produto,
                 const std::string& tipo,
                 float preco){
    this->nome = nome;
    this->descricao = descricao;
    this->id_produto = id_produto;
    this->tipo = tipo;
    this->preco = preco;
    
    std::map<long int, std::string> produto;
    long int id = std::stol(id_produto);
    produto.insert(std::make_pair(id, nome));
}

void
Produto::exibe_info(){
    std::cout << std::left << std::setw(20) << "Nome: " << nome << std::endl;
    std::cout << std::left << std::setw(20) << "Descricao: " << descricao << std::endl;
    std::cout << std::left << std::setw(20) << "ID do Produto: " << id_produto << std::endl;
    std::cout << std::left << std::setw(20) << "Tipo: " << tipo << std::endl;
    std::cout << std::left << std::setw(20) << "Preco: " << preco << std::endl;
}

void
Produto::atualiza_info(){
    std::cout << "Qual tipo de informacao quer alterar? Escolha uma opcao (1 a 4)" << std::endl;
    std::cout << "Para finalizar a operacao, digite 0" << std::endl;
    std::cout << "1. Nome" << std::endl;
    std::cout << "2. Descricao" << std::endl;
    std::cout << "3. Tipo" << std::endl;
    std::cout << "4. Preco" << std::endl;
    unsigned escolha = 5;
    while(std::cin >> escolha && escolha != 0){
        switch(escolha){
            case 1:
                std::cout << "Insira o novo nome: " << std::endl;
                std::cin >> nome;
                break;
            case 2:
                std::cout << "Insira a nova descricao: " << std::endl;
                std::cin >> descricao;
                break;
            case 3:
                std::cout << "Insira o novo tipo: " << std::endl;
                std::cin >> tipo;
                break;
            case 4:
                std::cout << "Insira o novo preco: " << std::endl;
                std::cin >> preco;
                break;
        }
        std::cout << "Escolha nova opcao (1 a 4)" << std::endl;
        std::cout << "Para finalizar a operacao, digite 0" << std::endl;
    }
}
