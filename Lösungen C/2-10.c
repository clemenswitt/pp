#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    char surname[100];
    char phone[100];
    char country[100];
} Person;

Person* parseCSVLineToPerson(char* line) {
    Person* person = (Person*) malloc(sizeof(Person));
    char* token = strtok(line, ";");
    if (token) strcpy(person->name, token);
    token = strtok(NULL, ";");
    if (token) strcpy(person->surname, token);
    token = strtok(NULL, ";");
    if (token) strcpy(person->phone, token);
    token = strtok(NULL, ";");
    if (token) strcpy(person->country, token);
    return person;
}

void printPerson(Person *person) {
    printf("    <PERSON>\n");
    printf("        <NAME>%s</NAME>\n", person->name);
    printf("        <VORNAME>%s</VORNAME>\n", person->surname);
    printf("        <TELEFON>%s</TELEFON>\n", person->phone);
    printf("        <LAND>%s</LAND>\n", person->country);
    printf("    </PERSON>\n");
}

int main() {
    FILE* f = fopen("Resources/PERSONS.csv", "r");
    printf("<PERSONS>\n");
    char line[1000];
    while(fgets(line, sizeof(line), f)) {
        line[strcspn(line, "\n")] = '\0'; // Zeilenumbrüche entfernen
        printPerson(parseCSVLineToPerson(line));
    }
    printf("</PERSONS>\n");
    fclose(f);
}
