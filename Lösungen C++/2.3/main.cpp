#include <array>
#include <iostream>
#include <algorithm>

namespace Terminplaner {

    struct Datum {
        int m_tag{};
        int m_monat{};
        int m_year{};

        Datum(const int tag = 1, const int monat = 1, const int year = 2000)
            : m_tag{tag}, m_monat{monat}, m_year{year} {}
    };

    struct Uhrzeit {
        int m_stunde{};
        int m_minute{};

        Uhrzeit(const int stunde = 0, const int minute = 0)
            : m_stunde{stunde}, m_minute{minute} {
        }
    };


    struct Termin {
        Datum m_datum;
        Uhrzeit m_uhrzeit;

        // Konstruktor
        Termin(const Datum& datum, const Uhrzeit& uhrzeit) :
        m_datum{datum}, m_uhrzeit{uhrzeit} {}

        // Standardkonstruktor
        Termin() : m_datum{}, m_uhrzeit{} {}

        // Operator Overloading -> benötigen wir für unsere Vergleichsoperationen
        bool operator<(const Termin &other) const {
            if (m_datum.m_year != other.m_datum.m_year)
                return m_datum.m_year < other.m_datum.m_year;
            if (m_datum.m_monat != other.m_datum.m_monat)
                return m_datum.m_monat < other.m_datum.m_monat;
            if (m_datum.m_tag != other.m_datum.m_tag)
                return m_datum.m_tag < other.m_datum.m_tag;
            if (m_uhrzeit.m_stunde != other.m_uhrzeit.m_stunde)
                return m_uhrzeit.m_stunde < other.m_uhrzeit.m_stunde;
            return m_uhrzeit.m_minute < other.m_uhrzeit.m_minute;
        }



    };
    // Hinzuf�gen von Terminen
    template <std::size_t N>
    void addTermine(std::array<Termin, N>& termine) {
        for (int i = 0; i < std::ssize(termine); ++i) {
            int tag{}, monat{}, jahr{}, stunde{}, minute{};
            std::cout << "Termin Nr." << i + 1 << " eingeben:\n";
            std::cout << "Tag (0 zum Abbrechen): ";
            std::cin >> tag;


            if (tag == 0) {
                std::cout << "Termin-Eingabe abgebrochen.\n";
                break;
            }
            std::cout << "Monat: "; std::cin >> monat;
            std::cout << "Jahr: "; std::cin >> jahr;
            std::cout << "Stunde: "; std::cin >> stunde;
            std::cout << "Minute: "; std::cin >> minute;
            std::cout << "--------------------------------------" << std::endl;
            termine[i] = Termin{Datum{tag, monat, jahr}, Uhrzeit{stunde, minute}};
        }
    }

    // Sortieren der Termine
    template <std::size_t N>
    void sortTermine(std::array<Termin, N>& termine) {
        std::sort(termine.begin(), termine.end());
    }

    // Ausgabe der Termine
    template <std::size_t N>
    void printTermine(const std::array<Termin, N>& termine) {
        for (std::size_t i = 0; i < std::ssize(termine); ++i) {
            const auto& termin = termine[i];
            std::cout << "Termin Nr." << i + 1 << ":\n";
            std::cout << "Datum: " << termin.m_datum.m_tag << "."
                      << termin.m_datum.m_monat << "."
                      << termin.m_datum.m_year << "\n";
            std::cout << "Uhrzeit: " << termin.m_uhrzeit.m_stunde << ":"
                      << termin.m_uhrzeit.m_minute << "\n";
            std::cout << "------------------------\n";
        }
    }

}

int main() {
    constexpr std::size_t MAXTERMIN{10};
    std::array<Terminplaner::Termin, MAXTERMIN> termin{};

    Terminplaner::addTermine(termin);
    Terminplaner::sortTermine(termin);
    Terminplaner::printTermine(termin);

    return 0;
}
