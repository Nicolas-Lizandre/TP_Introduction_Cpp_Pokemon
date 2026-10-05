//
// Created by nicol on 14/09/2026.
//

#ifndef INSHAPE_H
#define INSHAPE_H

#include "PokemonState.hpp"

class InShape : public PokemonState {
    public:
        InShape()=default;
        [[nodiscard]] bool isPokemonSendable() const override;
        [[nodiscard]] bool isPokemonAltered() const override;
        [[nodiscard]] std::string getName() const override;

        std::unique_ptr<PokemonState> clone() const override;
        double getSicknessStrength() const override;

};
#endif //INSHAPE_H
