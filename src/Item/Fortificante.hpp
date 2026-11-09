#ifndef FORTIFICANTE_HPP
#define FORTIFICANTE_HPP

#include "Item.hpp"

class Fortificante : public Item {
public:
    Fortificante() = default;
    virtual ~Fortificante() = default;

    bool usar(Pokemon& alvo) override;
};

#endif