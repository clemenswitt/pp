// Klasse.h
#ifndef KLASSE_H
#define KLASSE_H

#include <array>
#include <string>

namespace Klasse {
    constexpr size_t MAXSTUDENTS {28};

    struct Schueler {
        int m_id{};
        std::string m_name;
        std::string m_vorname;
        std::string m_adresse;
        std::string m_gebDatum;
        std::array<double, 8> m_durchNoten{};
    };

    enum class SortierKriterium {
        ID,
        Durchschnitt
    };

    void BubbleSort(std::array<Schueler, MAXSTUDENTS>& klasse, size_t size, SortierKriterium sortierkriterium);
    void eingabeSchueler(std::array<Schueler, MAXSTUDENTS>& schuelerArray, size_t& anzahl, SortierKriterium sortierkriterium);
    void ausgabeSchueler(const std::array<Schueler, MAXSTUDENTS>& schuelerArray, size_t anzahl);
}

#endif // KLASSE_H
