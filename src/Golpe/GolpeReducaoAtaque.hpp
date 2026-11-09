#ifndef GOLPE_REDUCAO_ATAQUE_HPP
#define GOLPE_REDUCAO_ATAQUE_HPP

#include "Golpe.hpp"

class GolpeReducaoAtaque : public Golpe {
private:
    int poder;

public:
    GolpeReducaoAtaque(std::string nome, int poder);
    virtual ~GolpeReducaoAtaque() = default;

    std::string aplicar(Pokemon& atacante, Pokemon& alvo) override;
};

#endif