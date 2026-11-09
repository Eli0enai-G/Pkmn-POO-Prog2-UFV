#include "PokemonFogo.hpp"
#include "Golpe/GolpeDano.hpp"
#include "Golpe/GolpeReducaoAtaque.hpp"
#include <cmath>
#include <algorithm>

PokemonFogo::PokemonFogo(std::string nome, int idPokemon, int vida, int ataque, int defesa)
    : Pokemon(nome, idPokemon, vida, ataque, defesa, "fogo") {
    definirGolpe(0, new GolpeDano("Lança-Chamas", 12));
    definirGolpe(1, new GolpeReducaoAtaque("Brasas", 6));
}

int PokemonFogo::calcularDanoRecebido(int dano, std::string tipoAtacante) {
    double multiplicador = 1.0;

    if (tipoAtacante == "agua") {
        multiplicador = 2.0;
    } else if (tipoAtacante == "planta") {
        multiplicador = 0.5;
    }

    int danoTipo = std::max(1, static_cast<int>(std::round(dano * multiplicador)));
    return danoTipo;
}