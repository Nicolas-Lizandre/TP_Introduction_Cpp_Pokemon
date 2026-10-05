//
// Created by nicol on 11/09/2026.
//

#include <iostream>

#include "PokemonParty.hpp"
#include "../PokemonState/InShape.hpp"
#include "../PokemonState/KO.hpp"
#include "../Items/Item_Inventory.hpp"

PokemonParty::PokemonParty(std::vector<Pokemon> setofpokemon, Item_Inventory inventory)
: setofpokemon(setofpokemon), inventory(inventory) {
    for (int i = 0; i < setofpokemon.size(); i++) {
        respective_BattleState.push_back(IN_PARTY);
    }
}


void PokemonParty::pushPokemon_INTO_Battlefield(Pokemon * pokemon) {
    //Il devra être couplé avec un check_validity avant/ pas de gardes ici
    for(int i = 0; i < setofpokemon.size(); i++){
        if(pokemon == &setofpokemon[i]) {
            respective_BattleState[i]=JUST_SENT;
        }
    }
}

void PokemonParty::pushPokemon_INTO_PokemonParty(Pokemon *pokemon) {
    for(int i = 0; i < setofpokemon.size(); i++){
        if(pokemon == &setofpokemon[i]) {
            respective_BattleState[i]=IN_PARTY;
        }
    }
}

std::vector<Pokemon> * PokemonParty::getSetOfPokemon() {
    return &setofpokemon;
}

std::vector<BattleState> * PokemonParty::getRespectiveBattleState() {
    return &respective_BattleState;
}

Pokemon *PokemonParty::getPokemon_withName(std::string name) {
    for(int i = 0; i < setofpokemon.size(); i++){
        if(setofpokemon[i].getName() == name) {
            return &setofpokemon[i];
        }
    }
    return nullptr;
}
Pokemon *PokemonParty::getPokemon_withId(int Id) {
    for(int i = 0; i < setofpokemon.size(); i++){
        if(setofpokemon[i].getId() == Id) {
            return &setofpokemon[i];
        }
    }
    return nullptr;
}

Pokemon * PokemonParty::getPokemon_withPosition(int position) {
    if(position >= setofpokemon.size()) {
        return nullptr;
    }

    for(int i = 0; i < setofpokemon.size(); i++){
        if(i == position) {
            return &setofpokemon[i];
        }
    }
    return nullptr;
}

bool PokemonParty::hasAllThePartyPokemonFainted() const {
    for(int i = 0; i < setofpokemon.size(); i++) { //Meilleure
        if( typeid(*(setofpokemon.at(i).getPokemonState())) == typeid(InShape) ) { //Attention le type doit être direct la classe
            return false;
        }
    }
    return true;
}

bool PokemonParty::hasTheSentPokemonFainted() const {
    for(int i = 0; i < setofpokemon.size(); i++) {
        if(respective_BattleState[i] == JUST_SENT || respective_BattleState[i] == FIGHTING
            && typeid(setofpokemon.at(i).getPokemonState()) == typeid(KO)) {
            return true;
        }
    }
    return false;
}

Pokemon * PokemonParty::sentPokemon() {
    for(int i = 0; i < setofpokemon.size(); i++) {
        if(respective_BattleState[i] == JUST_SENT || respective_BattleState[i] == FIGHTING) {
            return &setofpokemon[i];
        }
    }
    return nullptr;
}

BattleState * PokemonParty::sentPokemonBattleState() {
    for(int i = 0; i < setofpokemon.size(); i++) {
        if(respective_BattleState[i] == JUST_SENT || respective_BattleState[i] == FIGHTING) {
            return &respective_BattleState[i];
        }
    }
    return nullptr;
}

int PokemonParty::getPokemonPosition(Pokemon *pokemon) const {
    for(int i = 0; i < setofpokemon.size(); i++) {
        if(pokemon == &setofpokemon[i]) {
            return i;
        }
    }
    return -1; //Erreur
}

Item_Inventory *PokemonParty::getInventory() {
    return &inventory;
}

//Pas réel effacement sinon Dangling Pointer
void PokemonParty::eraseSentPokemon(){
    for(size_t i = 0; i < setofpokemon.size(); i++)
    {
        if(respective_BattleState[i] == JUST_SENT || respective_BattleState[i] == FIGHTING){
            setofpokemon[i] = Pokemon::createPlaceholderPokemon();
            respective_BattleState[i] = IN_PARTY;
            return;
        }
    }
}

void PokemonParty::emplaceNewPokemonInPokemonParty(Pokemon pokemon) {
    for (int i = 0; i < setofpokemon.size(); i++) {
        if(setofpokemon[i].getId() == -1) {//Placeholder
            setofpokemon[i] = pokemon;
            respective_BattleState[i] = IN_PARTY;
            return;
        }
    }
    //setofpokemon.push_back(pokemon);
    //respective_BattleState.push_back(IN_PARTY);
}

bool PokemonParty::isThereAPokemonSent() const {
    for(int i = 0; i < setofpokemon.size(); i++) {
        if(respective_BattleState[i] == JUST_SENT || respective_BattleState[i] == FIGHTING) {
            return true;
        }
    }
    return false;
}





