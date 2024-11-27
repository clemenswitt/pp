#include <stdio.h>
#include "2-4-Header.h"

/*
Main-Funktion zur Eingabe, zum Sortieren und zur anschließenden tabellarischen Ausgabe von n Schüler:innendatensätzen
*/
int main() {
    int n;
    printf("Wie viele Schüler:innen sollen angelegt werden? ");
    scanf("%d", &n);

    Student studentArray[n];

    for (int i = 0; i < n; i++) {
        addStudent(studentArray, i);
    }

    sortStudents(studentArray, n, 0);

    printf("\nNr.\tVorname\tNachname\tAdresse\tNotendurchschnitt\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%s\t%s\t%f\n", studentArray[i].id, studentArray[i].name, studentArray[i].surname, studentArray[i].address, studentArray[i].gradeAverage);
    }
}
