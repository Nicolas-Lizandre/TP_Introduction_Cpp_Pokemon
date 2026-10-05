//
// Created by nicol on 14/09/2026.
//

#include <fstream>
#include <iostream>

#include "Core/Game.hpp"
#include "Core/Pokedex.hpp"
#include "Core/Pokemon.hpp"
#include "Core/PokemonBattle.hpp"
#include "Core/PokemonParty.hpp"
#include "Items/Pokeball.hpp"
#include "Items/Potion_100HP.hpp"
#include "PokemonState/KO.hpp"

#define POKEDEX_CSV "../Assets/data/pokedex.csv"

int main() {
    Pokedex::Initialize_Pokedex(POKEDEX_CSV); //Permet d'utiliser un nouveau fichier - Changement impossible à postériori pour des raisons de concurrence de ressources
    Game game = Game();
    game.startGame();
    return 0;
}

