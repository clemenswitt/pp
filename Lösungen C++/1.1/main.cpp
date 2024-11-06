#include <iostream>
#include <string_view>

//Input Funktion, diese nimmt eine string_view als Eingabeparameter
//inputMessage -> string_view Objekt, welches nur betrachtet("viewed") werden kann, aber nicht bearbeitet werden kann
//Hier benutzt, da dies für eine bessere Performance sorgt, ein normaler String wäre über std::string, dieser kann bearbeitet werden
int getUserInput(const std::string_view inputMessage)
{
    //std::cout = unsere Ausgabefunktion von cpp
    // << ist der Operator für die Ausgabe für die Standard-Datentypen, dieser lässt auch Kettenbildung zu
    std::cout << inputMessage;
    //Variablen werden über {} initialisiert, Variablen können auch über = initialisiert werden, die hat allerdings mehrere Nachteile (weniger effizient, weniger Sicher, funktioniert nicht bei Arrays)
    int input{};
    //std::cin = unsere Inputfunktion von cpp
    // >> ist der Operator für die Eingabe, gibt ein istream Objekt zurück, welches hier als int impliziert konvertiert wird
    std::cin >> input;

    return input;
}

//Alle Parameter, welche nicht in der Funktion verändert werden, sollten const sein, damit es zu keinen ungewünschten Änderungen durch Aufrufe kommt
int getMinNumber(const int num1, const int num2, const int num3)
{
    // && ist unsere and Verknüpfung
    if (num1 < num2 && num1 < num3)
        return num1;
    else if (num2 < num3 && num2 < num1)
        return num2;
    else
        return num3;
}

int main()
{

    const int uInput1{ getUserInput("Bitte geben Sie Zahl 1 ein: ") };
    const int uInput2{ getUserInput("Bitte geben Sie Zahl 2 ein: ") };
    const int uInput3{ getUserInput("Bitte geben Sie Zahl 3 ein: ") };

    std::cout << "Die kleinste Zahl ist: " << getMinNumber(uInput1, uInput2, uInput3);

    return 0;
}
