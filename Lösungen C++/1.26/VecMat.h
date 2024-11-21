//
// Created by tonih on 14.10.2024.
//

#ifndef VECMAT_H
#define VECMAT_H

#include <random>
#include <algorithm>
#include <array>
#include <iostream>

extern std::mt19937 g_randNum; // Zufallszahlengenerator

double zufallZahl(double startWert, double endWert);

// Template-Funktionen für Arrays beliebiger Größe
template <std::size_t SIZE>
void initArray(std::array<double, SIZE>& array, double startWert, double endWert) {
    for (auto& row : array) {
        row = zufallZahl(startWert, endWert);
    }
}

template <std::size_t SIZE>
void bubbleSort(std::array<double, SIZE>& array) {
    const size_t len = SIZE;
    for (size_t i = 0; i < len - 1; ++i) {
        for (size_t j = 0; j < len - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

template <std::size_t SIZE>
double minNumber(const std::array<double, SIZE>& array) {
    return *std::min_element(array.begin(), array.end());
}

template <std::size_t SIZE>
double maxNumber(const std::array<double, SIZE>& array) {
    return *std::max_element(array.begin(), array.end());
}

template <std::size_t SIZE>
double durchschnitt(const std::array<double, SIZE>& array) {
    double sum {0.0};
    for (const auto& row : array) {
        sum += row;
    }
    return sum / SIZE;
}

template <std::size_t SIZE>
void printArray(const std::array<double, SIZE>& array) {
    for (const auto& element : array) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

#endif // VECMAT_H
