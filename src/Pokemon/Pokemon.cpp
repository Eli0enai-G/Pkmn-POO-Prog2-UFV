#include "Pokemon.h"
#include <algorithm>

Pokemon::Pokemon(std::string nome,int idPokemon,int vida,int ataque,int defesa, std::string tipo) 
{
//taldoconstrutor puxa os valores de outro lugar e coloca aqui
    this->nome = nome;
    this->idPokemon = idPokemon;
    this->vida = vida;
    this->vidaMaxima = vida;
    this->ataque = ataque;
    this->defesa = defesa;
    this->tipo = tipo;
    this->reduçãoProximoAtaque = 0;
    this->fortalecido = false;

    this->golpes[0] = nullptr;
    this->golpes[1] = nullptr;
}
 Pokemon::~Pokemon(){
    delete golpes[0];
    delete golpes[1];
 }

std::string Pokemon::getNome(){return nome; }
int Pokemon::getIdPokemon(){return idPokemon; }
int Pokemon::getVida(){return vida; }
int Pokemon::getVidaMaxima(){return vidaMaxima; }
int Pokemon::getAtaque(){return ataque; }
int Pokemon::getDefesa(){return defesa; }
std::string Pokemon::getTipo(){return tipo; }
bool Pokemon::derrotado(){return vida <= 0; }

//golpes
Golpe* Pokemon::getGolpe(int indice){
    if(indice < 0 || indice >= 2) return nullptr;
    return golpes[indice];
}
void Pokemon::definirGolpe(int indice, Golpe* golpe){
    if(indice < 0 || indice >= 2){
        delete golpe;
        return;
    }
    if (golpes[indice] != nullptr) {
        delete golpes[indice];
    }
    golpes[indice] = golpe;
}