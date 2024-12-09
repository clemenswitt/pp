#include <iostream>
#include <stdexcept>
using namespace std;

class Bruch {
  private:
    int z;
    int n;

  public:
    // Konstruktor mit zwei Parametern
    Bruch(int z, int n) {
      if (n == 0) throw invalid_argument("Der Nenner darf nicht 0 sein.");
      this->z = z;
      this->n = n;
    };

    Bruch(const Bruch& b) {
      this->z = b.getZaehler();
      this->n = b.getNenner();
    };

    int getZaehler() const {
      return z;
    }

    int getNenner() const {
      return n;
    }

    void setZaehler(int z) {
      this->z = z;
    }

    void setNenner(int n) {
      if (n == 0) throw invalid_argument("Der Nenner darf nicht 0 sein.");
      this->n = n;
    }

    // Operatorüberladung für +
    Bruch operator+(const Bruch& other) const {
        return Bruch(z * other.n + other.z * n, n * other.z);
    }

    // Operatorüberladung für -
    Bruch operator-(const Bruch& other) const {
        return Bruch(z * other.n - other.z * n, n * other.n);
    }

    // Operatorüberladung für *
    Bruch operator*(const Bruch& other) const {
        return Bruch(z * other.z, n * other.n);
    }

    // Operatorüberladung für /
    Bruch operator/(const Bruch& other) const {
        if (other.z == 0) {
            throw invalid_argument("Division durch 0 ist nicht erlaubt");
        }
        return Bruch(z * other.n, n * other.z);
    }

    // Ausgabeoperator überladen
    friend ostream& operator<<(ostream& os, const Bruch& bruch) {
        os << "(" << bruch.z << "/" << bruch.n << ")";
        return os;
    }

    // Kürzen von Brüchen
    void kuerzen() {
        int t = ggT(z, n);
        z /= t;
        n /= t;
    }

    void erweitern(int f) {
        z *= f;
        n *= f;
    }

    // Ermittlung des ggT als Voraussetzung zum Kürzen
    int ggT(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    double dezimal() {
        return double(z) / n;
    }

    // Destruktor
    ~Bruch() {};
};

int main() {
  Bruch b1 = Bruch(6, 4);
  b1.kuerzen();
  Bruch b2 = Bruch(5, 6);
  b2.kuerzen();

  // Ausgabe der Brüche:
  cout << "Erster Bruch gekürzt: " << b1 << endl;
  cout << "Zweiter Bruch gekürzt: " << b2 << endl;

  // Erweiterung der Brüche
  b1.erweitern(2);
  b2.erweitern(2);

  // Ausgabe der Brüche:
  cout << "Erster Bruch nach dem Erweitern: " << b1 << endl;
  cout << "Zweiter Bruch nach dem Erweitern: " << b2 << endl;

  cout << "Dezimalwert des ersten Bruchs: " << b1.dezimal() << endl;
  cout << "Dezimalwert des zweiten Bruchs: " << b2.dezimal() << endl;
}
