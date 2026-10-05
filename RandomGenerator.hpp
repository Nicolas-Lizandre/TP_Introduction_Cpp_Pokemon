//
// Created by nicol on 24/09/2026.
//

#ifndef RANDOMGENERATOR_HPP
#define RANDOMGENERATOR_HPP
#pragma once
#include <random>

//Classe assez étrange car on n'a pas besoin de l'instancier (c'est ChatGPT qui l'a faite)
class RandomGenerator {
private:
    static std::mt19937 gen; //cpp necessaire pour

public:
    //~RandomGenerator(); INUTILE car classe jamais instancié
    static double Uniform(){
        static std::uniform_real_distribution<double> dist(0.0, 1.0);
        return dist(gen);
    }

    static int Randint(int min, int max){
        std::uniform_int_distribution<int> dist(min, max);
        return dist(gen);}
};
#endif //RANDOMGENERATOR_HPP
