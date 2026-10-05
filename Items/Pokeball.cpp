//
// Created by nicol on 11/09/2026.
//

#include <cstdlib> // pour rand() et srand()
#include <ctime>   // pour time()
#include <iostream>
#include <ostream>

#include "../Items/Pokeball.hpp"
#include "../Core/Pokemon.hpp"
#include "../Core/PokemonParty.hpp"
#include "../Core/Pokedex.hpp"
#include "../RandomGenerator.hpp"
#include "../Items/Item.hpp"

#define POKEDEX_CSV "Assets/data/pokedex.csv"


//Variables à initialiser
Pokeball * Pokeball::pokeball_unique_instance = nullptr;
std::mutex Pokeball::pokeball_mutex;

//Pour Singleton
Pokeball * Pokeball::Pokeball_GetInstance() {
    std::lock_guard<std::mutex> lock(pokeball_mutex); //se délock automatiquement
    if(pokeball_unique_instance == nullptr) {
        pokeball_unique_instance = new Pokeball();
    }
    return pokeball_unique_instance;
}

//Méthodes
void Pokeball::useItem(PokemonParty * using_item_party, PokemonParty * waiting_party) {
    if ((waiting_party->sentPokemon()->getHitPoint()/waiting_party->sentPokemon()->getPokemonMaxHitPoint()+0.2 < RandomGenerator::Uniform())){
        std::cout << "Hahaha! You're MINE " << waiting_party->sentPokemon()->getName() << std::endl;
        //Il faut créer une méthode rien que pour ça (l'enlèvement du Pokemon) - Disons que les 2 joueurs envoient des Pokeballs :
        //il ne faut pas que cela crée des emplacements jamais remplis
        //ce code peut se faire uniquement ICI sous prétexte que c'est le seul moment où les pokemons font changer d'emplacement
        using_item_party->emplaceNewPokemonInPokemonParty(
        *(Pokedex::Pokedex_GetInstance()->getPokemon_withId(waiting_party->sentPokemon()->getId())));
        waiting_party->eraseSentPokemon();
    }

}


//Getters
std::string Pokeball::getName() const {
    return name;
}
std::string Pokeball::getDescription() const {
    return description;
}

