#include <iostream>
#include <string_view>

double getUserInput(std::string_view inputMessage) {
    std::cout << inputMessage;
    double input{};
    std::cin >> input;
    return input;
}

bool bKonstruierbar(double a, double b, double c) {
    return (a < b + c && b < a + c && c < a + b);
}


bool bGleichseitig(double a, double b, double c) {
    return (a == b && b == c);
}

//std::abs gibt uns ein double type für den Betrag des Eingabeparameters zurück
// wir müssen hier etwas tricksen, denn unsere datentypen sind nicht 100% genau, da diese nur einen festen Speicher besitzen
// d.h. da ein double nur 8 Byte groß ist kann die Gleitkommadarstellung nicht alle Zahlen genau darstellen
//Wir arbeiten hier deshalb mit einer Annäherung, welche allerdings für unser Beispiel ausreichen sein sollte
bool bRechtwinkligkeit(double a, double b, double c) {
    if (std::abs(a * a - (b * b + c * c)) < 1e-6 ||
        std::abs(b * b - (a * a + c * c)) < 1e-6 ||
        std::abs(c * c - (a * a + b * b)) < 1e-6) {
        return true;
        }
    return false;
}


int main() {

    const double uInput1{ getUserInput("Bitte geben Sie die L?nge von Seite 1 ein: ") };
    const double uInput2{ getUserInput("Bitte geben Sie die L?nge von Seite 2 ein: ") };
    const double uInput3{ getUserInput("Bitte geben Sie die L?nge von Seite 3 ein: ") };


    if (bKonstruierbar(uInput1, uInput2, uInput3)) {
        std::cout << "Das Dreieck ist konstruierbar.\n";

        if (bGleichseitig(uInput1, uInput2, uInput3)) {
            std::cout << "Das Dreieck ist gleichseitig.\n";
        }


        if (bRechtwinkligkeit(uInput1, uInput2, uInput3)) {
            std::cout << "Das Dreieck ist rechtwinklig.\n";
        }

    }
    else {
        std::cout << "Das Dreieck ist nicht konstruierbar.\n";
    }

    return 0;
}