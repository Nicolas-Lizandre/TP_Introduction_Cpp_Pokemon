//
// Created by nicol on 14/09/2026.
//

#include "InShape.h"
#include "C:\Users\nicol\Documents\Repositoires Github\TP Introduction_C++_Pokemon\Pokemon.h"
#include "KO.h"
bool KO::Is_Pokemon_Sendable() {
    return false;
}
bool KO::Has_pokemon_Alteration() {
    return false;
}
Pokemon * KO::Alteration_Effects(Pokemon& pokemon) {
    return &pokemon;
}