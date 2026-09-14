//
// Created by nicol on 11/09/2026.
//

#include <string>

#include "Pokemon.h"
#include "Pokedex.h"

#include <fstream>
#include <iostream>
#include <sstream>

//Variables à initialiser
Pokedex * Pokedex::pokedex_unique_instance = nullptr;
std::mutex Pokedex::pokedex_mutex;
//appelle automatiquement le constructeur par défaut de std::mutex
//qui initialise l’objet dans un état “déverrouillé” prêt à l’emploi



//Unique Accesseur et "One time" mutateur
Pokedex * Pokedex::Pokedex_GetInstance(const std::string& namefile) {

    std::lock_guard<std::mutex> lock(pokedex_mutex); //se délock automatiquement
    if(pokedex_unique_instance == nullptr) {
        pokedex_unique_instance = new Pokedex(namefile);
        pokedex_unique_instance->FillSetOfPokemon(); //complète setofpokemon (l'ensemble de tous les Pokemon par une fonction)
    }
    return pokedex_unique_instance;
}
/*, setofpokemon({}) {
if
(pokedex_unique_instance
==
nullptr
)
 {
    pokedex_unique_instance = new Pokedex(namefile);
}*/



//Fts qui récupèreront un Pokemon depuis setofpokemon
Pokemon *Pokedex::getPokemon_withName(std::string name) {
    for(Pokemon &pokemon : *this->GetSetOfPokemon()) {   //NE PAS ÉCRIRE Pokemon pokemon : setofpokemon ! Ne jamais oublier qu'en C une adresse bonne si l'objet n'est pas local
        if(pokemon.getName() == name) {
            return &pokemon;
        }
    }
    return nullptr;

}
Pokemon *Pokedex::getPokemon_withId(int Id) {
    for(Pokemon &pokemon : *this->GetSetOfPokemon()) {
        if(pokemon.getId() == Id) {
            return &pokemon;
        }
    }
    return nullptr;
}


//Méthodes à usage interne à priori
//Pour Pokedex * Pokedex_GetInstance
void Pokedex::FillSetOfPokemon() { //----------------------Rajouter un .size sur les lignes du fichier
    this->GetSetOfPokemon()->reserve(1000); //pour éviter les recopies intenpestives
    std::ifstream fichier(namefile);  // Ouvre le fichier
    if (!fichier.is_open()) {  // Vérifie si le fichier est bien ouvert
        std::cerr << "Impossible d'ouvrir le fichier : " << namefile << std::endl; //cerr pour console d'erreur
        return;
    }
    //rajouter un assert ici
    std::string ligne;
    std::getline(fichier, ligne);
    while (std::getline(fichier, ligne)) {  // Lit le fichier ligne par ligne
        std::stringstream ss(ligne);  // Utilise un flux pour diviser la ligne
        std::string cellule;
        std::vector<std::string> donneesLigne;
        // Divise la ligne en cellules séparées par des virgules
        while (std::getline(ss, cellule, ',')) {
            donneesLigne.push_back(cellule);  // Ajoute chaque cellule au vecteur
        }
        // Affiche les données de la ligne ----------------------- C'est ici LE changement vis-à-vis de lireCSV
        this->GetSetOfPokemon()->emplace_back(std::stoi(donneesLigne.at(0)),donneesLigne.at(1),
            std::stoi(donneesLigne.at(5)),std::stoi(donneesLigne.at(6)),
            std::stoi(donneesLigne.at(7)),std::stoi(donneesLigne.at(11)));
        //Pas besoin de spécifier Pokemon - emplace back est codé intelligemment
        //stoi permet de convertir "42" en 42
        //Il y a des sauts pour coller avec les paramètres de notre classe Pokemon
        /*
        for (const auto& valeur : donneesLigne) {
            std::cout << valeur << " ";  // Message debug : Affiche les valeurs séparées par un espace
        }
        std::cout << std::endl;*/
    }
    fichier.close();  // Ferme le fichier
}

