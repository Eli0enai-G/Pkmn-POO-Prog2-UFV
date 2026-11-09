#include "PokemonPlanta.hpp"
#include "Golpe/GolpeDano.hpp"
#include "Golpe/GolpeCura.hpp"
#include <cmath>
#include <algorithm>

PokemonPlanta::PokemonPlanta(std::string nome, int idPokemon, int vida, int ataque, int defesa)
    : Pokemon(nome, idPokemon, vida, ataque, defesa, "planta") {
    definirGolpe(0, new GolpeDano("Chicote de Vinha", 12));
    definirGolpe(1, new GolpeCura("Síntese", 6, 5));
}

int PokemonPlanta::calcularDanoRecebido(int dano, std::string tipoAtacante) {
    double multiplicador = 1.0;

    if (tipoAtacante == "fogo") {
        multiplicador = 2.0;
    } else if (tipoAtacante == "agua") {
        multiplicador = 0.5;
    }

    int danoTipo = std::max(1, static_cast<int>(std::round(dano * multiplicador)));
    return danoTipo;
}