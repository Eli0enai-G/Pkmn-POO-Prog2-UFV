#include "Pokemon.hpp"
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
//metodos perda de hp
int Pokemon::perderVida(int quantidade) {
    if (quantidade <= 0) return 0;
    int vidaAnterior = vida;
    vida = std::max(0, vida - quantidade);
    return vidaAnterior - vida; 
    // vida perdida
}
int Pokemon::curar(int quantidade) {
    if (quantidade <= 0 || derrotado()) return 0;
    int vidaAnterior = vida;
    vida = std::min(vidaMaxima, vida + quantidade);
    return vida - vidaAnterior; // Retorna a quantidade efetivamente curada
}
void Pokemon::reduzirAtaque(int quantidade) {
    if (quantidade > 0) {
        reducaoProximoAtaque = quantidade;
    }
} 
int Pokemon::consumirReducaoAtaque() {
    int reducao = reducaoProximoAtaque;
    reducaoProximoAtaque = 0; // Redefine para zero após ser consultado/consumido
    return reducao;
}
bool Pokemon::fortalecer() {
    if (derrotado() || fortalecido) return false;
    fortalecido = true;
    return true;
}
double Pokemon::consumirFortalecimento() {
    if (fortalecido) {
        fortalecido = false; // Remove o efeito após o consumo
        return 1.1;
    }
    return 1.0;
}