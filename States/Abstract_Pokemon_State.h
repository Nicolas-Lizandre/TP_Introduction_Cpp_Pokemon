//
// Created by nicol on 14/09/2026.
//

#ifndef ABSTRACT_POKEMON_STATE_H
#define ABSTRACT_POKEMON_STATE_H
class Abstract_Pokemon_State {
    public:
    virtual bool Is_Pokemon_Sendable();
    virtual bool Has_pokemon_Alteration();
    virtual Pokemon Alteration_Effects();


};
#endif //ABSTRACT_POKEMON_STATE_H
