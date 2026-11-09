#ifndef FORTIFICANTE_HPP
#define FORTIFICANTE_HPP

#include "Item.hpp"

class Pokemon;

class Fortificante : public Item {
public:
    Fortificante() : Item("Fortificante") {}
    virtual ~Fortificante() = default;

    bool usar(Pokemon& alvo) override;
};

#endif