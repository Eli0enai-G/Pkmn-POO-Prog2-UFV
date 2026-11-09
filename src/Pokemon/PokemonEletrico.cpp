#include "PokemonEletrico.hpp"
#include "Golpe/GolpeDano.hpp"
#include "Golpe/GolpeCura.hpp"
#include <cmath>     
#include <algorithm> 

PokemonEletrico::PokemonEletrico(std::string nome, int idPokemon, int vida, int ataque, int defesa)
    : Pokemon(nome, idPokemon, vida, ataque, defesa, "Eletrico") {
    //inicia pkmn eletr
    definirGolpe(0, new GolpeDano("Thunder Bolt", 12));

    definirGolpe(1, new GolpeCura("Eletric Punch", 6, 5));
}

int PokemonEletrico::calcularDanoRecebido(int dano, std::string tipoAtacante) {
    double multiplicador = 1.0;
    if (tipoAtacante == "agua") {
        multiplicador = 0.5;
    }

    int danoTipo = std::max(1, static_cast<int>(std::round(dano * multiplicador)));
    return danoTipo;