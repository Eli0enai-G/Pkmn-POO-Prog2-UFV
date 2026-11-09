#ifndef POKEMONELETRICO_H
#define POKEMONELETRICO_H
#include "Pokemon.h"
#include <string>

class PokemonEletrico : public Pokemon {
public:
    // Construtor conforme especificação UML
    PokemonEletrico(std::string nome, int idPokemon, int vida, int ataque, int defesa);
    
    // Destrutor virtual padrão
    virtual ~PokemonEletrico() = default;

    // Sobrescrita do método abstrato de cálculo de dano com multiplicador de tipo
    int calcularDanoRecebido(int dano, std::string tipoAtacante) override;
};

#endif