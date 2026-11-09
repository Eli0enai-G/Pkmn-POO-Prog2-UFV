#ifndef CURA_H
#define CURA_H

#include "Item.h"

class Cura : public Item {
public:
    Cura() = default;
    virtual ~Cura() = default;

    bool usar(Pokemon& alvo) override;
};

#endif