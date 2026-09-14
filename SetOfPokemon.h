//
// Created by nicol on 11/09/2026.
//

#ifndef SETOFPOKEMON_H
#define SETOFPOKEMON_H
#include <string>
#include <vector>

#include "Pokemon.h"

#endif //SETOFPOKEMON_H

class SetOfPokemon {
    private:
    std::vector<Pokemon> setofpokemon;
    public:
    //Pas de constructeur dans les classes abstraites
    void DisplaySetOfPokemon();
    std::vector<Pokemon> * GetSetOfPokemon();
    virtual Pokemon *getPokemon_withName(std::string name)=0; //Ce sont désormais des méthodes abstraites
    virtual Pokemon *getPokemon_withId(int Id)=0;
    virtual ~SetOfPokemon()=default; //Implémenté pour toutes les classes enfants grâce à =default

    //Toute fonction MÊME VIRTUELLE DOIT être déclaré sinon le linker plante si on écrit :
    //virtual Pokemon *getPokemon_withName(std::string name); on doit donc la déf dans le cpp !!!
};