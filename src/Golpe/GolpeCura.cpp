#include "GolpeCura.hpp"
#include "Pokemon/Pokemon.hpp"

GolpeCura::GolpeCura(std::string nome, int poder, int quantidade)
    : Golpe(nome), poder(poder), quantidade(quantidade) {}

std::string GolpeCura::aplicar(Pokemon& atacante, Pokemon& alvo) {
    int dano = calcularDano(atacante, alvo, poder);
    int vidaPerdida = alvo.perderVida(dano);
    int vidaRecuperada = atacante.curar(quantidade);
    return atacante.getNome() + " usou " + getNome() + ", causou " + std::to_string(vidaPerdida) + " de dano e recuperou " + std::to_string(vidaRecuperada) + " de vida!";
}