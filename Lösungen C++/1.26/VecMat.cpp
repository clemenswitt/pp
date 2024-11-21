#include "VecMat.h"
#include <random>

std::mt19937 g_randNum{std::random_device{}()};

double zufallZahl(double startWert, double endWert) {
    std::uniform_real_distribution<double> zahl{startWert, endWert};
    return zahl(g_randNum);
}