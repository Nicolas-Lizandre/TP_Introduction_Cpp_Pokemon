//
// Created by nicol on 11/09/2026.
//

#ifndef POKEMONPARTY_H
#define POKEMONPARTY_H
#include "SetOfPokemon.h"

//En faire une design pattern state en s'inspirant de ces lignes

enum BattleState {IN_PARTY,JUST_SENT,FIGHTING}BATTLESTATE;
enum PokemonState {IN_SHAPE,KO}POKEMONSTATE;       //Ajouter State : Alteration_Poison, etc.


class PokemonParty : private SetOfPokemon{
private:
    //std::vector<Pokemon> setofpokemon; //redondant déjà défini par SetOfPokemon
    std::vector<PokemonState> respective_PokemonStates;
    std::vector<PokemonState> respective_BattleStates;


public:
    PokemonParty()=delete;
    void pushPokemon_INTO_Battlefield(Pokemon &pokemon);
    void pushPokemon_INTO_PokemonParty(Pokemon &pokemon);
    Pokemon *getPokemon_withName(std::string name) override;
    Pokemon *getPokemon_withId(int Id) override;
    void givePokemon_itsRespectiveStates(Pokemon &pokemon); //Les états des Pokemons sont fournies à postériori (faire un builder ??)
};
#endif //POKEMONPARTY_H
