//
// Created by nicol on 24/09/2026.
//

#ifndef MAGICSICKNESS_HPP
#define MAGICSICKNESS_HPP

#include "PokemonState.hpp"

class MagicSickness : public PokemonState {
    private:
        std::string name;
        double sickness_strength;

    public:
        //Constructeur
        MagicSickness(double sickness_strength);

        //Méthodes
        bool isPokemonSendable() const override;
        bool isPokemonAltered() const override;
        void AlterationEffects(Pokemon * pokemon) override;
        double getSicknessStrength() const override;


        std::string getName() const override;

        std::unique_ptr<PokemonState> clone() const override;

};


#endif //MAGICSICKNESS_HPP
