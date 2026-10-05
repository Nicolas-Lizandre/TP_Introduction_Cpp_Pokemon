//
// Created by nicol on 11/09/2026.
//

#ifndef POKEBALL_H
#define POKEBALL_H
#include <mutex>

#include "../RandomGenerator.hpp"
#include "Item.hpp"

//Non implémenté au final car je trouve que ce n'est pas très utile -
//Une personne a une version où une Pokebell peut avoir plusieurs Pokemon [donc c'est plus censé]
//Je laisse le code ici en tant que tel mais c'est inutile

class PokemonParty;

class Pokeball : public Item {
    private:
        std::string name;
        std::string description;
        static Pokeball *pokeball_unique_instance;
        static std::mutex pokeball_mutex;
        Pokeball() {
            name = "Pokeball";
            description = "Captures the Pokemon and fully heals it. The rule is the following :/r/n CaptureChance = 1.3 - (current_Pokemon::hitPoint/max_Pokemon::hitPoint). MAX 1.0";
        }
    public:
        //Nécessaire pour Singleton
        static Pokeball * Pokeball_GetInstance();
        Pokeball copie(const Pokeball &)=delete; //Pour prévenir si qq essaye de construire une méthode copie
        void operator=(const Pokeball &)=delete;
        //~Pokeball() override =default;

        //Méthodes
        void useItem(PokemonParty * using_item_party,PokemonParty * waiting_party) override;

        //Getters
        [[nodiscard]] std::string getName() const override;
        [[nodiscard]] std::string getDescription() const override;


};
#endif //POKEBALL_H
