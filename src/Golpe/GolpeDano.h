#ifndef GOLPE_DANO_H
#define GOLPE_DANO_H

#include "Golpe.h"

class GolpeDano : public Golpe {
private:
    int poder;

public:
    GolpeDano(std::string nome, int poder);
    virtual ~GolpeDano() = default;

    std::string aplicar(Pokemon& atacante, Pokemon& alvo) override;
};

#endif