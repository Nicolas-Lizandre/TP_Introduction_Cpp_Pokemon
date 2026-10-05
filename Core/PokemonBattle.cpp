#include <iostream>
#include <ostream>

#include "PokemonBattle.hpp"
#include "PokemonParty.hpp"
#include "../PokemonState/KO.hpp"
#include "../PokemonState/MagicSickness.hpp"
//
// Created by nicol on 23/09/2026.
//
PokemonBattle::PokemonBattle(GameMode gamemode, PokemonParty * party_right, PokemonParty * party_left) : gamemode(gamemode),
party_right(party_right), party_left(party_left) {
}

//Méthodes
bool PokemonBattle::isAPartyDefeated() {
    if(party_right->hasAllThePartyPokemonFainted() == true ||
        party_left->hasAllThePartyPokemonFainted() == true ||
        party_right->getSetOfPokemon()->empty()== true ||
        party_left->getSetOfPokemon()->empty()== true) {
        return true;
    }
    return false;
}

void PokemonBattle::applyKOStateToPokemons() {
    for(int i = 0; i < party_right->getSetOfPokemon()->size(); i++) {
        if(typeid(*party_right->getSetOfPokemon()->at(i).getPokemonState()) != typeid(KO)) {
            party_right->getSetOfPokemon()->at(i).applyKO_IfEligibility();
        }
    }
    for(int i = 0; i < party_left->getSetOfPokemon()->size(); i++) {
        if(typeid(*party_left->getSetOfPokemon()->at(i).getPokemonState()) != typeid(KO)) {
            party_left->getSetOfPokemon()->at(i).applyKO_IfEligibility();
        }
    }
}

void PokemonBattle::managePartySentPokemonToBeChanged() {
    if(party_left->isThereAPokemonSent() == false) {
        selectPokemonToSend(party_left);
    }
    else if(typeid(*party_left->sentPokemon()->getPokemonState()) == typeid(KO)) {
        selectPokemonToSend(party_left);
    }

    if(party_right->isThereAPokemonSent() == false) {
        selectPokemonToSend(party_right);
    }
    else if(typeid(*party_right->sentPokemon()->getPokemonState()) == typeid(KO)) {
        selectPokemonToSend(party_right);
    }
}

void PokemonBattle::manageTurnOrder() {
    double speed_party_left = party_left->sentPokemon()->getSpeed();
    if(SpeedPenaltyEligibility(party_left)){speed_party_left =speed_party_left/2;}

    double speed_party_right = party_right->sentPokemon()->getSpeed();
    if(SpeedPenaltyEligibility(party_right)){speed_party_right =speed_party_right/2;}

    if(speed_party_left>=speed_party_right) {
        team = Team::LEFT;
    }
    else {
        team = Team::RIGHT;
    }

} //Toogle - Right first ou Left first

void PokemonBattle::toogleOrder() {
    if(team == Team::LEFT) {
        team = Team::RIGHT;
    }
    else if(team == Team::RIGHT) {
        team = Team::LEFT;
    }
}

