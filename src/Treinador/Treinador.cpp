#include "Treinador.hpp"
#include <fstream>
#include <iostream>

// Add os trem de include para os pokemons e itens
#include "Pokemon/PokemonFogo.hpp"
#include "Pokemon/PokemonAgua.hpp"
#include "Pokemon/PokemonPlanta.hpp"
#include "Pokemon/PokemonEletrico.hpp"
#include "Item/Cura.hpp"
#include "Item/Fortificante.hpp"
// O treinador vai ler tudo para controlar as partidas
// tomar cuidado pra nn criar nada NADA


Treinador::Treinador(std::string nome, int pokemons[3]) {
    this -> nome = nome;
    this -> ativo = 0;

    for (int indice = 0; indice < 3; indice++) {
        equipe[indice] = nullptr;
    }

    std::ifstream arquivo("../pokemons.txt");

    int id, vida, ataque, defesa;
    std::string tipo, nomePokemon;
    while (arquivo >> id >> tipo >> nomePokemon >> vida >> ataque >> defesa) {
        for (int indice = 0; indice < 3; indice++) {
            if (pokemons[indice] != id || equipe[indice] != nullptr) continue;

            if (tipo == "fogo") {
                equipe[indice] = new PokemonFogo(nomePokemon, id, vida, ataque, defesa);
            } else if (tipo == "agua") {
                equipe[indice] = new PokemonAgua(nomePokemon, id, vida, ataque, defesa);
            } else if (tipo == "planta") {
                equipe[indice] = new PokemonPlanta(nomePokemon, id, vida, ataque, defesa);
            } else if (tipo == "eletrico") {
                equipe[indice] = new PokemonEletrico(nomePokemon, id, vida, ataque, defesa);
            }
        }
    }
    itens[0] = new Cura();
    itens[1] = new Fortificante();
}

std::string Treinador::getNome() const {
    return nome;
}

Pokemon* Treinador::getPokemon(int indice) const {
    if (indice < 0 || indice >= 3) return nullptr;
    return equipe[indice];
}

Pokemon* Treinador::getAtivo() const {
    return equipe[ativo];
}

Item* Treinador::getItem(int indice) const {
    if (indice < 0 || indice >= 2) return nullptr;
    return itens[indice];
}

int Treinador::getIndiceAtivo() const {
    return ativo;
}

bool Treinador::perdeu() const {
    for (int i = 0; i < 3; i++) {
        if (equipe[i] != nullptr && !equipe[i]->derrotado()) {
            return false;
        }
    }
    return true;
}
bool Treinador::usarItem(int item, int alvo) {
    if (item < 0 || item >= 2 || itens[item] == nullptr) return false;
    if (alvo < 0 || alvo >= 3 || equipe[alvo] == nullptr) return false;

    if (itens[item]->usar(*equipe[alvo])) {
        delete itens[item];
        itens[item] = nullptr;
        return true;
    }
    return false;
}