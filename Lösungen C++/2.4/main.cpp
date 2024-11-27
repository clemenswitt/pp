// main.cpp
#include <iostream>
#include <array>
#include "Klasse.h"

int main() {
    std::array<Klasse::Schueler, Klasse::MAXSTUDENTS> schuelerArray {};
    size_t anzahl {0};

    int wahl;
    std::cout << "Entscheiden Sie nach welchem Kriterium sotiert werden soll 1 fuer ID oder 2 fuer Durchschnitt: \nIhre Auswahl: ";
    std::cin >> wahl;
    const Klasse::SortierKriterium sortierkriterium = (wahl == 1)
                                                          ? Klasse::SortierKriterium::ID
                                                          : Klasse::SortierKriterium::Durchschnitt;

    while (true) {
        eingabeSchueler(schuelerArray, anzahl, sortierkriterium);
        ausgabeSchueler(schuelerArray, anzahl);
        std::cout << "1. Fügen Sie einen Schueler hinzu oder terminieren Sie mit 0:\n";
        std::cin >> wahl;
        if (wahl == 0) break;
    }
    std::cout << "Programm beendet";
    return 0;
}
