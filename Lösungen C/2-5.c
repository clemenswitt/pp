#include <stdio.h>

/*
Definition des Structs "Employee"
*/
typedef struct {
    char name[100];
    char surname[100];
    char phoneNumber[15]; // Internationale Maximallänge von Telefonnummern einschl. Ländercode
    char roomNumber[5];
    int id;
} Employee;

/*
Definition des Structs "Phonebook"
*/
typedef struct {
    Employee entries[30];
} Phonebook;

/*
Funktion zur Intitialisierung eines leeren Telefonbuchs
@return phoneBook Instanz des Structs "Phonebook", mit leeren Instanzen des Structs "Employee" initialisiert
*/
Phonebook initPhonebook() {
    Phonebook phoneBook;
    int numEntries = sizeof(phoneBook.entries) / sizeof(phoneBook.entries[0]);
    for (int i = 0; i < numEntries; i++) {
        phoneBook.entries[i] = (Employee) {"", "", "", "", -1}; // --- -> Flag für leere ID
    }
    return phoneBook;
}

/*
Funktion zur Berechnung der Anzahl freier Einträge innerhalb einer Instanz des Structs "Phonebook"
@param phoneBook Zu überprüfende Instanz des Structs "Phonebook"
@return numEntries - entriesOccupied Anzahl freier Einträge in phoneBook
*/
int getNumEntriesAvailable(Phonebook phoneBook) {
    int numEntries = sizeof(phoneBook.entries) / sizeof(phoneBook.entries[0]);
    int entriesOccupied = 0;
    for (int i = 0; i < numEntries; i++) {
        if (phoneBook.entries[i].id == -1) break;
        else entriesOccupied++;
    }
    return numEntries - entriesOccupied;
}

/*
Funktion zur tabellarischen Ausgabe aller Einträge einer Instanz des Structs "Phonebook"
@param phoneBook Instanz des Structs "Phonebook"
@return 0 | 1 Status-Flag der Ausgabe: 1 -> erfolgreiche Ausgabe; 0 -> keine auszugebenden Einträge vorhanden
*/
int printEntries(Phonebook phoneBook) {
    int numEntries = sizeof(phoneBook.entries) / sizeof(phoneBook.entries[0]);
    if (getNumEntriesAvailable(phoneBook) == numEntries) {
        printf("\e[1;1H\e[2J"); // Clear console
        printf("Keine Einträge.\n\n");
        return 0; // 0 -> Error-Flag
    }

    printf("\e[1;1H\e[2J"); // Clear console
    printf("Nr.\tName\tNachname\tTel.\tZ-Nr.\tID\n");

    for (int i = 0; i < numEntries; i++) {
        if (phoneBook.entries[i].id == -1) break;
        else printf("%d\t%s\t%s\t%s\t%s\t%d\n", i+1, phoneBook.entries[i].name, phoneBook.entries[i].surname, phoneBook.entries[i].phoneNumber, phoneBook.entries[i].roomNumber, phoneBook.entries[i].id);
    }
    return 1; // 1 -> Success-Flag
};

/*
Funktion zur Erweiterung einer Instanz des Structs "Phonebook" um eine Instanz des Structs "Employee"
@param *phoneBook Pointer auf eine Instanz des Structs "Phonebook", in welche eingefügt werden soll
*/
void addEntry(Phonebook *phoneBook) {
    int entriesAvailable = getNumEntriesAvailable(*phoneBook);

    if (entriesAvailable == 0) {
        printf("\e[1;1H\e[2J"); // Clear console
        printf("Keine freien Einträge verfügbar.\n\n");
        return;
    }

    Employee employee;

    printf("\e[1;1H\e[2J"); // Clear console
    printf("Vorname: ");
    scanf(" %[^\n]", employee.name);
    printf("Nachname: ");
    scanf(" %[^\n]", employee.surname);
    printf("Telefonnummer: ");
    scanf(" %[^\n]", employee.phoneNumber);
    printf("Zimmernummer: ");
    scanf(" %[^\n]", employee.roomNumber);
    printf("ID: ");
    scanf("%d", &employee.id);

    int numEntries = sizeof((*phoneBook).entries) / sizeof((*phoneBook).entries[0]);

    (*phoneBook).entries[numEntries - entriesAvailable] = employee;
}

/*
Funktion zum Löschen einer Instanz des Structs "Employee" aus einer Instanz des Structs "Phonebook"
@param *phoneBook Pointer auf eine Instanz des Structs "Phonebook", in welche eingefügt werden soll
*/
void removeEntry(Phonebook *phoneBook) {
    // Anzeige aller vorhandenen Einträge -> Löschen nur ermöglicht, wenn Einträge vorhanden
    if(printEntries(*phoneBook)) {
        int entryToRemove;
        printf("\nNummer des zu löschenden Eintrags: ");
        scanf("%d", &entryToRemove);

        // Löschen durch Linksverschiebung aller Einträge ab zu löschendem Eintrag
        int numEntries = sizeof((*phoneBook).entries) / sizeof((*phoneBook).entries[0]);
        for (int i = entryToRemove - 1; i < numEntries - 1; i++) {
            (*phoneBook).entries[i] = (*phoneBook).entries[i+1];
        }
        // Erneute Initialisierung des letzten Elements in phoneBook als leere Instanz des Structs "Employee"
        (*phoneBook).entries[numEntries] = (Employee) {"", "", "", "", -1}; // --- -> Flag für leere ID
    }
}

/*
Funktion zur Anzeige eines Auswahlmenüs
@param *phoneBook Pointer auf eine Instanz des Structs "Phonebook"
*/
void menu(Phonebook *phoneBook) {
    printf("\nWählen Sie eine der folgenden Optionen:\n");
    printf("1. Eintrag hinzufügen\n");
    printf("2. Eintrag entfernen\n");
    printf("3. Einträge anzeigen\n");
    printf("4. Anzahl verfügbarer Einträge anzeigen\n");
    printf("\nOption:\t");

    int option;
    scanf("%d", &option);

    switch (option) {
        case 1:
            addEntry(phoneBook);
            break;
        case 2:
            removeEntry(phoneBook);
            break;
        case 3:
            printEntries(*phoneBook);
            break;
        case 4:
            printf("\e[1;1H\e[2J"); // Clear console
            printf("%d Einträge verfügbar.\n", getNumEntriesAvailable(*phoneBook));
    }
}

/*
Main-Funktion
*/
int main() {
    Phonebook phoneBook = initPhonebook();
    while (1) {
        menu(&phoneBook);
    }
}
