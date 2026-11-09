#include "GolpeReducaoAtaque.h"
#include "Pokemon/Pokemon.h"

GolpeReducaoAtaque::GolpeReducaoAtaque(std::string nome, int poder)
    : Golpe(nome), poder(poder) {}

std::string GolpeReducaoAtaque::aplicar(Pokemon& atacante, Pokemon& alvo) {
    int dano = calcularDano(atacante, alvo, poder);
    int vidaPerdida = alvo.perderVida(dano);

    if (!alvo.derrotado()) {
        alvo.reduzirAtaque(8);
        return atacante.getNome() + " usou " + getNome() + ", causou " + std::to_string(vidaPerdida) + " de dano e reduziu o ataque do adversário!";
    }

    return atacante.getNome() + " usou " + getNome() + " e causou " + std::to_string(vidaPerdida) + " de dano!";
}