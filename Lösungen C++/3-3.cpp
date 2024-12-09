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
        Fahrzeug(int personen, float tankvolumen, float verbrauch, float aktTankinhalt, float kmStand) {
            this->personen = personen;
            this->tankvolumen = tankvolumen;
            this->verbrauch = verbrauch;
            this->aktTankinhalt = aktTankinhalt;
            this->kmStand = kmStand;
        }

        float tankinhalt() {
            return aktTankinhalt;
        }

        float tanken(float liter) {
            aktTankinhalt = min(aktTankinhalt + liter, tankvolumen);
            return tankinhalt();
        }

        float reichweite() {
            return 100 *  aktTankinhalt / verbrauch;
        }

        float getKmStand() {
            return kmStand;
        }

        float fahren(float strecke) {
            kmStand += min(reichweite(), strecke);
            return kmStand;
        }
};

int main() {
    Fahrzeug pkw = Fahrzeug(4, 60, 7, 33, 30000);
    Fahrzeug bus = Fahrzeug(100, 200, 25, 120, 120000);
    Fahrzeug lkw = Fahrzeug(3, 200, 30, 180, 240000);


    pkw.fahren(3000);
    cout << pkw.getKmStand() << endl;
}
