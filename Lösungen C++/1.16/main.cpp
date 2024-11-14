#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

constexpr double PI = 3.14159265358979323846;
constexpr double EPSILON = 8.854187817e-12;

double calcCoulombGesetz(double const q1, double const q2, double const r) {
    return q1*q2/(4*PI*EPSILON*r*r);
}

double getUserInput(std::string_view inputMessage) {
    std::cout << inputMessage;

    double input {};
    std::cin >> input;

    return input;
}

std::pair<double, std::string> chooseUnit() {
    std::cout << "Wählen Sie die Einheit für die Ladung:\n";
    std::cout << "1. Coulomb (C)\n";
    std::cout << "2. Mikro-Coulomb (µC)\n";
    std::cout << "3. Milli-Coulomb (mC)\n";
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1: return {1.0, "C"}; // Coulomb
        case 2: return {1e-6, "µC"}; // Mikro-Coulomb
        case 3: return {1e-3, "mC"}; // Milli-Coulomb
        default:
            std::cout << "Ungültige Auswahl, Standard: Coulomb (C)\n";
        return {1.0, "C"};
    }
}

void createTable(const double q1, const double q2, const double r, const double force, const std::string& unit) {
    static int index{0};
    if (index == 0) {
        std::cout << "| Nr. |   q1 in " << unit << "   |   q2 in " << unit << "   |   r in m   |     F in N     |\n";
        std::cout << "---------------------------------------------------------------\n";
    }

    ++index;
    std::cout << "| " << std::setw(3) << index
              << " | " << std::setw(10) << std::scientific << std::setprecision(3) << q1
              << " | " << std::setw(10) << std::scientific << std::setprecision(3) << q2
              << " | " << std::setw(8) << std::fixed << std::setprecision(2) << r
              << " | " << std::setw(12) << std::scientific << std::setprecision(3) << force
              << " |\n";
}

constexpr std::vector<double> generateLogVals(const double rStart, const double rEnd, const int anzSteps) {
    std::vector<double> rVals;

    for (int i = 0; i < anzSteps; ++i) {
        double r = pow(10,log10(rStart) + i * (log10(rEnd) - log10(rStart))/anzSteps);
        rVals.push_back(r);
    }
    return rVals;
}



int main() {

    auto [unitFactor, unit] = chooseUnit();

    const double q1 = getUserInput("Geben Sie q1 an: ") * unitFactor;
    const double q2 = getUserInput("Geben Sie q2 an: ") * unitFactor;

    constexpr double rMin {1.0};
    constexpr double rMax  {100.0};
    constexpr int numSteps {10};

    std::vector<double> rVals { generateLogVals(rMin, rMax, numSteps)};

    for (const double r : rVals) {
        createTable(q1, q2, r, calcCoulombGesetz(q1, q2, r), unit);
    }
}
