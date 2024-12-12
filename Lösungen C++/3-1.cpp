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

    // Konstruktor mit Verweis auf bereits existierenden Bruch
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
        return Bruch(z * other.n + other.z * n, n * other.n);
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

    // Destruktor
    ~Bruch() {};
};

int main() {
  Bruch b1 = Bruch(3, 4);
  Bruch b2 = Bruch(5, 6);

  // Ausgabe der Brüche:
  cout << "Erster Bruch: " << b1 << endl;
  cout << "Zweiter Bruch: " << b2 << endl;

  // Testen der überladenen Operatoren:
  cout << "b1 + b2: " << b1 + b2 << endl;
  cout << "b1 - b2: " << b1 - b2 << endl;
  cout << "b1 * b2: " << b1 * b2 << endl;
  cout << "b1 / b2: " << b1 / b2 << endl;
}
