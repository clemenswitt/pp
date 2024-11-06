#include <iostream>


int getUserInput(const std::string_view inputMessage) {
    std::cout << inputMessage;
    int userInput {};

    std::cin >> userInput;

    //Folgende Kontrollstruktur ergibt sich nach der Aufgabenstellung
    if(userInput < 1 || userInput > 100) {
        std::terminate();
    }
    return userInput;
}

std::string getMark(const int punkte) {
    if (punkte >= 97) {
        return "Sehr gut";
    } else if (punkte >= 76) {
        return "Gut";
    } else if (punkte >= 61) {
        return "Befriedigend";
    } else if (punkte >= 50) {
        return "Ausreichend";
    } else {
        return "Ungenügend";
    }
}


int main()
{
    while (true) {

        const int inputPunkte {getUserInput("Bitte geben Sie die erreichten Punkte ein: ")};

        //unsere eingabe 1 terminiert hier das Programm, da durch das break, die while(true) hier verlassen wird
        if (inputPunkte == -1)
            break;

        std::cout << "Der Student hat mit einer Bewertung von " << inputPunkte << " und damit die Leistung: "
        << getMark(inputPunkte) << " erzielt!\n";

    }
}
