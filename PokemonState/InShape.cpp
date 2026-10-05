//
// Created by nicol on 14/09/2026.
//
#include "InShape.hpp"


bool InShape::isPokemonSendable() const {
    return true;
}
bool InShape::isPokemonAltered() const {
    return false;
}

std::string InShape::getName() const {
    return "InShape";
}

std::unique_ptr<PokemonState> InShape::clone() const {
    return std::make_unique<InShape>(*this);
}

double InShape::getSicknessStrength() const {
    return 0.0;
}
