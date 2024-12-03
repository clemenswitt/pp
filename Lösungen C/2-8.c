#include <stdio.h>
#include <string.h>

void readLines(char fileName[], char targetChar) {
    FILE *f = fopen(fileName, "r");
    char line[80+1];
    int totalCharCount = 0, targetCharCount = 0;
    while(fgets(line, (80+1), f) != NULL) {
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] != '\n') totalCharCount++;
            if (line[i] == targetChar) targetCharCount++;
        }
    }
    printf("Total Chars: %d, Target Char: %d\n", totalCharCount, targetCharCount);
    fclose(f);
}

void readChars(char fileName[], char targetChar) {
    FILE *f = fopen(fileName, "r");
    int totalCharCount = 0, targetCharCount = 0;
    char currentChar;
    while ((currentChar = fgetc(f)) != EOF) {
        if (currentChar != '\n') totalCharCount++;
        if (currentChar == targetChar) {
            targetCharCount++;
        }
    }
    printf("Total Chars: %d, Target Char: %d\n", totalCharCount, targetCharCount);
    fclose(f);
}

int main() {
    char targetChar;
    printf("Gesuchter Buchstabe: ");
    scanf(" %[^\n]", &targetChar);
    printf("[Zeilenweise Überprüfung] – ");
    readLines("TEXT.txt", 's');
    printf("[Zeichenweise Überprüfung] – ");
    readChars("TEXT.txt", 's');
}
