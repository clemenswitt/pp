//
// Created by tonih on 14.10.2024.
//
#include "charh.h"
#include <random>

std::mt19937 g_randNum{std::random_device{}()};

char zufallZahl(double startWert, double endWert) {
    std::uniform_real_distribution<double> zahl{startWert, endWert};
    return static_cast<char>(zahl(g_randNum));
}

