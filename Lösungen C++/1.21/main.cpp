#include <iostream>
#include <array>


//Wir sparen uns an dieser Stelle mal die Implementierung mithilfe der Funktionen von <string>


void initArray(std::array<std::pair<char, int>,26>& array) {
    //Array befüllen
    for (size_t i = 0; i < array.size(); ++i) {
        array[i] = {static_cast<char>('A' + i), 0};
    }
}

//Input abfragen -> toUpper()
std::istream& operator>>(std::istream& is, std::array<std::pair<char, int>,26>& array) {
    char ch;
    // Zeichen für Zeichen aus dem Eingabestrom lesen
    while (is.get(ch)) {
        if (ch == '.') {
            break;
        }

        // Nur alphabetische Zeichen berücksichtigen
        if (std::isalpha(ch)) {
            // In Großbuchstaben umwandeln
            ch = std::toupper(ch);

            // Index für A-Z berechnen
            ssize_t index = ch - 'A';

            if (index < array.size()) {
                // Den Zähler für das entsprechende Zeichen erhöhen
                array[index].second++;
            }
        }
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, const std::array<std::pair<char, int>,26>& array) {
    for (const auto & i : array) {
        if(!i.second == 0) os << i.first << " : " << i.second << std::endl;
    }
    return os;
}

int main()
{
    //Array Werten von A-Z mit
    std::array<std::pair<char, int>,26> haufigkeit{};
    initArray(haufigkeit);

    std::cout << "Geben Sie eine Textzeile mit Punkt als Abschluss ein: " << std::endl;

    std::cin >> haufigkeit;

    std::cout << haufigkeit << std::endl;
}
