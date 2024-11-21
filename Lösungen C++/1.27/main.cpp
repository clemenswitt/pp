#include <iostream>
#include <array>

#include "charh.h"





int main() {

    constexpr ssize_t SIZE{300};
    constexpr int startWert {33};
    constexpr int endWert {126};

    std::array<char, SIZE> charFeld{};

    initArray(charFeld, startWert, endWert);
    printArray(charFeld);

    std::cout << "------------------------------------------------------\n";
    bubbleSort(charFeld);
    printArray(charFeld);

    std::cout << "------------------------------------------------------\n";
    analyzeArray(charFeld);



}
