#include <iostream>
#include <vector>
#include <string>
#include <limits>

double getUserInput(const std::string& inputMessage) {
    std::cout << inputMessage;
    double input {};
    std::cin >> input;
    return input;
}

double calcGesamtWiderstand(const std::vector<double>& widerstaende) {
    double gesamtWiderstand {};
    for (double widerstand : widerstaende) {
        if (widerstand != 0) {
            gesamtWiderstand += 1.0 / widerstand;
        }
    }
    return (gesamtWiderstand != 0) ? 1.0 / gesamtWiderstand : std::numeric_limits<double>::infinity();
}

double  chooseUnit() {
    int einheit = static_cast<int>(getUserInput("Waehlen Sie die Einheit fuer die Widerstandswerte:\n1. Ohm\n2. kOhm\n3. MOhm\nAuswahl: "));

    double faktor = 1.0;
    switch (einheit) {
        case 1:
            faktor = 1.0;
            break;        // Ohm
        case 2:
            faktor = 1e3;
            break;        // kOhm
        case 3:
            faktor = 1e6;
            break;        // MOhm
        default:
            std::cerr << "Ungueltige Auswahl\n";
            std::terminate();
    }
    return faktor;
}

int main() {
    std::cout << "Programm zur Berechnung des Gesamtwiderstands einer Parallelschaltung.\n";

    const double einheitsFaktor {chooseUnit()};

    std::vector<double> widerstaende;
    int i {1};
    while (true){
        const double input = getUserInput("Widerstand R" + std::to_string(i) + " in der gewaehlten Einheit: ");
        ++i;
        if(input == 0.0) break;

        widerstaende.push_back(input * einheitsFaktor);

    }

    const double gesamtWiderstand {calcGesamtWiderstand(widerstaende)};

    std::cout << "Der Gesamtwiderstand der Parallelschaltung betraegt: " << gesamtWiderstand << " Ohm\n";

    return 0;
}
