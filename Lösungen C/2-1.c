#include <stdio.h>

/*
Definition des Structs "Time"
*/
typedef struct {
    int hh;
    int mm;
    int ss;
} Time;

/*
Funktion zur Berechnung der Zeitspanne in Sekunden
@param t Instanz des Structs "Time"
@return t.hh * 3600 + t.mm * 60 + t.ss Zeit in Sekudnen
*/
int getSeconds(Time t) {
    return t.hh * 3600 + t.mm * 60 + t.ss;
}

/*
Funktion zur Berechnung der Zeitdifferenz zwischen zwei Instanzen des Structs "Time"
@param t1 Instanz des Structs "Time"
@param t2 Instanz des Structs "Time"
@return diff Zeitdifferenz zwischen t1, t2 als Instanz des Structs "Time"
*/
Time calculateTimeDiff(Time t1, Time t2) {
    Time diff;
    int diffSeconds = getSeconds(t1) - getSeconds(t2);
    if (diffSeconds < 0) diffSeconds = -diffSeconds;
    diff.hh = diffSeconds / 3600;
    diff.mm = (diffSeconds % 3600) / 60;
    diff.ss = (diffSeconds % 3600) % 60;
    return diff;
}

/*
Main-Funktion
*/
int main() {
    Time t1, t2, timeDiff;

    printf("Geben Sie die erste Uhrzeit ein (Format hh mm ss): ");
    scanf("%d %d %d", &t1.hh, &t1.mm, &t1.ss);

    printf("Geben Sie die zweite Uhrzeit ein (Format hh mm ss): ");
    scanf("%d %d %d", &t2.hh, &t2.mm, &t2.ss);

    timeDiff = calculateTimeDiff(t1, t2);

    printf("Die Differenz beträgt: %02d:%02d:%02d\n", timeDiff.hh, timeDiff.mm, timeDiff.ss);
}
