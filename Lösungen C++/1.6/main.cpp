#include <iostream>
#include "Random.h"

//Funktion aus Aufgabe 1.3
int Wuerfel() {
    //Erstellen eine lokale Variable, dies ist unser reusable random Number Generator
    std::uniform_int_distribution<int> wuerfel {1, 6};
    return wuerfel(Random::mt);
}

int getUserInput(const std::string_view inputText) {

    int userInput {};
    std::cout << inputText;
    std::cin >> userInput;
    return userInput;
}

int main() {
    int userInput {getUserInput("Bitte geben sie ein wie oft die Zahl 6 gewürfelt werden soll: ")};
    while (userInput != 0) {
        const int zahl = Wuerfel();
        std::cout << "Es wurde gewürfelt: " << zahl << " offene Sechsen: " << userInput << "\n";
        if(zahl == 6) userInput--;
    }
}