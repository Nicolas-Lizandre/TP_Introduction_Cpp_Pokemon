//
// Created by nicol on 10/09/2026.
//

#ifndef POKEMON_H
#define POKEMON_H
#include <memory>
#include <vector>
#include <string>

#include "../PokemonState/PokemonState.hpp"

#pragma once
class PokemonState;

//enum PokemonState {IN_SHAPE,MAGIC_SICKNESS,KO};

class Pokemon {

    private :
        int id;
        std::string name;
        double hitPoint;
        double attack;
        double defense;
        double spAtk;
        double spDef;
        double speed;
        int generation;
        std::unique_ptr<PokemonState> pokemonState; //<-COMMENCER CHANTIER

    public :
        static int nb_pokemon_created; //C'est pour pouvoir le lire depuis l'objet et ne pas se retrouver avec des statics éparpillés

        //Fonctions obligatoires
        Pokemon() = delete;
        Pokemon(int id, std::string name, double hitPoint, double attack, double defense,
            double spAtk, double spDef, double speed, int generation);
        ~Pokemon();
        Pokemon& operator=(const Pokemon& other); //le std::unique_ptr empêche l'utilisation d'opérateur=, il faut le réimplémenter nous-même

        //Fonctions ajoutées
        Pokemon(const Pokemon &AnotherPokemon); //a valeur de création de nouvel objet Pokemon
        void displayInfo() const; //Cela signifie qu'il ne modifie pas l'état de la variable
        int getId() const;
        std::string getName() const;
        double getHitPoint() const;
        double getAttack() const;
        double getDefense() const;
        double getSpAtk() const;
        double getSpDef() const;
        double getSpeed() const;
        PokemonState * getPokemonState() const;
        int getGeneration() const;

        //Modif des caractéristiques
        void Attack(Pokemon* DefendingPokemon);
        void Damage(double damage_on_selected_pokemon);
        void setState(PokemonState * state);
        void Heal(double amount_restored);

        //Fts_internes
        double getPokemonMaxHitPoint() const;
        void applyMinimalDamage_IfEligibility(double damage);
        void applyKO_IfEligibility();

        //Cas placeholder pokemon
        static Pokemon createPlaceholderPokemon();
        void manageInitialPokemonStateSelection();
        bool isPlaceholderPokemon() const;
};


#endif //POKEMON_H
