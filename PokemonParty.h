//
// Created by nicol on 11/09/2026.
//

#ifndef POKEMONPARTY_H
#define POKEMONPARTY_H
#include "SetOfPokemon.h"

//En faire une design pattern state
enum BattleState {IN_PARTY,JUST_SENT,FIGHTING}BATTLESTATE;
enum PokemonState {IN_SHAPE,KO}POKEMONSTATE;


class PokemonParty : private SetOfPokemon{
private:
    //std::vector<Pokemon> setofpokemon; //redondant déjà défini par SetOfPokemon

public:
    Pokeball();
    void pushPokemon_INTO_Battlefield(Pokemon &pokemon);
    void pushPokemon_INTO_PokemonParty(Pokemon &pokemon);
    Pokemon *getPokemon_withName(std::string name) override; //Inutiles ici donc je mets {}
    Pokemon *getPokemon_withId(int Id) override;
};
#endif //POKEMONPARTY_H
