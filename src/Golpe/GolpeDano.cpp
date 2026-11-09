#include "GolpeDano.hpp"
#include "Pokemon/Pokemon.hpp"

GolpeDano::GolpeDano(std::string nome, int poder)
    : Golpe(nome), poder(poder) {}

std::string GolpeDano::aplicar(Pokemon& atacante, Pokemon& alvo) {
    int dano = calcularDano(atacante, alvo, poder);
    int vidaPerdida = alvo.perderVida(dano);
    return atacante.getNome() + " usou " + getNome() + " e causou " + std::to_string(vidaPerdida) + " de dano!";
}