#include "Fortificante.h"
#include "../Pokemon/Pokemon.h"

bool Fortificante::usar(Pokemon& alvo) {
    if (alvo.derrotado()) {
        return false;
    }
    return alvo.fortalecer();
}