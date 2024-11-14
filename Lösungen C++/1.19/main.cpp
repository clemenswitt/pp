#include <iostream>
#include <iomanip>
#include <string_view>

void print(const double masse, const double kraftErde, const double kraftMond, const double kraftMars, const std::string_view fromUnit, const std::string_view toUnit) {
    static bool headerPrinted {false};
    if (!headerPrinted) {
        std::cout << "Nr. | Wert-Angabe (" << fromUnit << ") | Kraft auf Erde (" << toUnit << ") | Kraft auf Mond (N) | Kraft auf Mars (N)\n";
        std::cout << "----------------------------------------------------------------------------------------\n";
        headerPrinted = true;
    }
    static int id {0};
    std::cout << std::setw(4) << ++id << " | " << std::setw(19) << masse << " | " << std::setw(13) << kraftErde << " | " << std::setw(13) << kraftMond << " | " << std::setw(13) << kraftMars << "\n";
}

void calcForcePlanet(const double beschleunigungErde, const double beschleunigungMond, const double beschleunigungMars) {
    for (int masse {0}; masse <= 500; masse += 5) {
        const double kraftErde = beschleunigungErde * masse; // Gewicht auf der Erde
        const double kraftMond = beschleunigungMond * masse; // Gewicht auf dem Mond
        const double kraftMars = beschleunigungMars * masse; // Gewicht auf dem Mars
        print(masse, kraftErde, kraftMond, kraftMars, "kg", "N");
    }
}

int main() {
    constexpr  double G_ERDE = 9.81;    // Erdbeschleunigung in m/s²
    constexpr double G_MOND = 1.62;     // Mondbeschleunigung in m/s²
    constexpr double G_MARS = 3.69;     // Marsbeschleunigung in m/s

    calcForcePlanet(G_ERDE, G_MOND, G_MARS);
    return 0;
}
