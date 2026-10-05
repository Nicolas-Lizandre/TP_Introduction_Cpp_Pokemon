//
// Created by nicol on 11/09/2026.
//

#ifndef POKEDEX_H
#define POKEDEX_H
#include <mutex>

#include "SetOfPokemon.hpp"


class Pokedex : private SetOfPokemon{ //Design Pattern SINGLETON

    private:
        //std::vector<Pokemon> setofpokemon;  //redondant déjà défini par SetOfPokemon
        //à cause de la façon dont les classes sont ici organisées
        //il faut passer par un Getter de SetOfPokemon pour l'obtenir surtout parce que Pokedex hérite de SetOfPokemon en private
        static std::string namefile;
        static Pokedex *pokedex_unique_instance;
        static std::mutex pokedex_mutex;

        //~Pokedex()=default; grâce à : virtual ~SetOfPokemon()=default; + private SetOfPokemon

        //Force le constructeur à être accessible QUE en interne (private) - Forece utilisation de Pokedex_GetInstance qui s'occupe de l'unicité
        Pokedex()=default;

    public:
        //Unique Accesseur et "One time" mutateur - static nécessaire pour car seule fonction donnant accès à l'objet
        static void Initialize_Pokedex(std::string namefile); //Peut être instancié une unique fois - Et DOIT se faire avant la première décla de Pokedex
        static Pokedex * Pokedex_GetInstance();


        //Suppression de chemin d'accès pour garantir Singleton
        //Pokedex() = delete;
        Pokedex copie(const Pokedex &)=delete; //Pour prévenir si qq essaye de construire une méthode copie
        void operator=(const Pokedex &)=delete; //Empêche l'opérateur =  d'être utilisé avec Pokedex (ainsi pas de copie de référence !)

        //Méthodes qui récupèreront un Pokemon depuis setofpokemon
        Pokemon *getPokemon_withName(std::string name) override; //Les overides se font à cet étape
        Pokemon *getPokemon_withId(int Id) override;

        //Méthodes internes
        void FillSetOfPokemon();
        static void warnIfDefaultCSVbeenChanged();

        // ~Pokedex();
};
#endif //POKEDEX_H
