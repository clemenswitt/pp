#include <stdio.h>

/*
Definition des Structs "Student"
*/
typedef struct {
    int id;
    char surname[100];
    char name[100];
    char address[100];
    float gradeAverage;
} Student;

/*
Funktion zum Sortieren eines Student-Arrays mithilfe des BubbleSort-Algorithmus
@param studentArray[] Zeiger auf das erste Element des zu sortierenden Student-Arrays
@param n Länge des zu sortierenden Arrays
@param sortingCriterion Kriterium, nach dem sortiert werden soll: 0 -> Sortierung nach id, 1 -> Sortierung nach gradeAverage
*/
void sortStudents(Student studentArray[], int n, int sortingCriterion) {
    int condition = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            switch (sortingCriterion) {
                case 0:
                    condition = studentArray[j].id > studentArray[j+1].id;
                    break;
                case 1:
                    condition = studentArray[j].gradeAverage > studentArray[j+1].gradeAverage;
                    break;
            }

            if (condition) {
                Student temp = studentArray[j];
                studentArray[j] = studentArray[j+1];
                studentArray[j+1] = temp;
            }
        }
    }
}

/*
Funktion zum Hinzufügen von Schüler:innendatensätzen
@param studentArray[] Zeiger auf das erste Element des zu verwendenden Student-Arrays
@param id ID des/der Schüler:in Einfügeposition innerhalb von studentArray[]
*/
void addStudent(Student studentArray[], int id) {
    Student s;
    s.id = id;
    printf("Vorname: ");
    scanf(" %[^\n]", s.name);
    printf("Nachname: ");
    scanf(" %[^\n]", s.surname);
    printf("Adresse: ");
    scanf(" %[^\n]", s.address);
    printf("Notendurchschnitt: ");
    scanf("%f", &s.gradeAverage);

    studentArray[id] = s;
}
