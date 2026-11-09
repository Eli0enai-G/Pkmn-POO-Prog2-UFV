#ifndef TREINADOR_HPP
#define TREINADOR_HPP
#include <string>
class Treinador {
private: //uml do xulio
    std::string nome;
    Pokemon * equipe[3];
    Item* itens[2];
    int ativo;
public:
    Treinador ( std::string nome , int pokemons [3]) ;
    ~ Treinador () ;

    std::string getNome () ;
    Pokemon * getPokemon (int indice ) ;
    Pokemon * getAtivo () ;
    Item * getItem ( int indice ) ;
    int getIndiceAtivo () ;

    bool trocar ( int indice ) ;
    bool perdeu () ;
    bool usarItem ( int item , int alvo ) ;
};
 #endif