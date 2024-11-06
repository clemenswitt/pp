#include <iostream>
#include <cmath>

// Heron-Methode zur Berechnung der Quadratwurzel
// Die zwei letzten Variablen bekommen standartwerte, so können wir unten diese Werte beim Aufruf weglassen,
// aber in anderen Aufruf bspw. auch angeben
double heron(double x, double x_n = 1.0, double t = 1e-10) {
    if (std::abs(x_n * x_n - x) < t) {
        return x_n;
    }
    return heron(x, (x_n + x / x_n) / 2, t);
}

// Für Gleichungen der Form x² + px + q = 0
void pqFormel(const double p, const double q) {
    const double discriminant = (p / 2) * (p / 2) - q;

    if (discriminant < 0) {
        std::cout << "Keine reellen Lösungen (diskriminant < 0).\n";
        return;
    }

    // Berechnung mit Heron
    const double nstHe1 = -(p / 2) + heron(discriminant);
    const double nstHe2 = -(p / 2) - heron(discriminant);
    std::cout << "Berechnung der Nullstellen mit Heron: x1 = " << nstHe1 << ", x2 = " << nstHe2 << "\n";

    // Berechnung mit sqrt aus cmath
    const double nstSq1 = -(p / 2) + std::sqrt(discriminant);
    const double nstSq2 = -(p / 2) - std::sqrt(discriminant);
    std::cout << "Berechnung der Nullstellen mit sqrt (cmath): x1 = " << nstSq1 << ", x2 = " << nstSq2 << "\n";
}

int main() {
    // Achtung das folgende Array erfüllt seine Funktion in unserem Programm ist aber nicht der bevorzugte Weg für Arrays
    // bevorzugt wäre über std::array und std::pair, dies würde aber alle im Folgenden unnötig kompliziert machen
    double testFaelle[][2] = {
        {2.0, -15.0},
        {5.5, -30.6},
        {0.0, 64.0}
    };

    for (const auto& test : testFaelle) {
        double p = test[0];
        double q = test[1];
        std::cout << "\nLöse die Gleichung: x² + " << p << "x + " << q << " = 0\n";
        pqFormel(p, q);
    }

    return 0;
}
