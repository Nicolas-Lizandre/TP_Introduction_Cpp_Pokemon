/*
TASKS : faire ftnner nb_pokemon_created
enlever le static de attack

*/


#include <fstream>
#include <iostream>
#include <sstream>

#include "Pokedex.h"
#include "Pokemon.h"
typedef enum {ROUGE,ORANGE,VERT} Colors; //cachent valeurs 0,1,2
//typedef enum color {ROUGE,ORANGE,VERT} Colors; ftne aussi

typedef struct pomme {
    float taille;
    Colors color;
    char nom[20];
}POMME;


void lireCSV(const std::string& nomFichier) {
    std::ifstream fichier(nomFichier);  // Ouvre le fichier
    if (!fichier.is_open()) {  // Vérifie si le fichier est bien ouvert
        std::cerr << "Impossible d'ouvrir le fichier : " << nomFichier << std::endl; //cerr pour console d'erreur
        return;
    }
    //rajouter un assert ici

    std::string ligne;
    while (std::getline(fichier, ligne)) {  // Lit le fichier ligne par ligne
        std::stringstream ss(ligne);  // Utilise un flux pour diviser la ligne
        std::string cellule;
        std::vector<std::string> donneesLigne;
        // Divise la ligne en cellules séparées par des virgules
        while (std::getline(ss, cellule, ',')) {
            donneesLigne.push_back(cellule);  // Ajoute chaque cellule au vecteur
        }
        // Affiche les données de la ligne
        for (const auto& valeur : donneesLigne) {
            std::cout << valeur << " ";  // Affiche les valeurs séparées par un espace
        }
        std::cout << std::endl;
    }
    fichier.close();  // Ferme le fichier
}




int main() {
    Pokemon * with_id_3 = Pokedex::Pokedex_GetInstance("C:/Users/nicol/Downloads/pokedex.csv")->getPokemon_withId(3);
    Pokemon * poliwag = Pokedex::Pokedex_GetInstance("C:/Users/nicol/Downloads/pokedex.csv")->getPokemon_withName("Poliwag");

    with_id_3->displayInfo();
    poliwag->displayInfo();
    /*
    const auto constante = 3; //constante = 9; ft pas

    std::cout << "Hello, World!" << std::endl;
    printf("Hello, World!\n");
    auto x = 10;
    for(int i = 0; i < 10; i++) {
        std::cout << x+i << std::endl;
    }

    int L[5] = {1, 2, 3, 4, 5}; //[1, 2, 3, 4, 5] ft pas
    L[0] = 9;
    *L=*L+1;
    *(L+1)=*(L+2);
    POMME chery = {0.03, Colors::ORANGE,"chery"}; //il est apparemment pas simple de choper les infos internes
    for(int i = 0; i < 5; i++) {
        std::cout << chery.color << std::endl;
    }
    char s[10];
    std::cin >> s;
    std::cout << s << std::endl;
    */

    Pokemon bullbizare(0,"bullbizare",30,5,5,1);
    Pokemon copie_pokemon(bullbizare);
    Pokemon pikachu(1,"pikachu",25,10,3,1);
    bullbizare.displayInfo();
    pikachu.displayInfo();
    std::cout << "Number of created Pokemon " << Pokemon::nb_pokemon_created << std::endl;
    while(1) { //un design pattern Observer sera à rajouter
        char c;
        std::cout << "Who attacks ?" << std::endl;
        std::cin >> c;
        if (c == 'b') {
            bullbizare.Attack(pikachu);
        }
        if (c == 'p') {
            pikachu.Attack(bullbizare);
        }
    }

    return 0;
}

