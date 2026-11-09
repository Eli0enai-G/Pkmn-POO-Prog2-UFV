#include "Cura.h"
#include "../Pokemon/Pokemon.h"

bool Cura::usar(Pokemon& alvo) {
    if (alvo.derrotado() || alvo.getVida() >= alvo.getVidaMaxima()) {
        return false;
    }
    return alvo.curar(20) > 0;
}