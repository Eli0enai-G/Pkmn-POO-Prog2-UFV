#ifndef POKEMON_FOGO_H
#define POKEMON_FOGO_H

#include <string>
#include "Pokemon.hpp"

class PokemonFogo : public Pokemon {
public:
    PokemonFogo(std::string nome, int idPokemon, int vida, int ataque, int defesa);
    virtual ~PokemonFogo() = default;

    int calcularDanoRecebido(int dano, std::string tipoAtacante) override;
};

#endif
