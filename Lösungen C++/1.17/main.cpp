#include <iostream>

double calcUmlaufszeit(const int laenge, const int maxUebertragung) {
    return static_cast<double>(laenge)/maxUebertragung;
}

int main() {
    constexpr int laenge {1000}; //in Byte
    constexpr int hoehe {12000000}; // in m
    constexpr int uebertragungsrate {10}; //in MBit/s

    constexpr int c {299792458}; //in m/s

    const double t1 {calcUmlaufszeit(laenge, uebertragungsrate)};
    const double t2 {calcUmlaufszeit(hoehe, c)};

    std::cout << "Sendezeit t1: " << t1 << " Sekunden" << "\n";
    std::cout << "Ausbreitungszeit t2: " << t2 << " Sekunden" << "\n";

    std::cout << "Gesamtzeit T: " << t1+t2 << " Sekunden" << "\n";
}
