#include <iostream>

#define deb(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

class Mascota {
protected:
  string nombre;
  int edad;

public:
  Mascota(string nombre, int edad) {
    this->nombre = nombre;
    this->edad = edad;
  }

  virtual void diTusPrivados() = 0;

  void habla() {
    cout << nombre << " habla" << endl;
  }

  virtual ~Mascota() = default;
};

/* class Perro {
  int patas;
  string raza;
  Mascota mascota;

public:
  Perro(string nombre, int edad, string raza) : mascota(nombre, edad) {
    this->patas = 4;
    this->raza = raza;
  }
}; */

class Perro : public Mascota {
  // string nombre;
  // int edad;
  int patas;
  string raza;

public:
  Perro(string nombre, int edad, string raza) : Mascota(nombre, edad) {
    this->patas = 4;
    this->raza = raza;
  }

  void diTusPrivados() override {
    cout << "Patas: " << patas << endl;
    cout << "Raza: " << raza << endl;
  }
};

class Pez : public Mascota {
  int aletas;
  string especie;

public:
  Pez(string nombre, int edad, string especie) : Mascota(nombre, edad) {
    this->aletas = 2;
    this->especie = especie;
  }

  void diTusPrivados() override {
    cout << "Aletas: " << aletas << endl;
    cout << "Especie: " << especie << endl;
  }
};

int main() {
  Perro p("Firulais", 3, "Pastor Aleman");
  p.habla();
  p.diTusPrivados();
  cout << endl;
  Pez g("Nemo", 1, "Payaso");
  g.habla();
  g.diTusPrivados();

  return 0;
}
