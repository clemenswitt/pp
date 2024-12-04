#include "head.h"
#include <iostream>
#include <array>

namespace Firma {
    std::string getArbeitstype(arbeitstyp arbeitstype) {
        switch (arbeitstype) {
            case Vollzeit:
                return "Vollzeit";
            case Halbzeit:
                return "Halbzeit";
        }
        return "Unknown";
    }


    Mitarbeiter MA_Profil_Anlegen(const int MA_Nummer) {

        // Mitarbeiter zurückgeben
        return getRandomProfil(MA_Nummer);
    }

    void MA_Profil_Anzeigen(const Mitarbeiter &mitarbeiter) {
        std::cout << "Personalnummer: " << mitarbeiter.m_personalnummer << '\n'
        << "Name: " << mitarbeiter.m_name << '\n'
        << "Position: " << mitarbeiter.position << '\n'
        << "Gehalt: " << mitarbeiter.gehalt << '\n'
        <<  "Arbeitstype: " << getArbeitstype(mitarbeiter.arbeitstype) << '\n'
        << "------------------------------\n";
    }

}


int main() {
    constexpr int mitarbeiterAnz{5};

    std::array<Firma::Mitarbeiter, mitarbeiterAnz>  Stammdaten;

    for (int i = 0; i < mitarbeiterAnz; i++) {
        Stammdaten[i] = Firma::MA_Profil_Anlegen(i);
    }
    for(auto &element : Stammdaten) {
        Firma::MA_Profil_Anzeigen(element);
    }
}
