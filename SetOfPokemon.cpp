//
// Created by nicol on 11/09/2026.
//
#include "SetOfPokemon.h"

#include <iostream>

void SetOfPokemon::DisplaySetOfPokemon() {
    for(Pokemon p : setofpokemon) {
        std::cout << "Id : " << p.getId() << "; Name : "<< p.getName() << std::endl;
    }
}

std::vector<Pokemon> * SetOfPokemon::GetSetOfPokemon() {
    return &setofpokemon;
}
