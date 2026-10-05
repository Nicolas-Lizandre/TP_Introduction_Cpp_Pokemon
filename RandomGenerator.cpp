//
// Created by nicol on 26/09/2026.
//
#include "RandomGenerator.hpp"

std::mt19937 RandomGenerator::gen(
    std::random_device{}()
);