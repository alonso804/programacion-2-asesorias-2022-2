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

  void sentarse() {
    cout << nombre << " sientate" << endl;
  }
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
};

class Pez : public Mascota {
  int aletas;
  string especie;

public:
  Pez(string nombre, int edad, string especie) : Mascota(nombre, edad) {
    this->aletas = 2;
    this->especie = especie;
  }
};

int main() {
  

  return 0;
}
