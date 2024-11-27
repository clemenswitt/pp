#include <iostream>
#include <limits>

struct Bruch {
    double m_zaehler;
    double m_nenner;

    Bruch(const double zaehler,const double nenner)
    : m_zaehler{zaehler}, m_nenner{nenner} {

    }
};
//Im Vergleich zu 2.1 eine andere Weise, wie man den Input handeln könnte
Bruch getInputBruch(const std::string_view inputMessage) {
    double zaehler{};
    double nenner{};

    std::cout << inputMessage << '\n';
    std::cout << "Zaehler: ";
    std::cin >> zaehler;
    std::cout << "Nenner: ";
    std::cin >> nenner;

    return Bruch{zaehler,nenner};
}

//Wie übergeben unseren struct datentyp als referenz -> muss nicht erneut erstellt werden
Bruch multiBruch(const Bruch& bruch1, const Bruch& bruch2)
{
    return {bruch1.m_zaehler*bruch2.m_zaehler,
    bruch1.m_nenner*bruch2.m_nenner};
}

int main() {
    Bruch bruch1 = getInputBruch("Geben Sie Bruch 1 ein  (Format: Zaehler Nenner): ");

    Bruch bruch2 = getInputBruch("Geben Sie Bruch 2 ein  (Format: Zaehler Nenner): ");

    Bruch ergebnis = multiBruch(bruch1, bruch2);

    std::cout << "Das Ergebnis der Multiplikation ist: "
              << ergebnis.m_zaehler << "/" << ergebnis.m_nenner << '\n';

    return 0;
}
