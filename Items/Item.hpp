//
// Created by nicol on 23/09/2026.
//

#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>

class PokemonParty;

class Item {
    private:
    std::string name;
    std::string description;

    public:
    virtual ~Item()=default;
    //Méthodes
    virtual void useItem(PokemonParty * using_item_party,PokemonParty * waiting_party)=0;
    //Getters
    virtual std::string getName() const=0;
    virtual std::string getDescription() const=0;

};
#endif //ITEM_HPP
