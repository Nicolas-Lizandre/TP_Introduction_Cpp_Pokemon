//
// Created by nicol on 04/10/2026.
//

#ifndef GAME_HPP
#define GAME_HPP
#include "PokemonParty.hpp"

inline enum GameMode{VS_Player, VS_CPU}GAMEMODE;
inline enum Team{RIGHT, LEFT}TEAM;
class Game{
private:
    PokemonParty party_left;
    PokemonParty party_right;
    std::vector<Pokemon> pokemons_party_left;
    std::vector<Pokemon> pokemons_party_right;
    Item_Inventory items_party_left;
    Item_Inventory items_party_right;

    GameMode mode;

    void askForGamemode();

    void askForPartyPokemons(Team team);
    void entryCompositionMessage(Team team);
    bool checkIfPartyValid(const std::vector<Pokemon>& pokemons_party_right);

    void addingPlaceholder();

    void completeOthersByPlaceholder(std::vector<Pokemon>& pokemons_party_right);
    std::vector<Pokemon> *teamCorrespondingPokemonParty(Team team);

    void askForItems(Team team);
    Item_Inventory *teamCorrespondingItemInventory(Team team);

    void startFight();

public:
    Game()=default;
    ~Game()=default;
    void startGame();


};
#endif //GAME_HPP
