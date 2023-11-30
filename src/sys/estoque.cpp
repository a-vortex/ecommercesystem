#include "../../include/sys/estoque.hpp"
#include "produto.cpp"


const std::string Estoque::PATH_ESTOQUE = "../../../estoque.txt";

bool Estoque::adiciona_produto(const Produto &produto, int quantidade)
{
    std::ofstream arquivo(PATH_ESTOQUE, std::ios_base::app);
      if(arquivo.is_open())
        {
            arquivo << produto.GetName() << "-" << produto.GetId() << "-" << quantidade<< "-" << std::endl;
            arquivo.close();
            std::cout << "> Novo produto adicionado ao estoque! <" << "\n\n";
        }
         else
        {
            throw std::runtime_error("> Erro ao realizar cadastro! <");
        }
    bool inserted = _lista_ids.insert(std::make_pair(produto.GetId(), quantidade)).second;
    produtos.push_back(produto);
    return inserted;
}

void Estoque::atualiza_quantidade(const std::string &id_produto, int quantidade)
{

    bool flag = false;
    for (auto it = _lista_ids.begin(); it != _lista_ids.end(); ++it)
    {
        const std::string &key = it->first;

        if (key == id_produto)
        {
            _lista_ids.erase(it);
            std::pair<std::string, int> novaQnt(id_produto, quantidade);
            _lista_ids.insert(novaQnt);
            flag = true;

            break;
        }
    }
    if (!flag)
    {
        std::cout << "Produto nao encontrado: " << id_produto << std::endl;
    }
}

void Estoque::exibe_quantidade(const std::string &id_produto)
{
    bool flag = false;
    for (auto it = _lista_ids.begin(); it != _lista_ids.end(); ++it)
    {
        const std::string &key = it->first;
        if (key == id_produto)
        {
            std::cout << std::left << std::setw(20) << "ID do Produto: " << id_produto << std::endl;
            std::cout << std::left << std::setw(20) << "Quantidade: " << it->second << std::endl;
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        std::cout << "Produto nao encontrado: " << id_produto << std::endl;
    }
}

std::vector<Produto>
Estoque::lista_produtos()
{
    return produtos;
}

int Estoque::GetQuantidade(const std::string &id_produto)
{
    for (auto it = _lista_ids.begin(); it != _lista_ids.end(); ++it)
    {
        const std::string &key = it->first;

        if (key == id_produto)
        {
            return it->second;
            break;
        }
    }
    throw std::runtime_error("Produto nao encontrado");
}

int main(){
    Estoque test;
    Produto produto("Produto1", "Testando o produto 1", "2154", "teste", 20.2);
    (test.adiciona_produto(produto, 12));
    (test.atualiza_quantidade("2154", 14));
    (test.exibe_quantidade("2154"));

}