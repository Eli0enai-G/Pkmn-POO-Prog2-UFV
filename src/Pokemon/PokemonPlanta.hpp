#ifndef POKEMON_PLANTA_H
#define POKEMON_PLANTA_H

#include <string>
#include "Pokemon.hpp"

class PokemonPlanta : public Pokemon {
public:
    PokemonPlanta(std::string nome, int idPokemon, int vida, int ataque, int defesa);
    virtual ~PokemonPlanta() = default;

    int calcularDanoRecebido(int dano, std::string tipoAtacante) override;
};

#endif