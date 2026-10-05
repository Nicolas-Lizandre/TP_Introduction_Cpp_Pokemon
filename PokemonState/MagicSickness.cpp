//
// Created by nicol on 24/09/2026.
//
#include "MagicSickness.hpp"

#include <memory>

#include "InShape.hpp"
#include "../RandomGenerator.hpp"
#include "../Core/Pokemon.hpp"

MagicSickness::MagicSickness(double sickness_strength) : sickness_strength(sickness_strength){
}

bool MagicSickness::isPokemonSendable() const {
    return true;
}
bool MagicSickness::isPokemonAltered() const {
    return true;
}
void MagicSickness::AlterationEffects(Pokemon *pokemon) {
    if(RandomGenerator::Uniform() < 1.0/5.0) {
        pokemon->setState(new InShape());
        return;
    }
    pokemon->Damage(sickness_strength);
}

std::string MagicSickness::getName() const {
    return "MagicSickness";
}

std::unique_ptr<PokemonState> MagicSickness::clone() const {
    return std::make_unique<MagicSickness>(*this);
}

double MagicSickness::getSicknessStrength() const {
    return sickness_strength;
}
