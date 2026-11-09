#ifndef CURA_HPP
#define CURA_HPP
#include "Item.hpp"

class Cura : public Item {
public:
    Cura() = default;
    virtual ~Cura() = default;

    bool usar(Pokemon& alvo) override;
};

#endif