#ifndef CURA_HPP
#define CURA_HPP

#include "Item.hpp"

class Pokemon;

class Cura : public Item {
public:
    Cura() : Item("Cura") {}
    virtual ~Cura() = default;

    bool usar(Pokemon& alvo) override;
};

#endif