//
// Created by tonih on 14.10.2024.
//

#ifndef CHARH_H
#define CHARH_H

#include <random>
#include <iostream>


extern std::mt19937 g_randNum;

char zufallZahl(double startWert, double endWert);

template <std::size_t SIZE, typename T>
void initArray(std::array<T, SIZE>& charArray, const int startWert, const int endWert) {
    for (auto& ch : charArray) {
        ch = zufallZahl(startWert, endWert);
    }
}

template <std::size_t SIZE, typename T>
extern void analyzeArray(const std::array<T, SIZE>& array) {
    for (size_t i = 0; i < array.size(); ++i) {
        const auto& element = array[i];

        if(element == 'e' || element == 'E' || element == 'n' || element == 'N' || element == 'i' ||
            element == 'I' || element == 's' || element == 'S') std::cout << element << " " << element << "\n";
        else std::cout << element << " ";

        //Zeilenumbruch nach 40. Zeichen
        if ((i + 1) % 40 == 0) {
            std::cout << "\n";
        }
    }
}

template <std::size_t SIZE, typename T>
extern void printArray(const std::array<T, SIZE>& array) {
    for (const auto& element : array) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

template <std::size_t SIZE, typename T>
void bubbleSort(std::array<T, SIZE>& array) {
    const size_t len = SIZE;
    for (size_t i = 0; i < len - 1; ++i) {
        for (size_t j = 0; j < len - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}


#endif //CHARH_H
