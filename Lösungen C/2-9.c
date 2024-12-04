#include <ctype.h>
#include <stdio.h>

/*
Funktion zum Zählen von Groß-/Kleinbuchstaben und Leerzeichen innerhalb einer gegebenen Datei
@param fileName[] Pfad zur auszuwertenden Datei
*/
void count(char fileName[]) {
    FILE *f = fopen(fileName, "r");
    int space = 0, lower = 0, upper = 0;
    char currentChar;

    while ((currentChar = fgetc(f)) != EOF) {
        if (currentChar == ' ') space++;
        else if (islower(currentChar)) lower++;
        else if (isupper(currentChar)) upper++;
    }
    printf("Space: %d, Lower Case: %d, Upper Case: %d\n", space, lower, upper);
    fclose(f);
}

int main() {
    count("TEXT.txt");
}
