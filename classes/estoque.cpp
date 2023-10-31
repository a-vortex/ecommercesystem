#include "estoque.hpp"

bool
Estoque::adiciona_produto(const Produto& produto, int quantidade)
{
    bool inserted = _lista_ids.insert(std::make_pair(produto.GetId(), quantidade)).second;
    produtos.push_back(produto);
    return inserted;
}

void
Estoque::atualiza_quantidade(const std::string& id_produto, int quantidade)
{
    int flag = 0;
    for(auto it = _lista_ids.begin(); it != _lista_ids.end(); ++it)
    {
        const std::string& key = it->first;

        if(key == id_produto) 
        {
            _lista_ids.erase(it);
            std::pair<std::string, int> novaQnt(id_produto, quantidade);
            _lista_ids.insert(novaQnt);
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        std::cout << "Produto nao encontrado: " << id_produto << std::endl;
    }
}

void
Estoque::exibe_quantidade(const std::string& id_produto)
{
    int flag = 0;
    for(auto it = _lista_ids.begin(); it != _lista_ids.end(); ++it)
    {
        const std::string& key = it->first;
        if(key == id_produto)
        {
            std::cout << std::left << std::setw(20) << "ID do Produto: " << id_produto << std::endl;
            std::cout << std::left << std::setw(20) << "Quantidade: " << it->second << std::endl;
            flag = 1;
            break;
        }
    }
    if(flag == 0 )
    {
        std::cout << "Produto nao encontrado: " << id_produto << std::endl;
    }
}