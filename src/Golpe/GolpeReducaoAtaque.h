#ifndef GOLPE_REDUCAO_ATAQUE_H
#define GOLPE_REDUCAO_ATAQUE_H

#include "Golpe.h"

class GolpeReducaoAtaque : public Golpe {
private:
    int poder;

public:
    GolpeReducaoAtaque(std::string nome, int poder);
    virtual ~GolpeReducaoAtaque() = default;

    std::string aplicar(Pokemon& atacante, Pokemon& alvo) override;
};

#endif