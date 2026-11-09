#include "Cura.hpp"
#include "../Pokemon/Pokemon.hpp"

bool Cura::usar(Pokemon& alvo) {
    if (alvo.derrotado() || alvo.getVida() >= alvo.getVidaMaxima()) {
        return false;
    }
    return alvo.curar(20) > 0;
}