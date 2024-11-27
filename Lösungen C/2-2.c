#include <stdio.h>

/*
Definition des Structs "Bruch"
*/
typedef struct {
    int z;
    int n;
} Bruch;

/*
Funktion zur Berechnung des Produkts zweier Instanzen des Structs "Bruch"
@param b1 Instanz des Structs "Bruch"
@param b2 Instanz des Structs "Bruch"
@return (Bruch) {b1.z * b2.z, b1.n * b2.n} Produk aus b1, b2 als Instanz des Structs "Bruch"
*/
Bruch product(Bruch b1, Bruch b2) {
    return (Bruch) {b1.z * b2.z, b1.n * b2.n};
}

/*
Funktion zur Eingabe eines Bruchs über die Kommandozeile
@return b Instanz des Structs "Bruch"
*/
Bruch readBruch() {
    Bruch b;
    printf("Geben Sie einen Bruch ein: (Format z n): ");
    scanf("%d %d", &b.z, &b.n);
    return b;
}

/*
Main-Funktion
*/
int main() {
    Bruch p = product(readBruch(), readBruch());
    printf("Das Produkt der eingelesen Brüche lautet: (%d/%d).\n", p.z, p.n);
}
