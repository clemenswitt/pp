#include <stdio.h>
#include <stdlib.h>

/*
Definition des Structs "Node" bestehend aus Wert `data` und Verweisen auf Vorgänger- und Nachfolgerknoten
*/
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

/*
Funktion zum Erstellen neuer Listenelemente
@param data Wert des zu erstellenden Knotens
@return n Pointer auf die erstellte Instanz des Structs "Node"
*/
Node* createNode(int data) {
    Node* n = (Node*) malloc(sizeof(Node));
    n->data = data;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

/*
Funktion zum Finden des letzten Listenelements
@param node Beliebiger Knoten einer Liste
@return node Letztes Element der betrachteten Liste
*/
Node* findListHead(Node* node) {
    if (node->next != NULL) return findListHead(node->next);
    else return node;
}

/*
Funktion zur Erweiterung einer Liste um einen weiteren Knoten
@param baseNode Basisknoten der betrachteten Liste
@param data Wert des anzufügenden Knotens
*/
void addNode(Node* baseNode, int data) {
    Node* listHead = findListHead(baseNode);
    listHead->next = createNode(data);
    listHead->next->prev = listHead;
}

/*
Funktion zum Einfügen eines neuen Knotens an einer bestimmten Position innerhalb einer gegebenen Liste
@param baseNode Basisknoten der betrachteten Liste
@param data Wert des einzufügenden Knotens
@param index Position innerhalb der Liste, an dem ein neuer Knoten eingefügt werden soll
*/
void addNodeAt(Node* baseNode, int data, int index) {
    Node* newNode = createNode(data);
    Node* targetIndex = baseNode;
    for (int i = 0; i < index-1; i++) targetIndex = targetIndex->next;
    newNode->next = targetIndex->next;
    newNode->prev = targetIndex;
    targetIndex->next = newNode;
}

/*
Funktion zum Löschen eines Knotens an einer bestimmten Position innerhalb einer gegebenen Liste
@param baseNode Basisknoten der betrachteten Liste
@param index Position innerhalb der Liste, an dem ein Knoten gelöscht werden soll
*/
void deleteNodeAt(Node* baseNode, int index) {
    Node* targetIndex = baseNode;
    for (int i = 0; i < index-1; i++) targetIndex = targetIndex->next;
    Node* nodeToDelete = targetIndex->next;
    targetIndex->next = nodeToDelete->next;
    targetIndex->next->prev = targetIndex;
    free(nodeToDelete);
}

/*
Funktion zur Ausgabe einer Liste im Stil eines Arrays
@param baseNode Basisknoten der betrachteten Liste
*/
void printList(Node* baseNode) {
    printf("[");
    Node* current = baseNode;
    while (current != NULL) {
        printf("%d", current->data);        // Ausgabe des aktuellen Knotens
        current = current->next;            // Zum nächsten Knoten wechseln
        if (current != NULL) printf(", ");  // Komma zwischen den Elementen einfügen
    }
    printf("]\n");
}

/*
Main-Funktion
*/
int main() {
    // Liste anlegen -> Basisknoten 0 erstellen
    Node* list = createNode(0);

    // Zahlen 1 – 10 ergänzen
    for (int i = 1; i < 11; i++) {
        addNode(list, i);
    }
    printList(list);

    // Knoten mit Zahl 99 an Index 7 hinzufügen
    addNodeAt(list, 99, 7);
    printList(list);

    // Knoten an Index 7 löschen
    deleteNodeAt(list, 7);
    printList(list);
}
