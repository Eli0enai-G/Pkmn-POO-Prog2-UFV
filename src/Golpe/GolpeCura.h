#ifndef GOLPE_CURA_H
#define GOLPE_CURA_H

#include "Golpe.h"

class GolpeCura : public Golpe {
private:
    int poder;
    int quantidade;

public:
    GolpeCura(std::string nome, int poder, int quantidade);
    virtual ~GolpeCura() = default;

    std::string aplicar(Pokemon& atacante, Pokemon& alvo) override;
};

#endif