#include "estoque.hpp"

bool
Estoque::adiciona_produto(const std::string& id_produto, int quantidade)
{
    bool inserted = _lista_ids.insert(std::make_pair(id_produto, quantidade)).second;
    return inserted;
}

void
Estoque::atualiza_quantidade(const std::string& id_produto, int quantidade)
{
    for(auto it = _lista_ids.begin(); it != _lista_ids.end(); ++it)
    {
        const std::string& key = it->first;

        if(key == id_produto) 
        {
            _lista_ids.erase(it);
            std::pair<std::string, int> novaQnt(id_produto, quantidade);
            _lista_ids.insert(novaQnt);
            break;
        }
    }
    std::cout << "Produto nao encontrado: " << id_produto << std::endl;
}

void
Estoque::exibe_quantidade(const std::string& id_produto)
{
    for(auto it = _lista_ids.begin(); it != _lista_ids.end(); ++it)
    {
        const std::string& key = it->first;
        if(key == id_produto)
        {
            std::cout << std::left << std::setw(20) << "ID do Produto: " << id_produto << std::endl;
            std::cout << std::left << std::setw(20) << "Quantidade: " << it->second << std::endl;
            break;
        }
    }
    std::cout << "Produto nao encontrado: " << id_produto << std::endl;
}