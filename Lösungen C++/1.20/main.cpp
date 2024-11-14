#include <iostream>
#include <vector>
#include <sstream>
#include <string>

//Operator Funktions:
//Operatoren sind in Wahrheit auch nur Funktion, deshalb können wir diese auch wie normale Funktionen überladen
//Der << Operator returned eine ostream-Referenz und nimmt eine ostream var und unseren Vector -> nach dem Bau: [std::ostream] << [std::vector<string>]
//Warum machen wir das? -> wir können hiermit den std::vector<std::string> datatyp als normalen Datentypen behandeln wie z.B. wenn wir einen int printen mit std::cout << [var mit datatype int];
std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& words) {
    //Für unsere Elemente in unserem Vektor words:
    for (const auto& word : words) {
        os << word << " ";
    }
    return os;
}

//Speichern jedes Wort in unserem Vector
std::istream& operator>>(std::istream& is, std::vector<std::string>& words) {
    std::string line;
    std::getline(is >> std::ws, line);

    std::istringstream stream(line);
    std::string word;
    while (stream >> word) {
        words.push_back(word);
    }
    return is;
}


std::vector<std::string> WordIn(const std::vector<std::string>& ZK, const std::string_view zkeinf, const int N) {
    if (N < 0 || N > static_cast<int>(ZK.size())) {
        std::cerr << "Ungültige Position!\n";
        return ZK; // Rückgabe des unveränderten Vektors im Fehlerfall
    }

    std::vector<std::string> newZK;

    // Elemente bis zur Position N hinzufügen
    for (int i = 0; i < N; ++i) {
        newZK.push_back(ZK[i]);
    }

    // Neues Element unserem Vector/Array hinzufügen
    newZK.push_back(std::string(zkeinf));

    // Restliche Elemente hinzufügen
    for (int i = N; i < static_cast<int>(ZK.size()); ++i) {
        newZK.push_back(ZK[i]);
    }

    return newZK;
}




int main()
{
    std::cout << "Geben sie eine Zeichenkette ein: " << std::endl;
    std::vector<std::string> ZK{};
    std::cin >> ZK;

    std::string zeichenKetteEinf{};
    std::cout << "Geben Sie die zu einfügene Zeichenkette ein: " << std::endl;
    std::getline(std::cin >> std::ws, zeichenKetteEinf);

    int posEinf;
    std::cout << "Geben Sie ein, an welcher Stelle die Zeichenkette eingefügt werden soll: " << std::endl;
    std::cin >> posEinf;

   std::vector<std::string> result = WordIn(ZK, zeichenKetteEinf, posEinf);
    std::cout << "Ergebnis: " << result << std::endl;


}
