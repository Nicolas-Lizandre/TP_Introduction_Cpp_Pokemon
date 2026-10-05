//
// Created by nicol on 04/10/2026.
//
#include "Game.hpp"
#include "Pokemon.hpp"
#include "Pokedex.hpp"


#include <iostream>
#include <sstream>

#include "PokemonBattle.hpp"
#include "../Items/Pokeball.hpp"
#include "../Items/Potion_100HP.hpp"


void Game::startGame() {
    std::cout<<"Welcome to the C++ Project of FADE Lizandre"<<std::endl;
    askForGamemode();
    std::cout<<"Create RIGHT et LEFT Pokemon Teams (by default player is RIGHT)"<<std::endl;
    askForPartyPokemons(Team::RIGHT);
    askForPartyPokemons(Team::LEFT);
    addingPlaceholder();
    askForItems(Team::RIGHT);
    askForItems(Team::LEFT);
    //Construction des équipes
    party_left = PokemonParty(pokemons_party_left,items_party_left);
    party_right = PokemonParty(pokemons_party_right,items_party_right);
    //Démarrage du combat
    startFight();
}

void Game::askForGamemode() {
    bool key_validGamemode = false;
    std::string command;
    while(key_validGamemode==false) {
        std::cout<<"Choose Gamemode : 1 - VS_Player / 2 - VS_CPU" <<std::endl;
        std::getline(std::cin, command);
        if (command == "1") {
            mode = GameMode::VS_Player;
            key_validGamemode=true;
        }
        else if (command == "2") {
            mode = GameMode::VS_CPU;
            key_validGamemode=true;
        }
    }
}


void Game::askForPartyPokemons(Team team) {
    entryCompositionMessage(team);

    std::vector<Pokemon> pokemons_party;
    std::string command;
    bool key_validTeam = false;

    while(key_validTeam == false) {
        std::cout << "Write exact Pokemon Id or Name (see Pokemon.csv) - Write STOP to save - Write NO to erase last" << std::endl;
        std::cout << "You have " << pokemons_party.size() << " pokemons. " << std::endl;
        std::getline(std::cin, command);

        if(command == "STOP") {                                                                        //Commande : "STOP"
            if(checkIfPartyValid(pokemons_party)) {
                key_validTeam = true;
            }
        }
        else if(command == "NO") {                                                                    //Commande : "NON"
            pokemons_party.erase(pokemons_party.end());
        }
        else if(Pokedex::Pokedex_GetInstance()->getPokemon_withName(command) != nullptr) {           //Commande : Sélection avec nom
            pokemons_party.emplace_back(*Pokedex::Pokedex_GetInstance()->getPokemon_withName(command));
            pokemons_party.back().displayInfo();
        }
        else {
            try {
                if(Pokedex::Pokedex_GetInstance()->getPokemon_withId(std::stoi(command)) != nullptr) { //Commande : Sélection avec Id
                    pokemons_party.emplace_back(*Pokedex::Pokedex_GetInstance()->getPokemon_withId(std::stoi(command)));
                    pokemons_party.back().displayInfo();
                }
            }
            catch(...) {
                std::cout << "Invalid Name OR Id" << std::endl;
            }
        }
    }
    *teamCorrespondingPokemonParty(team)=pokemons_party;
}

void Game::entryCompositionMessage(Team team) {
    switch(team) {
        case Team::RIGHT : std::cout << "Building of the RIGHT Pokemon Team" << std::endl; break;
        case Team::LEFT : std::cout << "Building of the LEFT Pokemon Team" << std::endl; break;
    }
}


bool Game::checkIfPartyValid(const std::vector<Pokemon>& pokemons_party) {
    if(pokemons_party.size()==0) {
        return false;
    }
    return true;
}

void Game::addingPlaceholder(){
    const int leftSize  = pokemons_party_left.size();
    const int rightSize = pokemons_party_right.size();

    pokemons_party_left.reserve(leftSize + rightSize);
    pokemons_party_right.reserve(leftSize + rightSize);

    for(int i = 0; i < rightSize; ++i){
        pokemons_party_left.push_back(Pokemon::createPlaceholderPokemon());
    }

    for(int i = 0; i < leftSize; ++i){
        pokemons_party_right.push_back(Pokemon::createPlaceholderPokemon());
    }
}

std::vector<Pokemon> * Game::teamCorrespondingPokemonParty(Team team) {
    switch(team) {
        case Team::RIGHT : return &pokemons_party_right;
        case Team::LEFT : return &pokemons_party_left;
    }
    throw std::invalid_argument("Argument 'team' invalid");
}



void Game::askForItems(Team team) {
    entryCompositionMessage(team);

    std::string itemName;
    int quantity;
    Item_Inventory items_party({Pokeball::Pokeball_GetInstance(), Potion_100HP::Potion_100HP_GetInstance()},{0, 0});
    std::string command;
    bool key_validTeam = false;

    while(key_validTeam == false) {
        std::cout << "Write Pokeball <int> OR Potion_100HP <int> [<int> number] - Write STOP to save - Write i to see inventory" << std::endl;
        std::getline(std::cin, command);


        if(command == "STOP") {                   //Commande : "STOP"
            key_validTeam = true;
        }
        else if(command == "i") {                 //Commande : "i"
            items_party.displayInventory();
        }
        else {                                    //Commande : Pokeball <int> ou Potion_100HP <int>
            try{
                std::stringstream ss(command);
                ss >> itemName >> quantity;
                items_party.setRespectiveItemsQuantity(itemName, quantity);
                if(items_party.isNameInItems_Types(itemName) == false) {
                    std::cout << "Item : " << itemName << " does not exist !" << std::endl;
                }

            }
            catch(...) {
                std::cout << "Invalid command" << std::endl;
            }
        }
    }
    *teamCorrespondingItemInventory(team) = items_party;
}

Item_Inventory * Game::teamCorrespondingItemInventory(Team team) {
    switch(team) {
        case Team::RIGHT : return &items_party_right;
        case Team::LEFT : return &items_party_left;
    }
    throw std::invalid_argument("Argument 'team' invalid");
}



void Game::startFight() {
    party_left.pushPokemon_INTO_Battlefield(party_left.getPokemon_withPosition(0));
    party_right.pushPokemon_INTO_Battlefield(party_right.getPokemon_withPosition(0));

    PokemonBattle pokemon_battle(mode, &party_right,&party_left);
    while(true) { //break nécess si isAPartyDefeated()
        std::cout << "Start Turn" << std::endl;
        pokemon_battle.manageTurnOrder();

        pokemon_battle.asksForPartyActions();
        pokemon_battle.applyKOStateToPokemons();
        if(pokemon_battle.isAPartyDefeated()){break;}
        pokemon_battle.managePartySentPokemonToBeChanged();

        pokemon_battle.toogleOrder();

        pokemon_battle.asksForPartyActions();
        pokemon_battle.applyKOStateToPokemons();
        if(pokemon_battle.isAPartyDefeated()){break;}
        pokemon_battle.managePartySentPokemonToBeChanged();
        pokemon_battle.applyAffliction(); //seulement affiché en fin de tour -- Stupide de le faire 2 fois mais nécessaire
        pokemon_battle.managePartySentPokemonToBeChanged();


    }
    pokemon_battle.getTheVictoriousPokemonParty();

}