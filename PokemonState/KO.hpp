//
// Created by nicol on 14/09/2026.
//

#ifndef KO_H
#define KO_H

#include "PokemonState.hpp"

class KO : public PokemonState {
    public:
        KO()=default;
        [[nodiscard]] bool isPokemonSendable() const override;
        [[nodiscard]] bool isPokemonAltered() const override;
        [[nodiscard]] std::string getName() const override;
        std::unique_ptr<PokemonState> clone() const override;
        double getSicknessStrength() const override;

};
#endif //KO_H
