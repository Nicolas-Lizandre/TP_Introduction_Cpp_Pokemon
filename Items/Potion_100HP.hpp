//
// Created by nicol on 28/09/2026.
//

#ifndef POTION_100HP_HPP
#define POTION_100HP_HPP
#include <mutex>

#include "Item.hpp"


class Potion_100HP : public Item{
private:
    std::string name;
    std::string description;
    static Potion_100HP *potion_100HP_unique_instance;
    static std::mutex potion_100HP_mutex;
    Potion_100HP() {
        name = "Potion_100HP";
        description = "Add 100 to hitPoint of the Pokemon. Caps to the max Pokemon hitPoint (the one given by the Pokedex.csv)";
    }
public:
    //Nécessaire pour Singleton
    static Potion_100HP * Potion_100HP_GetInstance();
    Potion_100HP copie(const Potion_100HP &)=delete; //Pour prévenir si qq essaye de construire une méthode copie
    void operator=(const Potion_100HP &)=delete;
    //~Pokeball() override =default;

    //Méthodes
    void useItem(PokemonParty * using_item_party,PokemonParty * waiting_party) override;

    //Getters
    std::string getName() const override;
    std::string getDescription() const override;
};



#endif //POTION_100HP_HPP
