cmake_minimum_required(VERSION 3.29)
project(Testcode)

set(CMAKE_CXX_STANDARD 20)

add_executable(Testcode main.cpp
        Core/Pokemon.cpp
        Core/Pokemon.hpp
        Core/SetOfPokemon.cpp
        Core/SetOfPokemon.hpp
        Core/PokemonParty.cpp
        Items/Pokeball.cpp
        Core/Pokedex.cpp
        Items/Pokeball.hpp
        Core/Pokedex.hpp
        Core/PokemonParty.hpp
        PokemonState/PokemonState.hpp
        PokemonState/InShape.cpp
        PokemonState/InShape.hpp
        PokemonState/KO.hpp
        PokemonState/KO.cpp
        Core/PokemonBattle.cpp
        Core/PokemonBattle.hpp
        Items/Item.hpp
        Items/Item_Inventory.hpp
        Items/Item_Inventory.cpp
        PokemonState/MagicSickness.hpp
        PokemonState/MagicSickness.cpp
        RandomGenerator.hpp
        RandomGenerator.cpp
        Items/Potion_100HP.cpp
        Items/Potion_100HP.hpp
        Core/Game.hpp
        Core/Game.hpp
        Core/Game.cpp
)
