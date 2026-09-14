#include <string>
#include "Pokemon.h"

#include <iostream>
#include <ostream>
//
// Created by nicol on 10/09/2026.
//
//(Pokemon:: pour signifier que la méthode vient de Pokemon.h)

int Pokemon::nb_pokemon_created=0; //Façon généralement acceptée pour initialiser une variable static d'une classe

//Fts obligatoires
Pokemon::Pokemon(int id, std::string name, double hitPoint, double attack, double defense, int generation) :
id(id), name(name) , hitPoint(hitPoint), attack(attack), defense(defense), generation(generation) {
    nb_pokemon_created += 1; //suivi nombre Pokemon créé
    std::cout << "Pokemon " << name << " created" << std::endl; //message debug
}

Pokemon::~Pokemon() {
    Pokemon::nb_pokemon_created -= 1; //suivi nombre Pokemon créé
    std::cout << "Pokemon is deleted" << std::endl; //message debug
}



//Fts ajoutées
//Rajoute une méthode alternative pour fabriquer une instance Pokemon
Pokemon::Pokemon(const Pokemon& AnotherPokemon) :
id(AnotherPokemon.id), name(AnotherPokemon.name), hitPoint(AnotherPokemon.hitPoint),
attack(AnotherPokemon.attack), defense(AnotherPokemon.defense), generation(AnotherPokemon.generation) {
    Pokemon::nb_pokemon_created += 1; //suivi nombre Pokemon créé
    std::cout << "Pokemon " << name << " copied" << std::endl; //message debug
}

void Pokemon::displayInfo() const {
    std::cout<<"************************"<< std::endl;
    std::cout<< "Pokemon name :" << name << std::endl;
    std::cout<< "Pokemon id :" << id << std::endl;
    std::cout <<"Pokemon hitPoint :" <<hitPoint<<std::endl;
    std::cout <<"Pokemon attack :" <<attack<<std::endl;
    std::cout <<"Pokemon defense :" <<defense<<std::endl;
    std::cout <<"Pokemon generation :" <<generation<<std::endl;
    std::cout<<"************************"<< std::endl;

}

int Pokemon::getId() const {
    return id;
}

std::string Pokemon::getName() const {
    return name;
}

double Pokemon::getHitPoint() const {
    return hitPoint;
}

double Pokemon::getAttack() const {
    return attack;
}

double Pokemon::getDefense() const {
    return defense;
}

int Pokemon::getGeneration() const {
    return generation;
}

//Une version alternativePour enlever static il faut que ça s'applique à un unique objet ! PAS les 2 !
//Pour rappel toute les méthodes (sauf static) sont censé être entichées sur un objet
void Pokemon::Attack(Pokemon &DefendingPokemon) {
    std::cout << name << " attacks " << attack << std::endl; //message debug
    double damage = attack - DefendingPokemon.defense;
    if(damage < 0){damage = 0;} //test de validité
    DefendingPokemon.hitPoint = DefendingPokemon.hitPoint - damage;
    if (DefendingPokemon.hitPoint <= 0) { //Corrige HP
        DefendingPokemon.hitPoint = 0;
    }
    DefendingPokemon.Check_if_Fainted(); //Un Observer serait bq plus cool
}//Ce code n'est pas clean - il fait trop de trucs, il mélange 3 méthodes : "return_pokemon_state/is_damage_sucessesful/damage_dealt



//Méthodes à usage interne à priori
//Pour Pokemon::Attack
void Pokemon::Check_if_Fainted() {
    if(hitPoint==0){
        std::cout << name << " has fainted" << std::endl;
    }
    else {
        std::cout << name << " has now " << hitPoint << " hitPoint"  << std::endl;
    }
}
