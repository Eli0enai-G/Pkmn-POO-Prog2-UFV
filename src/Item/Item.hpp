#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Pokemon;

class Item {
private:
    std::string nome;

public:
    Item(std::string nome) : nome(nome) {}
    virtual ~Item() = default;

    std::string getNome() const { return nome; }
    virtual bool usar(Pokemon& alvo) = 0;
};

#endif