//
// Created by nicol on 14/09/2026.
//

#include "KO.hpp"

bool KO::isPokemonSendable() const {
    return false;
}
bool KO::isPokemonAltered() const {
    return false;
}

std::string KO::getName() const {
    return "KO";
}

std::unique_ptr<PokemonState> KO::clone() const {
    return std::make_unique<KO>(*this);
}

double KO::getSicknessStrength() const {
    return 0;
}