void PokemonBattle::asksForPartyActions() { //Aura besoin d'être complêtement réécrit dans la version finale
    char c;
    bool action_selection=false;
    PokemonParty & doing_action_party = team == Team::RIGHT ? *party_right : *party_left;
    PokemonParty & waiting_party = team == Team::RIGHT ? *party_left : *party_right;

    while(action_selection==false) {

        //Injection Gamemode VS_CPU
        if(gamemode==VS_CPU && team == Team::LEFT) {
            c='a'; //Le CPU attaque bêtement
        }
        else {
            std::cout << ((team == Team::RIGHT) ? "RIGHT" : "LEFT")  << " What is your choice ?" << std::endl;
            std::cout << "> a to attack - b to sp.attack [inflict MagicSickness] - c to change pokemons - z to give up" << std::endl;
            std::cout << "> h to use Potion_100HP - p to use Pokeball - d to display sent pokemons infos" << std::endl;
            std::cin >> c;
        }

        if (c == 'a') {
            doing_action_party.sentPokemon()->Attack(waiting_party.sentPokemon());
            action_selection = true;
        }

        if(c == 'b') {
            waiting_party.sentPokemon()->setState(new MagicSickness((
                doing_action_party.sentPokemon()->getSpAtk() - waiting_party.sentPokemon()->getSpDef())/2.0));
            action_selection = true;
        }

        if(c == 'c') {
            changePokemon(&doing_action_party);
            action_selection = true; //Si tu choisis le même Pokemon ce n'est PAS mon problème
        }

        if(c=='z') {
            giveUp(&doing_action_party);
            action_selection = true;
        }

        if (c == 'h') {
            if(doing_action_party.getInventory()->isItemAvailable("Potion_100HP")) {
                doing_action_party.getInventory()->getItemWithName("Potion_100HP")->useItem(&doing_action_party,&waiting_party);
                doing_action_party.getInventory()->decreaseRespectiveQuantityOfOne("Potion_100HP");
                action_selection = true;
            }
            else{std::cout << "No Potion_100HP are available" << std::endl;}
        }


        if (c == 'p') {
            if(doing_action_party.getInventory()->isItemAvailable("Pokeball")) {
                doing_action_party.getInventory()->getItemWithName("Pokeball")->useItem(&doing_action_party,&waiting_party);
                doing_action_party.getInventory()->decreaseRespectiveQuantityOfOne("Pokeball");
                action_selection = true;
            }
            else{std::cout << "No Pokeball are available" << std::endl;}
        }

        if (c== 'd') {
            doing_action_party.sentPokemon()->displayInfo();
            waiting_party.sentPokemon()->displayInfo();
        }


    }
}


void PokemonBattle::applyAffliction() {
    party_left->sentPokemon()->getPokemonState()->AlterationEffects(party_left->sentPokemon());
    party_right->sentPokemon()->getPokemonState()->AlterationEffects(party_right->sentPokemon());
}


void PokemonBattle::changePokemon(PokemonParty * pokemon_party) {
    pokemon_party->pushPokemon_INTO_PokemonParty(pokemon_party->sentPokemon());
    managePartySentPokemonToBeChanged();
}
void PokemonBattle::giveUp(PokemonParty * pokemon_party) {
    for(int i =0; i < pokemon_party->getSetOfPokemon()->size(); i++) {
        pokemon_party->getSetOfPokemon()->at(i).setState(new KO());
    }
}

//Fonctions internes


void PokemonBattle::selectPokemonToSend(PokemonParty * pokemon_party) {
    bool valid_selection_key = false;
    std::string typetext;
    Pokemon * involved_pokemon;
    int index_ifInjectionCPU=-1;
    while(valid_selection_key==false) {
        //Injection VS_CPU
        if(gamemode==VS_CPU && pokemon_party == party_left) {
            std::cout << "CPU Selecting its next Pokemon" << std::endl;
            index_ifInjectionCPU += 1;
            typetext = std::to_string(index_ifInjectionCPU);
        }
        else {
            std::cout << "Player must choose its next Pokemon (only position here)" << std::endl;
            std::cin >> typetext;
        }
        try {
            involved_pokemon = pokemon_party->getPokemon_withPosition(std::stoi((typetext)));
            if(involved_pokemon !=nullptr && typeid(*involved_pokemon->getPokemonState()) != typeid(KO)) {
                if(pokemon_party->isThereAPokemonSent() == true) {
                    pokemon_party->pushPokemon_INTO_PokemonParty(pokemon_party->sentPokemon());
                }
                valid_selection_key = true;
                pokemon_party->pushPokemon_INTO_Battlefield(&pokemon_party->getSetOfPokemon()->at(std::stoi(typetext)));
            }

        } catch(...) {std::cout << "Number Please" << std::endl;}
    }
}

bool PokemonBattle::SpeedPenaltyEligibility(PokemonParty * pokemon_party) {
    if(*pokemon_party->sentPokemonBattleState() == JUST_SENT) {
        *pokemon_party->sentPokemonBattleState()=FIGHTING;
        return true;
    }
    return false;
}

PokemonParty * PokemonBattle::getTheVictoriousPokemonParty() {
    if(party_right->hasAllThePartyPokemonFainted() == true || party_right->getSetOfPokemon()->empty()== true) {
        std::cout << "Party Left WINS" << std::endl;
        return party_right;
    }
    else if(party_left->hasAllThePartyPokemonFainted() == true || party_left->getSetOfPokemon()->empty()== true) {
        std::cout << "Party Right WINS" << std::endl;
        return party_left;
    }
    return nullptr;
}