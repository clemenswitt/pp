#include <stdio.h>
#include <stdlib.h>

/*
Definition des Structs "Employee"
*/
typedef struct {
    int id;
    char name[50];
    char position[50];
    float wage;
    int fullTime; // 0 -> part time, 1 -> full time
} Employee;

/*
Funktion zur Initialisierung eines Felds bestehend aus Instanzen des Structs "Employee"
@param n Anzahl der Feldelemente
*/
Employee* initMasterData(int n) {
    Employee* masterData = malloc(n * sizeof(Employee));
    for (int i = 0; i < n; i++) masterData[i] = (Employee) {-1, "", "", 0.0, 0};
    return masterData;
}

/*
Funktion zur Ausgabe der Daten eines Mitarbeiters innerhalb eines Felds bestehend aus Instanzen des Structs "Employee"
@param masterData[] Feld bestehend aus Instanzen des Structs "Employee"
@param entryNumber Index des auszugebenden Mitarbeiters
*/
void printEmployee(Employee masterData[], int entryNumber) {
    printf("%d\t%s\t%s\t%f\t%d\t\n", masterData[entryNumber].id, masterData[entryNumber].name, masterData[entryNumber].position, masterData[entryNumber].wage, masterData[entryNumber].fullTime);
}

/*
Funktion zur Initialisierung eines neuen Mitarbeiters
@param masterData[] Feld bestehend aus Instanzen des Structs "Employee"
@param len Länge des Felds masterData[]
*/
void addEmployee(Employee masterData[], int len) {
    Employee e;
    printf("Mitarbeiter ID: ");
    scanf("%d", &e.id);
    printf("Name: ");
    scanf(" %[^\n]", e.name);
    printf("Position: ");
    scanf(" %[^\n]", e.position);
    printf("Gehalt in €: ");
    scanf("%f", &e.wage);
    printf("Vollzeit (1: ja, 0: nein): ");
    scanf("%d", &e.fullTime);

    // Finden der ersten freien Employee-Instanz innerhalb von masterData[]
    for (int i = 0; i < len; i++) {
        if (masterData[i].id == -1) {
            masterData[i] = e;
            break;
        }
    }
}

/*
Main-Funktion
*/
int main() {
    int numEmployees = 5;
    Employee* masterData = initMasterData(numEmployees);
    for (int i = 0; i < numEmployees; i++) addEmployee(masterData, numEmployees);
    printf("Zweiter Mitarbeiter: ");
    printEmployee(masterData, 1);
    printf("Fünfter Mitarbeiter: ");
    printEmployee(masterData, 4);
}
