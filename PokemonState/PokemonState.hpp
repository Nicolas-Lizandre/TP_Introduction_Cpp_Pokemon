//
// Created by nicol on 14/09/2026.
//

#ifndef ABSTRACT_POKEMONSTATE_H
#define ABSTRACT_POKEMONSTATE_H

#include <string>
#include <memory>
#pragma once

class Pokemon;

class PokemonState {
    public:
    virtual ~PokemonState() = default;
    virtual bool isPokemonSendable() const=0; //Pour "faire plaisir au compilateur" -Revient au même !!
    virtual bool isPokemonAltered() const=0;
    virtual void AlterationEffects(Pokemon * pokemon){} //Le principe est que le Pokemon attaquant aura des propriétés spéciales
    virtual std::string getName() const=0;
    virtual double getSicknessStrength() const=0;

    virtual std::unique_ptr<PokemonState> clone() const=0;
};
#endif //ABSTRACT_POKEMONSTATE_H
