#include <iostream>
#include <vector>

#define deb(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

class Carga;
class CargaGeneral;
class CargaPeligrosa;

ostream& operator<<(ostream&, const vector<Carga*>&);
ostream& operator<<(ostream&, const CargaGeneral*);
ostream& operator<<(ostream&, const CargaPeligrosa*);

double getPesos(const vector<Carga*>&);

class Carga {
protected:
  string descripcion;
  double peso;

public:
  Carga() = default;

  Carga(string descripcion, double peso) {
    this->descripcion = descripcion;
    this->peso = peso;
  }

  virtual ~Carga() = default;
  friend double getPesos(const vector<Carga*>&);
};

class CargaGeneral : public Carga {
public:
  CargaGeneral() = default;

  CargaGeneral(string descripcion, double peso) : Carga(descripcion, peso) {}

  friend ostream& operator<<(ostream&, const CargaGeneral*);
};

class CargaPeligrosa : public Carga {
  char nivelPeligrosidad;

public:
  CargaPeligrosa() = default;

  CargaPeligrosa(string descripcion, double peso, char nivelPeligrosidad) : Carga(descripcion, peso) {
    this->nivelPeligrosidad = nivelPeligrosidad;
  }

  friend ostream& operator<<(ostream&, const CargaPeligrosa*);
};

int main() {
  int n;
  vector<Carga*> cargas;
  cin >> n;

  FOR(i, 0, n) {
    char tipo;
    string descripcion;
    double peso;

    cin >> tipo >> descripcion >> peso;

    if (tipo == 'G') {
      cargas.push_back(new CargaGeneral(descripcion, peso));
    } else if (tipo == 'P') {
      char nivelPeligrosidad;
      cin >> nivelPeligrosidad;
      cargas.push_back(new CargaPeligrosa(descripcion, peso, nivelPeligrosidad));
    }
  }

  cout << cargas << endl;
  cout << "Total = " << getPesos(cargas) << endl;

  return 0;
}

ostream& operator<<(ostream& os, const vector<Carga*>& cargas) {
  for (auto carga : cargas) {
    if (dynamic_cast<CargaGeneral*>(carga)) {
      os << dynamic_cast<CargaGeneral*>(carga);
    } else if (dynamic_cast<CargaPeligrosa*>(carga)) {
      os << dynamic_cast<CargaPeligrosa*>(carga);
    }
  }

  return os;
}

ostream& operator<<(ostream& os, const CargaGeneral* carga) {
  os << carga->descripcion << " " << carga->peso << endl;

  return os;
}

ostream& operator<<(ostream& os, const CargaPeligrosa* carga) {
  os << carga->descripcion << " " << carga->peso << " " << carga->nivelPeligrosidad << endl;

  return os;
}

double getPesos(const vector<Carga*>& cargas) {
  double pesos = 0;

  for (auto carga : cargas) {
    pesos += carga->peso;
  }

  return pesos;
}
