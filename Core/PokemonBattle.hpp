//
// Created by nicol on 23/09/2026.
//

#ifndef POKEMONBATTLE_HPP
#define POKEMONBATTLE_HPP

#include "PokemonParty.hpp"
#include "Game.hpp"

class PokemonBattle {
    private:
    PokemonParty * party_right; //À transformer en std::unique_ptr MAIS on peut faire sans car c'est déclaré à l'extérieur
    PokemonParty * party_left;
    //PokemonParty initial_party_right;
    //PokemonParty initial_party_left; <- Ajout potentiels si option Recommencer

    Team team;
    GameMode gamemode;
    public:
    //Constructeur
    PokemonBattle(GameMode gamemode, PokemonParty * party_right, PokemonParty * party_left);
    PokemonBattle()=delete;
    ~PokemonBattle()=default;

    //Méthodes
    bool isAPartyDefeated();
    void applyKOStateToPokemons();
    void managePartySentPokemonToBeChanged();
    void manageTurnOrder(); //Toogle - Right first ou Left first
    void toogleOrder();
    void asksForPartyActions();
    void applyAffliction();

    //Fonctions internes - Actions
    void changePokemon(PokemonParty * pokemon_party);
    void giveUp(PokemonParty * pokemon_party);

    //Fonctions internes
    void selectPokemonToSend(PokemonParty * pokemon_party);
    bool SpeedPenaltyEligibility(PokemonParty * pokemon_party);
    PokemonParty * getTheVictoriousPokemonParty();

};
#endif //POKEMONBATTLE_HPP
