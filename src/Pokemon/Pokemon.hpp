#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <string>

#include "../Golpe/Golpe.hpp"
class Pokemon {
private:
    std::string nome;
    std::string tipo;
    int idPokemon;
    int vida;
    int vidaMaxima;
    int ataque;
    int defesa;
    int reducaoProximoAtaque;
    bool fortalecido;
    Golpe* golpes[2];

public:
    Pokemon(std::string nome,int idPokemon,int vida,int ataque,int defesa, std::string tipo);
    ~Pokemon();
    // Pegar procurar buscar as inf dos pkmn

    std::string getNome();
    int getIdPokemon();
    int getVida();
    int getVidaMaxima();   
    int getAtaque();
    int getDefesa();
    std::string getTipo();
    bool derrotado();
//buscando os golpes
    Golpe* getGolpe(int indice);
    void definirGolpe(int indice, Golpe* golpe);

    // efeitos de batalha(perda de vida, buffer e dff)

    int perderVida(int quantidade);
    int curar(int quantidade);
    void reduzirAtaque(int quantidade);
    int consumirReducaoAtaque();
    bool fortalecer();
    double consumirFortalecimento();
    virtual int calcularDanoRecebido(int dano, std::string tipoAtacante) =0;


};
#endif