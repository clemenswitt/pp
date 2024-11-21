#include <stdio.h>
#include <stdlib.h>

int main(void) {


    printf("Geben Sie eine Ziffernfolge zwischen 12345 und 29876 ein: \n");
    char input[6]; //6, da wir 5 Zeichen und eine Nullterminierung einlesen
    char *endptr; //ptr für Fehlerprüfung
    scanf("%s", &input);

    const int number = atoi(input);
    if (number < 12345 || number > 29876) {
        printf("Die eingegebene Zahl liegt nicht im Bereich 12345 bis 29876.\n");
        return 1;
    }
    //da input ein char ist, welcher einen int (in Ascii) repräsentiert liegt hier das Problem
    //die korrekte Umwandlung von Ascii in den tatsächlichen Int, dies kann entweder über '0' oder
    //Äquivalent mit 48
    printf("1. Ziffer: %d\n", (int)input[0]-48);

    printf("3. Ziffer: %d\n", (int)input[2]-'0');

    printf("Letzte Ziffer: %d\n", input[4] - '0');


    return 0;
}
