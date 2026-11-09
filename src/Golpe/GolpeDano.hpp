#ifndef GOLPE_DANO_HPP
#define GOLPE_DANO_HPP

#include "Golpe.hpp"

class GolpeDano : public Golpe {
private:
    int poder;

public:
    GolpeDano(std::string nome, int poder);
    virtual ~GolpeDano() = default;

    std::string aplicar(Pokemon& atacante, Pokemon& alvo) override;
};

#endif