#include <iostream>
#include <iomanip> //für std::stw

double getUserEingabe(const std::string_view inputMessage) {
    std::cout << inputMessage;

    double userinput{};
    std::cin >> userinput;

    return userinput;
}

constexpr double convertToKmh(const double knoten) {
    constexpr double umrechnungsconst {1.852};
    return knoten * umrechnungsconst;
}

void print(const double knoten) {
    //static variable, static gibt an, dass diese Variable nur beim ersten mal ausführen dieser Anweise erstellt wird, so wird id nicht jedes mal auf 0 gestellt
    //sondern kann benutzt werden um die Id's zu tracken
    static int id {0};
    if (id == 0) {
        std::cout << "Nr. | Wert-Angabe in [kt] | Angabe in [kmh]" << "\n";
    }
    //std::setw = Manipulator für das folgende ostream-Objekt, welches die Breite in der Ausgabe festlegt, wenn das Objekt nicht breit genug ist werden
    //Leerzeichen zum Auffüllen verwendet
    std::cout << std::setw(4) << ++id << " | " << std::setw(19) << knoten << " | " << std::setw(13) << convertToKmh(knoten) << "\n";
}

int main() {
    while (true) {
        const double KnotenEingabe{
            getUserEingabe(
                "Bitte geben sie die Geschwindigkeitn in Knoten ein: ")
        };

        if (KnotenEingabe == 0) {
            std::cout << "Programm wird terminiert";
            break;
        }

        print(KnotenEingabe);

    }
    return 0;
}
