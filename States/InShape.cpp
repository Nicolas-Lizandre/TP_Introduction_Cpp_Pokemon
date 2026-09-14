//
// Created by nicol on 14/09/2026.
//

#include "InShape.h"
#include "C:\Users\nicol\Documents\Repositoires Github\TP Introduction_C++_Pokemon\Pokemon.h"


bool InShape::Is_Pokemon_Sendable() {
    return true;
}
bool InShape::Has_pokemon_Alteration() {
    return false;
}
Pokemon * InShape::Alteration_Effects(Pokemon& pokemon) {
    return &pokemon;
}