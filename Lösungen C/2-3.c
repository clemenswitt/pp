#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
Definition des Structs "Time"
*/
typedef struct {
    int hh;
    int mm;
    int ss;
} Time;

/*
Definition des Structs "Date"
*/
typedef struct {
    int d;
    int m;
    int y;
} Date;

/*
Definition des Structs "Appointment"
*/
typedef struct {
    Time t;
    Date d;
    int unixTimeStamp;
} Appointment;

/*
Funktion zur Konsolenausgabe einer Instanz des Structs "Appointment"
@param a Instanz des Structs "Appointment"
*/
void printAppointment(Appointment a) {
    printf("%d.%d.%d, %d:%d:%d\n", a.d.d, a.d.m, a.d.y, a.t.hh, a.t.mm, a.t.ss);
}

/*
Funktion zur Berehcnung des Unix-Timestamps einer Instanz des Structs "Appointment"
@param a Instanz des Structs "Appointment"
@return (int) mktime(&t) Int-Repräsentation des Unix-Timestamps von a
*/
int calculateUnixTimestamp(Appointment a) {
    // Vernwendung des Structs tm ("Time") aus <time.h>
    struct tm t = {0};

    // Zeitdaten in t übertragen
    t.tm_year = a.d.y - 1900; // Jahre seit 1900
    t.tm_mon = a.d.m - 1;    // Monate von 0 bis 11
    t.tm_mday = a.d.d;       // Tag des Monats
    t.tm_hour = a.t.hh;      // Stunden
    t.tm_min = a.t.mm;       // Minuten
    t.tm_sec = a.t.ss;       // Sekunden

    // mktime berechnet den Unix-Timestamp
    return (int) mktime(&t);
}

/*
Funktion zur Berechnung der Gültigkeit einer angelegten Instanz des Structs "Appointment"
@param a Instanz des Structs "Appointment"
@return a Instanz des Structs "Appointment"
*/
Appointment checkAppointment(Appointment a) {
    if (a.d.d > 31 || a.d.m > 12 || a.t.hh > 23 || a.t.mm > 59 || a.t.ss > 59) {
        printf("Das eingegebene Datum ist fehlerhaft.\n");
        abort(); // Programmabbruch bei fehlerhafter Eingabe
    }
    return a;
}

/*
Funktion zur Erstellung einer Instanz des Structs "Appointment" mittels Konsoleneingabe
@return a Instanz des Structs "Appointment"
*/
Appointment createAppointment() {
    Appointment a;
    printf("Datum (YYYY MM DD): ");
    scanf("%d %d %d", &a.d.y, &a.d.m, &a.d.d);
    printf("Uhrzeit (HH MM SS): ");
    scanf("%d %d %d", &a.t.hh, &a.t.mm, &a.t.ss);
    a.unixTimeStamp = calculateUnixTimestamp(a);
    return a;
}

/*
Funktion zur Sortierung eines Arrays aus Instanzen des Structs "Appointment" mithilfe des BubbleSort-Algorithmus
@param appointments[] Pointer auf das erste Element des zu sortierenden Arrays
@param n Länge des zu sortierenden Arrays
*/
void sortAppointments(Appointment appointments[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (appointments[j].unixTimeStamp > appointments[j+1].unixTimeStamp) {
                Appointment temp = appointments[j];
                appointments[j] = appointments[j+1];
                appointments[j + 1] = temp;
            }
        }
    }
}

/*
Main-Funktion
*/
int main() {
    int n;
    printf("Wie viele Termine sollen angelegt werden? ");
    scanf("%d", &n);

    Appointment appointments[n];

    for (int i = 0; i < n; i++) {
        appointments[i] = checkAppointment(createAppointment());
    }

    sortAppointments(appointments, n);

    for (int i = 0; i < n; i++) {
        printAppointment(appointments[i]);
    }
};
