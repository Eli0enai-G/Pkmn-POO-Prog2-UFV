#include "Golpe.h"
#include "../Pokemon/Pokemon.h"
#include <cmath>
#include <algorithm>

Golpe::Golpe(std::string nome) : nome(nome) {}

std::string Golpe::getNome() {
    return nome;
}

int Golpe::calcularDano(Pokemon& atacante, Pokemon& alvo, int poder) {
    int danoBase = std::max(1, poder + atacante.getAtaque() - alvo.getDefesa());
    
    int reducao = atacante.consumirReducaoAtaque();
    if (reducao > 0) {
        danoBase = std::max(0, danoBase - reducao);
    }

    int danoTipo = alvo.calcularDanoRecebido(danoBase, atacante.getTipo());
    double fortalecimento = atacante.consumirFortalecimento();

    int danoFinal = std::max(1, static_cast<int>(std::round(danoTipo * fortalecimento)));
    return danoFinal;
}