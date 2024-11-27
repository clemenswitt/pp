#include <iostream>
#include <string_view>
#include <cmath>

//Erstellen ein Struct Uhrzeit, welcher drei var enth�lt um unsere Zeit zu beschreiben
struct Uhrzeit {
    int m_stunden{};
    int m_minuten{};
    int m_second{};

    //struct constructor
    Uhrzeit(const int stunden = 0, const int minuten = 0, const int sekunden = 0)
        : m_stunden{stunden}, m_minuten{minuten}, m_second{sekunden} {}

    int toSeconds() const {
        return m_stunden * 3600 + m_minuten * 60 + m_second;
    }

};

//erstellen eine Funktion damit wir diesen wie bei std Datentypen ausgeben k�nnen
std::ostream& operator<<(std::ostream& os, const Uhrzeit& uhrzeit) {
    os << (uhrzeit.m_stunden < 10 ? "0" : "") << uhrzeit.m_stunden << ':'
       << (uhrzeit.m_minuten < 10 ? "0" : "") << uhrzeit.m_minuten << ':'
       << (uhrzeit.m_second < 10 ? "0" : "") << uhrzeit.m_second;
    return os;
}
//�hnlich wie oben �berladen wir die Eingabe
std::istream& operator>>(std::istream& is, Uhrzeit& time) {
    std::cout << "Stunde in hh: ";
    is >> time.m_stunden;
    std::cout << "Minute in mm: ";
    is >> time.m_minuten;
    std::cout << "Second in ss: ";
    is >> time.m_second;
    return is;
}

Uhrzeit calcDifferenzUhrzeit(const Uhrzeit& uhrzeitOne, const Uhrzeit& uhrzeitTwo)
{
    int differenzSekunden = std::abs(uhrzeitOne.toSeconds() - uhrzeitTwo.toSeconds());

    return {
        differenzSekunden / 3600,
        (differenzSekunden % 3600) / 60,
        differenzSekunden % 60
    };
}



Uhrzeit getUserInput(const std::string_view inputMessage) {
    Uhrzeit uhrzeit;
    std::cout << inputMessage;
    std::cin >> uhrzeit;
    return uhrzeit;
}

int main()
{
    std::cout << "Geben Sie im folgenden zwei Zeiten ein: " << std::endl;
    Uhrzeit timeOne {};
    std::cin >> timeOne;

    std::cout << "---------------------------" << std::endl;

    Uhrzeit timeTwo {};
    std::cin >> timeTwo;

    std::cout << "---------------------------" << std::endl;

    std::cout << "Die Zeitdifferenz beträgt: " << std::endl;
    std::cout << calcDifferenzUhrzeit(timeOne, timeTwo);


}
