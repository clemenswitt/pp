#include <iostream>
#include <cmath> // Für Vergleichsfunktionen

constexpr int g_anzahlGlieder {10};
constexpr double eps {1e-6}; // Genauigkeit für Abbruch

// Berechnung der Fakultät
int fakultaet(const int n) {
    if (n <= 1)
        return 1;
    return n * fakultaet(n - 1);
}

double Expo(const double x) {
    double summe {0.0}, term {1.0};
    for (int i = 0; i <= g_anzahlGlieder && std::abs(term) > eps; i++) {
        summe += term;
        term *= x / (i + 1);
    }
    return summe;
}

double Sin(const double x) {
    double summe {0.0}, term {x};
    for (int i = 0; i <= g_anzahlGlieder && std::abs(term) > eps; i++) {
        summe += (i % 2 == 0 ? 1 : -1) * term;
        term *= x * x / ((2 * i + 2) * (2 * i + 3));
    }
    return summe;
}

double Cos(const double x) {
    double summe {0.0}, term {1.0};
    for (int i = 0; i <= g_anzahlGlieder && std::abs(term) > eps; i++) {
        summe += (i % 2 == 0 ? 1 : -1) * term;
        term *= x * x / ((2 * i + 1) * (2 * i + 2));
    }
    return summe;
}

double Log(const double x) {
    double summe {0.0}, term {x};
    for (int i = 1; i <= g_anzahlGlieder && std::abs(term) > eps; i++) {
        summe += (i % 2 == 0 ? -1 : 1) * term / i;
        term *= x;
    }
    return summe;
}

double Wurzel(const double x) {
    double term {1.0}, result {1.0}, power {(x - 1) / x};
    for (int i = 1; i <= g_anzahlGlieder && std::abs(term) > eps; ++i) {
        term *= (0.5 - (i - 1)) / i;
        result += term * power;
        power *= (x - 1) / x;
    }
    return result * x;
}

int main() {
    const double pi {3.141592653589793};

    std::cout << "Exponential Approximation: " << Expo(2) << " | Exact: " << exp(2) << "\n";
    std::cout << "Sin Approximation: " << Sin(pi) << " | Exact: " << sin(pi) << "\n";
    std::cout << "Cos Approximation: " << Cos(pi / 3) << " | Exact: " << cos(pi / 3) << "\n";
    std::cout << "Log Approximation: " << Log(0.85) << " | Exact: " << log(1 + 0.85) << "\n";
    std::cout << "Sqrt Approximation: " << Wurzel(1.35) << " | Exact: " << sqrt(1.35) << "\n";

    return 0;
}
