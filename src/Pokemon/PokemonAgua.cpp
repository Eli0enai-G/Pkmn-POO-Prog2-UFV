#include "PokemonAgua.hpp"
#include "Golpe/GolpeDano.hpp"
#include "Golpe/GolpeCura.hpp"
#include <cmath>     
#include <algorithm> 

PokemonAgua::PokemonAgua(std::string nome, int idPokemon, int vida, int ataque, int defesa)
    : Pokemon(nome, idPokemon, vida, ataque, defesa, "agua") {
    
    
    definirGolpe(0, new GolpeDano("Pistola de Água", 12));

    definirGolpe(1, new GolpeCura("Water Bubble", 6, 5));   
}

int PokemonAgua::calcularDanoRecebido(int dano, std::string tipoAtacante) {
    double multiplicador = 1.0;
    if (tipoAtacante == "fogo") {
        multiplicador = 0.5;
    } else if (tipoAtacante == "eletrico" || tipoAtacante == "planta") {
        multiplicador = 2.0;
    }

    int danoTipo = std::max(1, static_cast<int>(std::round(dano * multiplicador)));
    return danoTipo;
}