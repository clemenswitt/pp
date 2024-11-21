#include <iostream>
#include <random>
#include "Random.h"

void bubble_float(float *arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        // Innere Schleife f�r den Vergleich der benachbarten Elemente
        for (int j = 0; j < size - i - 1; ++j) {
            // Wenn das aktuelle Element gr��er ist als das n�chste, tauschen
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(const float *arr, int size) {
    std::cout << "Index\tWert\n";
    std::cout << "----------------------\n";
    for (int i = 0; i < size; ++i) {
        std::cout << i+1 << "\t" << arr[i] << "\n";
    }
    std::cout << "----------------------\n";
}


double zufallZahl(const double startWert, const double endWert) {
    std::uniform_real_distribution<double> zahl{startWert, endWert};
    return zahl(Random::mt);
}


int main() {
    constexpr double startWert{1.0};
    constexpr double endWert{100.0};

    constexpr int arraySize{50};
    float numbers[arraySize];

    for (int i {0}; i < arraySize; ++i) {
        numbers[i] = zufallZahl(startWert, endWert);
    }

    std::cout << "Array vor der Sortierung:\n";
    printArray(numbers, arraySize);

    bubble_float(numbers, arraySize);

    std::cout << "\nArray nach der Sortierung:\n";
    printArray(numbers, arraySize);

    return 0;
}
