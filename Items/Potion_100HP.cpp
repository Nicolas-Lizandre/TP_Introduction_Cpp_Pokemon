//
// Created by nicol on 28/09/2026.
//

#include "Potion_100HP.hpp"

#include "../Core/PokemonParty.hpp"
#define POKEDEX_CSV "Assets/data/pokedex.csv"


//Variables à initialiser
Potion_100HP * Potion_100HP::potion_100HP_unique_instance = nullptr;
std::mutex Potion_100HP::potion_100HP_mutex;

//Pour Singleton
Potion_100HP * Potion_100HP::Potion_100HP_GetInstance() {
    std::lock_guard<std::mutex> lock(potion_100HP_mutex); //se délock automatiquement
    if(potion_100HP_unique_instance == nullptr) {
        potion_100HP_unique_instance = new Potion_100HP();
    }
    return potion_100HP_unique_instance;
}

//Méthodes
void Potion_100HP::useItem(PokemonParty * using_item_party,PokemonParty * waiting_party) {
    using_item_party->sentPokemon()->Heal(100.0);
}

// (ne pas oublier d'utiliser quantity)


//Getters
std::string Potion_100HP::getName() const {
    return name;
}

std::string Potion_100HP::getDescription() const {
    return description;
}
