//
// Created by nicol on 10/09/2026.
//

#ifndef POKEMON_H
#define POKEMON_H
#include <vector>
#include <string>
class Pokemon {

    private :
        int id;
        std::string name;
        double hitPoint;
        double attack;
        double defense;
        int generation;


    public :
        static int nb_pokemon_created; //C'est pour pouvoir le lire depuis l'objet et ne pas se retrouver avec des statics éparpillés

        //Fonctions obligatoires
        Pokemon() = delete;
        Pokemon(int id,
        std::string name,
        double hitPoint,
        double attack,
        double defense,
        int generation);
        ~Pokemon();

        //Fonctions ajoutées
        Pokemon(const Pokemon &AnotherPokemon); //a valeur de création de nouvel objet Pokemon
        void displayInfo() const; //Cela signifie qu'il ne modifie pas l'état de la variable
        int getId() const;
        std::string getName() const;
        double getHitPoint() const;
        double getAttack() const;
        double getDefense() const;
        int getGeneration() const;
        void Attack(Pokemon& DefendingPokemon);
        void Check_if_Fainted();
};


#endif //POKEMON_H
