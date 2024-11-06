#include <iostream>
#include <iomanip>
#include <string>
#include <map>

// Umrechnungsfaktoren als constexpr für Compile-Time
constexpr double ZOLL_IN_CM {2.54};
constexpr double FUSS_IN_DM {3.048};
constexpr double YARD_IN_METER {0.9144};
constexpr double MEILE_IN_KM {1.60934};
constexpr double OUNCES_IN_GRAMM {28.3495};
constexpr double PFUND_IN_KG {0.453592};

// Auswahl in einem enum | Enum = unserer eigener Datentyp | class ist hier für stärkere Typisierung und Einschränkung des Scopes
// Deshalb unten auch nur den Aufruf über ConversionOption::[Wert]
enum class ConversionOption {
    EXIT = 0,
    ZOLL_TO_CM = 1,
    FUSS_TO_DM,
    YARD_TO_METER,
    MEILE_TO_KM,
    OUNCES_TO_GRAMM,
    PFUND_TO_KG,
    INVALID
};

// Erstellen eine Map, vergleichbar mit einem Dictionary in Python
//Key: Ein ConversionOption-Wert
//Value: std::pair = Paar aus 1. einem String für die Bezeichnung der Umrechnung 2. double Variable mit dem Umrechnungsfaktor
const std::map<ConversionOption, std::pair<std::string, double>> conversionMap {
    {ConversionOption::ZOLL_TO_CM, {"Zoll", ZOLL_IN_CM}},
    {ConversionOption::FUSS_TO_DM, {"Fuß", FUSS_IN_DM}},
    {ConversionOption::YARD_TO_METER, {"Yard", YARD_IN_METER}},
    {ConversionOption::MEILE_TO_KM, {"Meilen", MEILE_IN_KM}},
    {ConversionOption::OUNCES_TO_GRAMM, {"Ounces", OUNCES_IN_GRAMM}},
    {ConversionOption::PFUND_TO_KG, {"Pfund", PFUND_IN_KG}},
};

//Template Funktion, damit der User eine int oder double eingabe tätigen kann
//Template -> heißt der Datentyp für T ist hier "frei"
template <typename T>
T getUserEingabe(const std::string& inputMessage) {
    std::cout << inputMessage;
    T userInput{};
    std::cin >> userInput;
    return userInput;
}

// im Vgl. zum Projekt 1_15 brauchen wir nun nur eine Umrechnungsfunktion
double umrechnung(const double value, const double umrechnungsfaktor) {
    return value * umrechnungsfaktor;
}

// Tabelle für die Ausgabe
void print(const double unconvertedVal, const double convertedVal, const std::string& fromUnit, const std::string& toUnit) {
    static bool headerPrinted {false};
    if (!headerPrinted) {
        std::cout << "Nr. | Wert-Angabe (" << fromUnit << ") | Wert-Angabe (" << toUnit << ")\n";
        headerPrinted = true;
    }
    static int id {0};
    std::cout << std::setw(4) << ++id << " | " << std::setw(19) << unconvertedVal << " | " << std::setw(13) << convertedVal << "\n";
}

void Auswahl(const ConversionOption option) {
    //Funktion [map-Objekt].find ist über
    //"This function takes a key and tries to locate the element with which the key matches.
    //If successful the function returns a constant iterator pointing to the sought after %pair" definiert
    //auto schreibt der it variable den korrekten Typ zu, also "constant iterator pointing"
    const auto it = conversionMap.find(option);
    if (it == conversionMap.end()) {
        std::cout << "Ungültige Auswahl!\n";
        return;
    }

    //Da it ein "constant iterator pointing" ist müssen wir diesen bspw. so behandeln: (*[constant iterator pointing]).first dies
    //lässt sich aber durch -> vereinfachen, also -> = (*).
    const std::string& einheit = it->second.first;
    const double factor = it->second.second;

    while (true) {
        const auto unconvertedVal = getUserEingabe<double>("Geben Sie die " + einheit + " ein (0 um zurückzukehren): ");
        if (unconvertedVal == 0) {
            std::cout << "Zurück zur Hauptauswahl.\n";
            break;
        }
        print(unconvertedVal, umrechnung(unconvertedVal, factor), einheit, einheit == "Meilen" ? "km" : "Meter");
    }
}

int main() {
    while (true) {
        //User gibt eine Zahl ein:
        const int userChoice = getUserEingabe<int>(
            R"(Welche der folgenden Umrechnungen soll durchgeführt werden? Geben Sie die Zahl der jeweiligen Umrechnung ein:
1) Zoll in cm
2) Fuß in dm
3) Yard in Meter
4) Meile in km
5) Ounces in Gramm
6) Pfund (lbs) in kg
0) Programm beenden
Auswahl: )"
        );
        //Diese Zahl konvertieren wir in unserem Enum, dies erfolgt dadurch, dass dem Enum eine Zahl explizit zugewiesen werden kann
        //Da wir unseren daten als "enum class" erstellt haben, müssen wir diesen casten, da implizierte conversion nicht verfügbar ist
        auto option = static_cast<ConversionOption>(userChoice);

        if (option == ConversionOption::EXIT) {
            std::cout << "Programm wird beendet.\n";
            break;
        }
        //Schauen mithilfe der Map-Memberfunktion (Class-Methode) ob die ausgewählte Option in unserer Map ist
        if (conversionMap.contains(option)) {
            Auswahl(option);
        } else {
            std::cout << "Ungültige Auswahl! Bitte wählen Sie eine Zahl zwischen 0 und 6.\n";
        }
    }
    return 0;
}
