#include <complex>
#include <iostream>

double geometrischeFolge(const double wachstumsfaktor, const double startwert, const int n) {
    double summe {0.0};
    for (int i = 0; i <= n; ++i) {  // wir müssen hier <= nehmen, damit wir auf die korrekte Summenformel kommen
        summe += wachstumsfaktor * std::pow(startwert,i);
    }
    return summe;
}

int main() {
    constexpr double testdaten[][3] = {
        {1.0,2.0,10},
        {2.0,0.75,20},
        {3,0.5,10}
    };

    for(auto element :testdaten) {
        std::cout << "Für die Werte a= " << element[0] << ", q= " << element[1] << ", n= " << element[2]
    << " -> Ergibt sich die folgenden geometische Folge: "<< geometrischeFolge(element[0],element[1],element[2]) << "\n";
    }
    return 0;
}
