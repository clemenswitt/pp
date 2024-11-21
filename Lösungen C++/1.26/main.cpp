#include <iostream>
#include "VecMat.h"
#include <array>

constexpr int MAXSIZE = 50; // Maximale Größe des Arrays

size_t getUserInput() {
    int size;
    std::cout << "Bitte geben Sie die Größe des Arrays (max. " << MAXSIZE << ") ein: ";
    std::cin >> size;

    // Sicherstellen, dass die Größe innerhalb der erlaubten Grenzen liegt
    if (size < 1 || size > MAXSIZE) {
        std::cerr << "Ungültige Größe. Bitte eine Zahl zwischen 1 und " << MAXSIZE << " eingeben.\n";
        return getUserInput(); // Rekursive Eingabeaufforderung
    }

    return static_cast<size_t>(size);
}

int main() {
    constexpr double startBereich {0.0};
    constexpr double endBereich {100.0};
    const size_t size {getUserInput()};

    // Erstellen eines std::array mit der vom Benutzer eingegebenen Größe
    std::array<double, MAXSIZE> X{};

    // Nur die ersten `size` Elemente werden verwendet
    initArray(X, startBereich, endBereich);

    printArray(X);

    std::cout << "------------------------------------------\n";
    std::cout << "MEAN: " << durchschnitt(X) << "\n";
    std::cout << "MIN: " << minNumber(X) << "\n";
    std::cout << "BIG: " << maxNumber(X) << "\n";
    std::cout << "------------------------------------------\n";

    bubbleSort(X);
    printArray(X);

    return 0;
}
