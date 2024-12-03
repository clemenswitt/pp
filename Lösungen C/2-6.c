#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    char position[50];
    float wage;
    int fullTime; // 0 -> part time, 1 -> full time
} Employee;

Employee* initMasterData(int n) {
    Employee* masterData = malloc(n * sizeof(Employee));
    for (int i = 0; i < n; i++) masterData[i] = (Employee) {-1, "", "", 0.0, 0};
    return masterData;
}

void printEmployee(Employee masterData[], int entryNumber) {
    printf("%d\t%s\t%s\t%f\t%d\t\n", masterData[entryNumber].id, masterData[entryNumber].name, masterData[entryNumber].position, masterData[entryNumber].wage, masterData[entryNumber].fullTime);
}

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

    for (int i = 0; i < len; i++) {
        if (masterData[i].id == -1) {
            masterData[i] = e;
            break;
        }
    }
}

int main() {
    int numEmployees = 5;
    Employee* masterData = initMasterData(numEmployees);
    for (int i = 0; i < numEmployees; i++) addEmployee(masterData, numEmployees);
    printf("Zweiter Mitarbeiter: ");
    printEmployee(masterData, 1);
    printf("Fünfter Mitarbeiter: ");
    printEmployee(masterData, 4);
}
