//
// Created by nicol on 14/09/2026.
//

#ifndef KO_H
#define KO_H

#include "Abstract_Pokemon_State.h"
#include "C:\Users\nicol\Documents\Repositoires Github\TP Introduction_C++_Pokemon\Pokemon.h"

class KO : public Abstract_PokemonState {
    public:
        KO();
        bool Is_Pokemon_Sendable() override;
        bool Has_pokemon_Alteration() override;
        Pokemon * Alteration_Effects(Pokemon& pokemon) override;
};
#endif //KO_H
