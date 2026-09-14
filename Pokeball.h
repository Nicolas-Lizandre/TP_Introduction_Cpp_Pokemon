//
// Created by nicol on 11/09/2026.
//

#ifndef POKEBALL_H
#define POKEBALL_H
#include "Pokemon.h"
#include "SetOfPokemon.h"

//Non implémenté au final car je trouve que ce n'est pas très utile -
//Une personne a une version où une Pokebell peut avoir plusieurs Pokemon [donc c'est plus censé]
//Je laisse le code ici en tant que tel mais c'est inutile

class Pokeball : private SetOfPokemon{
    private:
        //std::vector<Pokemon> setofpokemon; //redondant déjà défini par SetOfPokemon
        //C'est celui Pokemon pokemon;
    public:
        Pokeball();
        void pushPokemon_INTO_Pokeball(Pokemon &pokemon);
        void pushPokemon_OUT_Pokeball(Pokemon &pokemon);
        Pokemon *getPokemon_withName(std::string name) override {return nullptr; }; //Inutiles ici donc je mets {}
        Pokemon *getPokemon_withId(int Id) override { return nullptr; };
};
#endif //POKEBALL_H
