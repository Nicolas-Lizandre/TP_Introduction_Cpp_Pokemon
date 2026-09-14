cmake_minimum_required(VERSION 3.29)
project(Testcode)

set(CMAKE_CXX_STANDARD 20)

add_executable(Testcode main.cpp
        Pokemon.cpp
        Pokemon.h
        SetOfPokemon.cpp
        SetOfPokemon.h
        PokemonParty.cpp
        Pokeball.cpp
        Pokedex.cpp
        Pokeball.h
        Pokedex.h
        PokemonParty.h
        States/Abstract_Pokemon_State.h)
