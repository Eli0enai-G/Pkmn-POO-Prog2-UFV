#ifndef POKEMON_AGUA_H
#define POKEMON_AGUA_H

#include <string>
#include "Pokemon/Pokemon.h" 
class PokemonAgua : public Pokemon {
public:
    
    PokemonAgua(std::string nome, int idPokemon, int vida, int ataque, int defesa);
    virtual ~PokemonAgua() = default;
    int calcularDanoRecebido(int dano, std::string tipoAtacante) override;
};

#endif