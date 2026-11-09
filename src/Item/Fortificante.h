#ifndef FORTIFICANTE_H
#define FORTIFICANTE_H

#include "Item.h"

class Fortificante : public Item {
public:
    Fortificante() = default;
    virtual ~Fortificante() = default;

    bool usar(Pokemon& alvo) override;
};

#endif