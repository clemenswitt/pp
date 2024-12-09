#include <iostream>
using namespace std;

class Konto {
    private:
        int kontonummer;
        int kundennummer;
        string inhaber;
        float betrag;
        float dispo;

    public:
        Konto(int kontonummer, int kundennummer, string inhaber) {
            this->kontonummer = kontonummer;
            this->kundennummer = kundennummer;
            this->inhaber = inhaber;
            this->betrag = 0;
            this->dispo = 0;
        }

        void setDispo(float d) {
            dispo = d;
        }

        float getBetrag() {
            return betrag;
        }

        float einzahlung(float b) {
            betrag += b;
            return betrag;
        }

        float auszahlung(float b) {
            betrag = max(betrag - b, -dispo);
            return betrag;
        }

        void auszug() {
            cout << "Kundennummer:\t" << kundennummer << "\nKontonummer:\t" << kontonummer << "\nInhaber:\t" << inhaber << "\nBetrag:\t\t" << betrag << "\nDispo:\t\t" << dispo << endl;
        }
};

int main() {
    Konto k = Konto(123, 111, "Peter Lustig");
    k.setDispo(500);
    k.einzahlung(5000);
    k.auszahlung(7000);
    k.auszug();
}
