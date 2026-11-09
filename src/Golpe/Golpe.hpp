#ifndef GOLPE_HPP
#define GOLPE_HPP

#include <string>

class Pokemon;

class Golpe {
private:
    std::string nome;

protected:
    int calcularDano(Pokemon& atacante, Pokemon& alvo, int poder);

public:
    Golpe(std::string nome);
    virtual ~Golpe() = default;

    std::string getNome();
    virtual std::string aplicar(Pokemon& atacante, Pokemon& alvo) = 0;
};

#endif