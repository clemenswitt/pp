#include <iostream>
#include <ostream>
using namespace std;

// Klassendefinitionen
class Tier {
    protected:
        int Tempo;

    public:
        Tier(int Te) : Tempo(Te) {}
        Tier() : Tempo(0) {}

        void druck() const {
            cout << "Tempo = " << Tempo << endl;
        }
};

class Saeugetier : public Tier {
    protected:
        int Tragzeit;

    public:
        Saeugetier(int Te, int Tr) : Tier(Te), Tragzeit(Tr) {}
};

class Flugtier : public Tier {
    protected:
        int Fluegelspanne;

    public:
        Flugtier(int Te, int Fl) : Tier(Te), Fluegelspanne(Fl) {}
};

class Pferd : public Saeugetier {
    protected:
        string Farbe;

    public:
        Pferd(int Te, int Tr, string F): Saeugetier(Te, Tr), Farbe(F) {}

        void druck() const {
            cout << "Tempo:\t\t" << Tempo << "\nTragzeit:\t" << Tragzeit << "\nFarbe:\t\t" << Farbe << endl;
        }
};

class Wolf : public Saeugetier {
    protected:
        float Beisskraft;

    public:
        Wolf(int Te, int Tr, float B): Saeugetier(Te, Tr), Beisskraft(B) {}

        void druck() const {
            cout << "Tempo:\t\t" << Tempo << "\nTragzeit:\t" << Tragzeit << "\nBeißkraft:\t" << Beisskraft << endl;
        }
};

class Huhn : public Flugtier {
    protected:
        int LegeDauer;

    public:
        Huhn(int Te, int Fl, int L) : Flugtier(Te, Fl), LegeDauer(L) {}

        void druck() const {
            cout << "Tempo:\t\t" << Tempo << "\nFlügelspanne:\t" << Fluegelspanne << "\nLegedauer:\t" << LegeDauer << endl;
        }
};

class Papagei : public Flugtier {
    protected:
        int AnzahlFarben;

    public:
        Papagei(int Te, int Fl, int F) : Flugtier(Te, Fl), AnzahlFarben(F) {}

        void druck() const {
            cout << "Tempo:\t\t" << Tempo << "\nFlügelspanne:\t" << Fluegelspanne << "\nAnzahl Farben:\t" << AnzahlFarben << endl;
        }
};

int main() {
    Pferd p = Pferd(20, 10, "Braun");
    p.druck();

    Wolf w = Wolf(20, 10, 2700);
    w.druck();

    Huhn h = Huhn(20, 10, 2);
    h.druck();

    Papagei pg = Papagei(20, 10, 5);
    pg.druck();
}
