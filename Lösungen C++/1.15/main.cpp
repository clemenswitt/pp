#include <iostream>
#include <iomanip> // für std::setw

//Unsere Umrechnung festgelegt als constexpr um diese zur compile-Time
constexpr double ZOLL_IN_CM {2.54};
constexpr double FUSS_IN_DM {3.048};
constexpr double YARD_IN_METER {0.9144};
constexpr double MEILE_IN_KM {1.60934};
constexpr double OUNCES_IN_GRAMM {28.3495};
constexpr double PFUND_IN_KG {0.453592};

//Umrechnungsfunktionen (mit const eingabeparametern):
double zollInCm(const double zoll) {
    return zoll * ZOLL_IN_CM;
}

double fussInDm(const double fuss) {
    return fuss * FUSS_IN_DM;
}

double yardInMeter(const double yard) {
    return yard * YARD_IN_METER;
}

double meileInKm(const double meile) {
    return meile * MEILE_IN_KM;
}

double ouncesInGramm(const double ounces) {
    return ounces * OUNCES_IN_GRAMM;
}

double pfundInKg(const double pfund) {
    return pfund * PFUND_IN_KG;
}

//Template Funktion, damit der User eine int oder double eingabe tätigen kann
//Template -> heißt der Datentyp für T ist hier "frei"
//Der Compiler erstellt dann nach unserer Vorlage(Template) diese Funktion mit dem passenden Datentyp (Wie das funktioniert sieht man unten beim Aufruf)
template <typename T>
T getUserEingabe(const std::string_view inputMessage) {
    std::cout << inputMessage;

    //Hier ist jetzt T den wir oben im template definiert haben unser Datentyp
    T userinput{};
    std::cin >> userinput;

    return userinput;
}

// Funktion zur Erstellung der Tabelle
void print(const double unconvertedVal, const double convertedVal, const std::string& fromUnit, const std::string& toUnit) {
    static bool headerPrinted {false};
    //Checken ob unserer Header nicht schon erstellt wurde -> static ist hier vorteilhaft
    if (!headerPrinted) {
        std::cout << "Nr. | Wert-Angabe (" << fromUnit << ") | Wert-Angabe (" << toUnit << ")\n";
        headerPrinted = true;
    }
    static int id {0};
    //Achtung: Hier wird direkt im String id um 1 erhöht je Aufruf
    std::cout << std::setw(4) << ++id << " | " << std::setw(19) << unconvertedVal << " | " << std::setw(13) << convertedVal << "\n";
}

// Dynamische Eingabeaufforderung basierend auf der gewählten Umrechnung
void Auswahl(const int auswahl) {
    //Switch Statement zur 1. Auswahl der Umrechnung
    std::string einheit;
    switch (auswahl) {
        case 1: einheit = "Zoll"; break;
        case 2: einheit = "Fuß"; break;
        case 3: einheit = "Yard"; break;
        case 4: einheit = "Meilen"; break;
        case 5: einheit = "Ounces"; break;
        case 6: einheit = "Pfund"; break;
        default: einheit = "nichtmetrische Zahl"; break;
    }


    while (true) {
        //Hier wird die template Funktion getUserEingabe mit T als double durch den Aufruf erzeugt
        //der Datentyp in den <> zeigt an, welchen Datentyp T in unserem Template hat
        const double nichtMetrischeEingabe {getUserEingabe<double>("Geben Sie die " + einheit + " ein (0 um zurückzukehren): ")};

        if (nichtMetrischeEingabe == 0) {
            std::cout << "Zurück zur Hauptauswahl.\n";
            break;
        }

        switch (auswahl) {
            case 1:
                print(nichtMetrischeEingabe, zollInCm(nichtMetrischeEingabe), "Zoll", "cm");
                break;
            case 2:
                print(nichtMetrischeEingabe, fussInDm(nichtMetrischeEingabe), "Fuß", "dm");
                break;
            case 3:
                print(nichtMetrischeEingabe, yardInMeter(nichtMetrischeEingabe), "Yard", "Meter");
                break;
            case 4:
                print(nichtMetrischeEingabe, meileInKm(nichtMetrischeEingabe), "Meilen", "km");
                break;
            case 5:
                print(nichtMetrischeEingabe, ouncesInGramm(nichtMetrischeEingabe), "Ounces", "Gramm");
                break;
            case 6:
                print(nichtMetrischeEingabe, pfundInKg(nichtMetrischeEingabe), "Pfund", "kg");
                break;
            default:
                std::cout << "Ungültige Auswahl!" << std::endl;
                break;
        }
    }
}


int main() {
    while (true) {
        const int userAuswahl{
            //Hier wird die template Funktion getUserEingabe mit T als int durch den Aufruf erzeugt, dies ist nicht die gleiche Funktion wie getUserEingabe oben
            getUserEingabe<int>(
                //Wir übergeben der Funktion einen Raw String Literal, also den String wie er im folgenden formatiert ist (mit allen Zeilenumbrüchen usw.)
                R"( Welche der folgenden Umrechnungen soll durchgeführt werden? Geben Sie die Zahl der jeweiligen Umrechnung ein:
1) Zoll in cm
2) Fuß in dm
3) Yard in Meter
4) Meile in km
5) Ounces in Gramm
6) Pfund (lbs) in kg
0) Programm beenden
Auswahl: )")
        };

        if (userAuswahl == 0) {
            std::cout << "Programm wird beendet." << std::endl;
            break;
        }

        if (userAuswahl >= 1 && userAuswahl <= 6) {
            Auswahl(userAuswahl);
        } else {
            std::cout << "Ungültige Auswahl! Bitte wählen Sie eine Zahl zwischen 0 und 6." << std::endl;
        }
    }
    return 0;
}
