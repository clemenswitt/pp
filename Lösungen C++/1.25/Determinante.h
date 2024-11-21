//
// Created by tonih on 13.10.2024.
//

#ifndef DETERMINANTE_H
#define DETERMINANTE_H
void printMatrix(const std::array<std::array<double, 3>,3>& matrix) {
    std::cout << "Die 3x3-Matrix ist:" << std::endl;
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}


double calcDeterminante(const std::array<std::array<double, 3>, 3>& matrix) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
         - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
         + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

std::mt19937 g_randNum{std::random_device{}()};

double zufallZahl(const double startWert, const double endWert) {
    std::uniform_real_distribution<double> zahl{startWert, endWert};
    return zahl(g_randNum);
}

void initMatrix(std::array<std::array<double, 3>, 3>& matrix, const double startWert, const double endWert) {
    for (auto& row : matrix) {
        for (auto& element : row) {
            element = zufallZahl(startWert, endWert);
        }
    }
}
#endif //DETERMINANTE_H
