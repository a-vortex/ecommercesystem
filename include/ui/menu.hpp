#pragma once

#include <string>
#include <vector>

namespace ecommerce::ui
{

    class Menu
    {
    public:
        // virtual ~Menu() = default;
        virtual Menu *next(unsigned option) = 0;
        // virtual void render() const;

    protected:
        std::string _title = "Menu de Oções";
        std::vector<std::string> _options = {"0 - Sair"};
    };

}