#include <iostream>
#include <array>
#include <random>
#include "DETERMINANTE.h"

void printMatrix(const std::array<std::array<double, 3>,3>& matrix);
double calcDeterminante(const std::array<std::array<double, 3>, 3>& matrix);
double zufallZahl(const double startWert, const double endWert);
void initMatrix(std::array<std::array<double, 3>, 3>& matrix, const double startWert, const double endWert);


int main() {
    constexpr double startVal{};
    constexpr double endVal{};

    std::array<std::array<double, 3>, 3> matrix{};

    initMatrix(matrix, 0.0, 10.0);
    printMatrix(matrix);

    std::cout << "Determinante ist: "  << calcDeterminante(matrix) << std::endl;
}
