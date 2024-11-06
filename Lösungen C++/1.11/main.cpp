#include <iostream>
#include <fstream> //Für die Arbeit mit Files
#include <cmath> //Für PI
#include <array>


//Werte aus der Aufgabenstellung:
constexpr int intervalle{ 16 };
constexpr double start{ 0.0 };
constexpr double end{ 4.0 * M_PI };

void createFile(const std::array<double, intervalle+1>& x, const std::array<double, intervalle+1>& y)
{
    //Erstellen ein Objekt logfile -> Objekt zur Behandlung von Dateien, {NAME} = Name unserer Datei
    std::ofstream logfile{"LOG.FILE"};
    //kontrollieren ob das Programm die Datei geöffnet hat
    if(logfile.is_open()) {
        for (int i{ 0 }; i < std::ssize(x); ++i) {
            //unser logfile objekt können wir ähnlich wie std::cout behandeln, d.h << ist der Operator um in die File zu schreiben
            logfile << "x-Wert: " << x[i] << '\n';
            logfile << "y-Wert: " << y[i] << '\n';
            logfile << "--------------------------" << '\n';
        }
        logfile.close();
    }
    else {
        //Wir werfen einen Fehler, wenn die Datei nicht geöffnet werden kann
        std::cerr << "Error opening file" << std::endl;
    }
}


int main() {
    // Arrays für Funktionswerte
    std::array<double, intervalle+1> x{};
    std::array<double, intervalle+1> y{};

    // Schrittweite für die 16 Intervalle, also 4pi in 16 Intervalle aufgeteilt
    constexpr double step = end / intervalle;

    // Berechnung der x- und y-Werte
    for (int i = 0; i <= intervalle; ++i) {
        x[i] = start + i * step;
        //Formel: y(x) = x * sin(x)
        y[i] = x[i] * std::sin(x[i]);
    }

    //Ausgabe, wenn wir dies nur in der Konsole ausgeben wollen
    /*for (int i{ 0 }; i < std::ssize(x); ++i) {
        std::cout << "x-Wert: " << x[i] << '\n';
        std::cout << "y-Wert: " << y[i] << '\n';
        std::cout << "--------------------------" << '\n';
    }*/
    createFile(x,y);

    return 0;
}
