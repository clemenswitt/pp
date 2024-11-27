// Klasse.cpp
#include "Klasse.h"
#include <numeric>
#include <iostream>
#include <algorithm>

void Klasse::BubbleSort(std::array<Klasse::Schueler, MAXSTUDENTS>& klasse, size_t size, Klasse::SortierKriterium sortierkriterium) {
    bool swapped;
    for (size_t i = 0; i < size - 1; ++i) {
        swapped = false;
        for (size_t j = 0; j < size - i - 1; ++j) {
            bool tauschen = false;
            if (sortierkriterium == Klasse::SortierKriterium::ID) {
                if (klasse[j].m_id > klasse[j + 1].m_id) tauschen = true;
            } else {
                double avg1 = std::accumulate(klasse[j].m_durchNoten.begin(), klasse[j].m_durchNoten.end(), 0.0) / 8;
                double avg2 = std::accumulate(klasse[j + 1].m_durchNoten.begin(), klasse[j + 1].m_durchNoten.end(), 0.0) / 8;
                if (avg1 > avg2) tauschen = true;
            }
            if (tauschen) {
                std::swap(klasse[j], klasse[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
//Eine bessere Variante wäre hier die Operatoren zu überladen, dies wäre vor allem praktisch wenn wir unser Programm erweitern und erneut die Ausgabe oder Eingabe
//unser selbsterstellten Objekte benötigen
void Klasse::eingabeSchueler(std::array<Klasse::Schueler, MAXSTUDENTS>& schuelerArray, size_t& anzahl, SortierKriterium sortierkriterium) {
    if (anzahl >= MAXSTUDENTS) {
        std::cout << "Maximale Anzahl von Schülern erreicht.\n";
        return;
    }
    std::cout << "--------------------------" << std::endl;
    std::cout << "Geben Sie im folgenden die Daten des Schülers ein: " << std::endl;
    std::cout << "ID: ";
    std::cin >> schuelerArray[anzahl].m_id;

    std::cout << "Name: ";
    std::getline(std::cin >> std::ws, schuelerArray[anzahl].m_name);
    std::cout << "Vorname: ";
    std::getline(std::cin >> std::ws, schuelerArray[anzahl].m_vorname);
    std::cout << "Adresse: ";
    std::getline(std::cin >> std::ws, schuelerArray[anzahl].m_adresse);
    std::cout << "Geburtsdatum: ";
    std::getline(std::cin >> std::ws, schuelerArray[anzahl].m_gebDatum);

    for (int i = 0; i < 8; ++i) {
        std::cout << "Endnote Schuljahr " << i + 5 << ": ";
        std::cin >> schuelerArray[anzahl].m_durchNoten[i];
    }
    anzahl++;
    std::cout << "Schüler hinzugefügt!\n";

    BubbleSort(schuelerArray, anzahl, sortierkriterium);
}

void Klasse::ausgabeSchueler(const std::array<Klasse::Schueler, MAXSTUDENTS>& schuelerArray, size_t anzahl) {
    std::cout << "--------------------------" << std::endl;
    std::cout << "Schülerliste: " << std::endl;
    for (size_t i = 0; i < anzahl; ++i) {
        const auto& schueler = schuelerArray[i];

        std::cout << "ID: " << schueler.m_id
                  << ", Name: " << schueler.m_name
                  << ", Vorname: " << schueler.m_vorname
                  << ", Adresse: " << schueler.m_adresse
                  << ", Geburtsdatum: " << schueler.m_gebDatum
                  << ", Durchschnitt: ";

        double avg = std::accumulate(schueler.m_durchNoten.begin(), schueler.m_durchNoten.end(), 0.0) / 8;
        std::cout << avg << '\n';
    }
    std::cout << "--------------------------" << std::endl;
}
