//
// Created by nicol on 11/09/2026.
//

#ifndef POKEMONPARTY_H
#define POKEMONPARTY_H

#include "Pokemon.hpp"
#include "SetOfPokemon.hpp"
#include "../Items/Item_Inventory.hpp"
//#include "SetOfPokemon.h" <- Le compilateur me l'interdit - va savoir pk
//En faire une design pattern state en s'inspirant de ces lignes

inline enum BattleState {IN_PARTY,JUST_SENT,FIGHTING}BATTLESTATE;//Ajouter State : Alteration_Poison, etc.


class PokemonParty : private SetOfPokemon{
private:
    std::vector<Pokemon> setofpokemon; //redondant déjà défini par SetOfPokemon
    // Déloc à Pokemon car seraient plus pertient :
    //std::vector<PokemonState> respective_PokemonState;
    std::vector<BattleState> respective_BattleState;
    Item_Inventory inventory;

public:
    PokemonParty()=default;
    PokemonParty(std::vector<Pokemon> setofpokemon, Item_Inventory inventory);
    //std::vector<Pokemon> * GetSetOfPokemon(); //déjà déf par SetOfPokemon
    void pushPokemon_INTO_Battlefield(Pokemon *pokemon);
    void pushPokemon_INTO_PokemonParty(Pokemon *pokemon);


    //Getters
    std::vector<Pokemon> *getSetOfPokemon();
    std::vector<BattleState> *getRespectiveBattleState();
    Pokemon *getPokemon_withName(std::string name) override;
    Pokemon *getPokemon_withId(int Id) override;
    Pokemon *getPokemon_withPosition(int position);

    //Pour le battlefield (un Observer)
    [[nodiscard]] bool hasAllThePartyPokemonFainted() const;
    bool hasTheSentPokemonFainted() const;
    Pokemon * sentPokemon();
    BattleState * sentPokemonBattleState();
    int getPokemonPosition(Pokemon * pokemon) const;

    //Pour les objets
    Item_Inventory *getInventory();
    void emplaceNewPokemonInPokemonParty(Pokemon pokemon);
    void eraseSentPokemon();
    [[nodiscard]] bool isThereAPokemonSent() const;

};

#endif //POKEMONPARTY_H
