#include <iostream>

bool istSchaltjahr(const int jahr) {
    if (jahr % 4 == 0) {
        if (jahr % 100 == 0) {
            if (jahr % 400 == 0) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}


int main() {
    constexpr int startJahr {1777};
    constexpr int endJahr {2117};

    std::cout << "------------------------------------------\n";
    std::cout << "Schaltjahre von " << startJahr << " bis " << endJahr <<"\n";
    std::cout << "------------------------------------------\n";

    for(int jahr {startJahr}; jahr <= endJahr; ++jahr) {
        if (istSchaltjahr(jahr)) {
            std::cout << jahr << " ist ein Schaltjahr\n";
        } else {
            std::cout << jahr << " ist kein Schaltjahr\n";
        }
    }
}
