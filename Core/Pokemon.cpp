//
// Created by nicol on 10/09/2026.
//

#include <string>
#include <iostream>
#include <ostream>

#include "Pokemon.hpp"
#include "Pokedex.hpp"
#include "../PokemonState/InShape.hpp"
#include "../PokemonState/KO.hpp"
#include "../PokemonState/MagicSickness.hpp"

#define POKEDEX_CSV "Assets/data/pokedex.csv"


//(Pokemon:: pour signifier que la méthode vient de Pokemon.h)

int Pokemon::nb_pokemon_created=0; //Façon généralement acceptée pour initialiser une variable static d'une classe

//Fts obligatoires
Pokemon::Pokemon(int id, std::string name, double hitPoint, double attack, double defense,
    double spAtk, double spDef, double speed, int generation) :
id(id), name(name) , hitPoint(hitPoint), attack(attack), defense(defense), spAtk(spAtk), spDef(spDef), speed(speed),generation(generation), pokemonState(InShape().clone()){
    manageInitialPokemonStateSelection();
    nb_pokemon_created += 1; //suivi nombre Pokemon créé
    //std::cout << "Pokemon " << name << " created" << std::endl; //message debug
}

Pokemon::~Pokemon() {
    Pokemon::nb_pokemon_created -= 1; //suivi nombre Pokemon créé
    //std::cout << "Pokemon is deleted" << std::endl; //message debug
}

Pokemon& Pokemon::operator=(const Pokemon& other) {
    if(this != &other)
    {
        //std::cout << "ASSIGN " << other.getName() << std::endl;
        //std::cout << "other.pokemonState = "<< other.pokemonState.get()<< std::endl; //debug

        id = other.id;
        name = other.name;
        hitPoint = other.hitPoint;
        attack = other.attack;
        defense = other.defense;
        spAtk = other.spAtk;
        spDef = other.spDef;
        speed = other.speed;
        generation = other.generation;
        pokemonState = other.pokemonState->clone();
    }

    return *this;
}

//Fts ajoutées
//Rajoute une méthode alternative pour fabriquer une instance Pokemon
Pokemon::Pokemon(const Pokemon& AnotherPokemon) :
id(AnotherPokemon.id), name(AnotherPokemon.name), hitPoint(AnotherPokemon.hitPoint),attack(AnotherPokemon.attack),
defense(AnotherPokemon.defense), spAtk(AnotherPokemon.spAtk), spDef(AnotherPokemon.spDef), speed(AnotherPokemon.speed),
generation(AnotherPokemon.generation), pokemonState(AnotherPokemon.pokemonState->clone()){
    Pokemon::nb_pokemon_created += 1; //suivi nombre Pokemon créé
    //std::cout << "Pokemon " << name << " copied" << std::endl; //message debug
}

void Pokemon::displayInfo() const {
    std::cout<<"************************"<< std::endl;
    std::cout<< "Pokemon name :" << name << std::endl;
    std::cout<< "Pokemon id :" << id << std::endl;
    std::cout <<"Pokemon hitPoint :" <<hitPoint<<std::endl;
    std::cout <<"Pokemon attack :" <<attack<<std::endl;
    std::cout <<"Pokemon defense :" <<defense<<std::endl;
    std::cout <<"Pokemon sp.attack :" <<spAtk<<std::endl;
    std::cout <<"Pokemon sp.defense :" <<spDef<<std::endl;
    std::cout <<"Pokemon speed :" <<speed<<std::endl;
    std::cout <<"Pokemon generation :" <<generation<<std::endl;
    std::cout <<"Pokemon current shape :" <<pokemonState->getName()<<std::endl;
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

double Pokemon::getSpAtk() const {
    return spAtk;
}

double Pokemon::getSpDef() const {
    return spDef;
}

double Pokemon::getSpeed() const {
    return speed;
}

//Retourne une copie !
PokemonState * Pokemon::getPokemonState() const {
    if(pokemonState->getName() == "InShape") {
        return new InShape();
    }
    else if(pokemonState->getName() == "MagicSickness") {
        return new MagicSickness(pokemonState->getSicknessStrength());
    }
    else {return new KO();}

}



int Pokemon::getGeneration() const {
    return generation;
}

//Une version alternativePour enlever static il faut que ça s'applique à un unique objet ! PAS les 2 !
//Pour rappel toute les méthodes (sauf static) sont censé être entichées sur un objet
void Pokemon::Attack(Pokemon *DefendingPokemon) {
    double damage = attack - DefendingPokemon->defense;
    std::cout << name << " damages " <<  DefendingPokemon->getName() << " for "<< std::max(5.0, damage) << std::endl; //message debug
    DefendingPokemon->applyMinimalDamage_IfEligibility(damage);
    //Apply KO sera géré par le PokemonBattle
}//Ce code n'est pas clean - il fait trop de trucs, il mélange 3 méthodes : "return_pokemon_state/is_damage_sucessesful/damage_dealt


void Pokemon::Damage(double damage_on_selected_pokemon) {
    this->applyMinimalDamage_IfEligibility(damage_on_selected_pokemon);
    this->applyKO_IfEligibility();
}



void Pokemon::setState(PokemonState * state) {
    pokemonState = state->clone();
}

void Pokemon::Heal(double amount_restored) {
    hitPoint += amount_restored;
    double base_hitPoint = Pokedex::Pokedex_GetInstance()->getPokemon_withId(this->getId())->getHitPoint();
    if (base_hitPoint < hitPoint) { //Heal Cap
        hitPoint = base_hitPoint;
    }
}


//Fts internes
double Pokemon::getPokemonMaxHitPoint() const {
    return Pokedex::Pokedex_GetInstance()->getPokemon_withName(name)->getHitPoint();
}

void Pokemon::applyMinimalDamage_IfEligibility(double damage) {
    if(damage < 5){damage = 5;} //test de validité - //Pour éviter softlocks
    hitPoint = hitPoint - damage;
}

void Pokemon::applyKO_IfEligibility() {
    if (hitPoint <= 0) { //Corrige HP
        hitPoint = 0;
        pokemonState = KO().clone();
        std::cout << "EndFight pour " << name <<std::endl;
    }
}


//Fts pour gérer Placeholder Pokemon
Pokemon Pokemon::createPlaceholderPokemon() {
    return {-1, "PLACEHOLDER",0.0,0.0,0.0,0.0,0.0,0.0,0};
}

void Pokemon::manageInitialPokemonStateSelection() {
    if (hitPoint <= 0 || isPlaceholderPokemon()) {
        hitPoint = 0;
        pokemonState = KO().clone();
    }
    else {pokemonState = InShape().clone();}
}

bool Pokemon::isPlaceholderPokemon() const {
    if (id == -1 || name == "PLACEHOLDER") {
        return true;
    }
    return false;
}

