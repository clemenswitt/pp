#include <iostream>
#include <array>
#include <string>

namespace Firma {
    constexpr int maxMitarbeiter {30};

    struct Mitarbeiter {
        std::string name;
        std::string vorname;
        std::string telefonnummer;
        int zimmernummer;
        int personalnummer;
    };
}

void addMitarbeiter(std::array<Firma::Mitarbeiter, Firma::maxMitarbeiter>& liste, int& anzahl) {
    if (anzahl >= Firma::maxMitarbeiter) {
        std::cout << "Das Telefonverzeichnis ist voll.\n";
        return;
    }

    Firma::Mitarbeiter neuerMitarbeiter;
    std::cout << "Name: ";
    std::cin >> neuerMitarbeiter.name;
    std::cout << "Vorname: ";
    std::cin >> neuerMitarbeiter.vorname;
    std::cout << "Telefonnummer: ";
    std::cin >> neuerMitarbeiter.telefonnummer;
    std::cout << "Zimmernummer: ";
    std::cin >> neuerMitarbeiter.zimmernummer;
    std::cout << "Personalnummer: ";
    std::cin >> neuerMitarbeiter.personalnummer;

    liste[anzahl] = neuerMitarbeiter;
    ++anzahl;
    std::cout << "Mitarbeiter hinzugef�gt.\n";
}

void delMitarbeiter(std::array<Firma::Mitarbeiter, Firma::maxMitarbeiter>& liste, int& anzahl, int personalnummer) {
    bool gefunden = false;
    for (int i = 0; i < anzahl; ++i) {
        if (liste[i].personalnummer == personalnummer) {
            for (int j = i; j < anzahl - 1; ++j) {
                liste[j] = liste[j + 1];
            }
            --anzahl;
            gefunden = true;
            std::cout << "Mitarbeiter entfernt.\n";
            break;
        }
    }
    if (!gefunden) {
        std::cout << "Mitarbeiter mit der Personalnummer " << personalnummer << " nicht gefunden.\n";
    }
}

void printMitarbeiter(const std::array<Firma::Mitarbeiter, Firma::maxMitarbeiter>& liste, int anzahl) {
    if (anzahl == 0) {
        std::cout << "Keine Mitarbeiter im Verzeichnis.\n";
        return;
    }

    for (int i = 0; i < anzahl; ++i) {
        std::cout << "Name: " << liste[i].name
                  << ", Vorname: " << liste[i].vorname
                  << ", Telefonnummer: " << liste[i].telefonnummer
                  << ", Zimmernummer: " << liste[i].zimmernummer
                  << ", Personalnummer: " << liste[i].personalnummer << '\n';
    }
}

int main() {
    std::array<Firma::Mitarbeiter, Firma::maxMitarbeiter> mitarbeiterListe;
    int aktuelleAnzahl = 0;
    int wahl = 0;

    while (true) {
        std::cout << "----------------------------------" << std::endl;
        std::cout << "1. Mitarbeiter hinzufuegen\n2. Alle Mitarbeiter anzeigen\n3. Mitarbeiter entfernen\n4. Beenden\n";
        std::cout << "----------------------------------\nIhre Wahl: ";
        std::cin >> wahl;

        switch (wahl) {
            case 1:
                addMitarbeiter(mitarbeiterListe, aktuelleAnzahl);
                break;
            case 2:
                printMitarbeiter(mitarbeiterListe, aktuelleAnzahl);
                break;
            case 3: {
                int personalnummer;
                std::cout << "Personalnummer des zu entfernenden Mitarbeiters: ";
                std::cin >> personalnummer;
                delMitarbeiter(mitarbeiterListe, aktuelleAnzahl, personalnummer);
                break;
            }
            case 4:
                return 0;
            default:
                std::cout << "Ungueltige Auswahl. Bitte erneut versuchen.\n";
        }
    }

    return 0;
}