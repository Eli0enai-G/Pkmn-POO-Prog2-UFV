#include "Fortificante.hpp"
#include "../Pokemon/Pokemon.hpp"

bool Fortificante::usar(Pokemon& alvo) {
    if (alvo.derrotado()) {
        return false;
    }
    return alvo.fortalecer();
}