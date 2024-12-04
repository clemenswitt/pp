//
// Created by tonih on 14.11.2024.
//

#ifndef HEAD_H
#define HEAD_H

#include <string>
#include <random>

namespace Firma {
    enum arbeitstyp {
        Vollzeit,
        Halbzeit
    };
    std::string getArbeitstype(arbeitstyp arbeitstype);

    struct Mitarbeiter {
        int m_personalnummer;
        std::string m_name;
        int position;
        double gehalt;
        arbeitstyp arbeitstype;
    };
    //damit wir ein randomProfil erstellen, für das Verständnis der Aufgabe nicht nötig
    Mitarbeiter getRandomProfil(int MA_Nummer) {
        // Zufallsgenerator initialisieren
        std::random_device rd;
        std::mt19937 gen(rd());

        // Zufälligen Namen generieren
        std::vector<std::string> namen = {"Alice", "Bob", "Charlie", "Diana", "Eve"};
        std::uniform_int_distribution<> name_dist(0, namen.size() - 1);
        std::string randomName = namen[name_dist(gen)];

        // Zufällige Position generieren
        std::uniform_int_distribution<> position_dist(1, 10); // Beispiel: 1 bis 10
        int randomPosition = position_dist(gen);

        // Zufälliges Gehalt generieren
        std::uniform_real_distribution<> gehalt_dist(30000.0, 120000.0); // Beispiel: Gehalt zwischen 30k und 120k
        double randomGehalt = gehalt_dist(gen);

        // Zufälligen Arbeitstyp generieren
        std::uniform_int_distribution<> typ_dist(0, 1); // Vollzeit, Teilzeit
        arbeitstyp randomTyp = static_cast<arbeitstyp>(typ_dist(gen));

        return {MA_Nummer, randomName, randomPosition, randomGehalt, randomTyp};
    }

    Mitarbeiter MA_Profil_Anlegen(const int MA_Nummer);

    void MA_Profil_Anzeigen(const Mitarbeiter &mitarbeiter);

}
#endif //HEAD_H
