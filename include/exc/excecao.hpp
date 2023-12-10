/*
    excecao.hpp
    Author: M. Clara Contarini
                Júlia Raposo Ferreira
    mccontarinid@gmail.com
    juliarferreira00@gmail.com
    
    Exceções do sistema
*/

#ifndef EXCECAO_H
#define EXCECAO_H

#include <iostream>
#include <string>
#include <stdexcept>

class NotFound : public std::exception
{
    public:
    char const *what() const noexcept override;
};

class AlreadyExists : public std::exception
{
    public:
    char const *what() const noexcept override;
};

class InvalidInput : public std::exception
{
    public:
    char const *what() const noexcept override;
};

class NoAvailablePay : public std::exception
{
    public:
    char const *what() const noexcept override;
};

class ErrorFile : public std::exception
{
    public:
    char const *what() const noexcept override;
};

#endif /* EXCECAO_H */