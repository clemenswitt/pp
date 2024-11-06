#include <iostream>
#include "Random.h" //wird f�r alle folgenden Random Numbers benutzt
//Wie alles mit Random.h funktioniert ist in der Random.h Datei aufzufinden


int Wuerfel() {
    //Erstellen eine lokale Variable, dies ist unser reusable random Number Generator
    std::uniform_int_distribution<int> wuerfel {1, 6};
    return wuerfel(Random::mt);
}

int main() {
    int zufallszahl {0};
    //Fu�gesteuerte Schleife, diese wird einmal durchlaufen, bevor die Bedingung gepr�ft wird
    do {
        zufallszahl = Wuerfel();
        std::cout << zufallszahl << "\n";
    } while (zufallszahl != 4);

    return 0;
}
