//
// Created by nicol on 14/09/2026.
//

#ifndef ABSTRACT_POKEMONSTATE_H
#define ABSTRACT_POKEMONSTATE_H

#include "C:\Users\nicol\Documents\Repositoires Github\TP Introduction_C++_Pokemon\Pokemon.h"

class Abstract_PokemonState {
    public:
    virtual ~Abstract_PokemonState() = default;
    virtual bool Is_Pokemon_Sendable()=0;
    virtual bool Has_pokemon_Alteration()=0;
    virtual Pokemon * Alteration_Effects(Pokemon & pokemon)=0; //Le principe est que le Pokemon attaquant aura des propriétés spéciales
};
#endif //ABSTRACT_POKEMONSTATE_H
