#include <stdio.h>

/*
Main-Funktion
Das Programm öffnet die angegebene Textdatei im Lesemodus ("r") und liest sie zeilenweise ein, wobei pro Zeile maximal 30 Zeichen plus ein Nullterminierungszeichen (`\0`) eingelesen werden.
Die Funktion `fgets()` wird dafür mit dem Argument (30 + 1) aufgerufen, um sicherzustellen, dass das Nullterminierungszeichen ausreichend Platz im Puffer hat.

Nach dem Einlesen einer Zeile wird ein Pointer `tmp` erzeugt, der um 3 Zeichen von der Speicheradresse des Puffers `line` verschoben ist. Dieser Pointer zeigt auf die Zeichen ab dem vierten Zeichen der aktuellen Zeile.
Die verbleibende Zeichenkette wird anschließend auf dem Bildschirm ausgegeben.

Auf diese Weise entfernt das Programm die ersten drei Zeichen jeder Zeile und gibt die restlichen Zeichen der Datei aus.
*/
int main() {
    FILE *f = fopen("Resources/MY_FRIENDS.txt", "r");
    int index = 0;
    char line[30+1];

    if (f == NULL) {
        printf("Fehler beim Lesen der Datei.");
        return 0;
    }

    while(fgets(line, (30+1), f) != NULL) {
        char *tmp = line + 3;
        printf("%s", tmp);
        index ++;
    }
    printf("Datei beinhaltet %d Zeilen!\n", index);
	fclose(f);
}
