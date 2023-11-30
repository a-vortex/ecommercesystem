#include "../../include/exc/excecao.hpp"

char const *NotFound::what() const noexcept 
{
    return "Produto não encontrado.";
}

char const *AlreadyExists::what() const noexcept
{
    return "Identificador já existente.";
}

char const *InvalidInput::what() const noexcept
{
    return "Entrada inválida.";
};

char const *NoAvailablePay::what() const noexcept
{
    return "Nenhum método de pagamento cadastrado.";
}

char const *ErrorFile::what() const noexcept
{
    return "Não foi possível abrir o arquivo.";
}
