#include <iostream>
using namespace std;

class Fahrzeug {
    private:
        int personen;
        float tankvolumen;
        float verbrauch;
        float aktTankinhalt;
        float kmStand;

    public:
        Fahrzeug(int personen, float tankvolumen, float verbrauch, float aktTankinhalt, float kmStand) :
            personen(personen),
            tankvolumen(tankvolumen),
            verbrauch(verbrauch),
            aktTankinhalt(aktTankinhalt),
            kmStand(kmStand)
            {}

        float tankinhalt() const {
            return aktTankinhalt;
        }

        float tanken(float liter) {
            aktTankinhalt = min(aktTankinhalt + liter, tankvolumen);
            return tankinhalt();
        }

        float reichweite() const {
            return 100 *  aktTankinhalt / verbrauch;
        }

        float getKmStand() const {
            return kmStand;
        }

        float fahren(float strecke) {
            float moeglicheStrecke = min(reichweite(), strecke);
            aktTankinhalt -= (moeglicheStrecke * verbrauch) / 100;
            kmStand += moeglicheStrecke;
            return kmStand;
        }

        friend ostream& operator<<(ostream& os, const Fahrzeug& f) {
            os << "Km-Stand: " << f.kmStand << ", Tankinhalt: " << f.aktTankinhalt << " L" << endl;
            return os;
        }
};

int main() {
    Fahrzeug pkw = Fahrzeug(4, 60, 7, 33, 30000);
    Fahrzeug bus = Fahrzeug(100, 200, 25, 120, 120000);
    Fahrzeug lkw = Fahrzeug(3, 200, 30, 180, 240000);


    pkw.fahren(3000);
    cout << pkw;
}
