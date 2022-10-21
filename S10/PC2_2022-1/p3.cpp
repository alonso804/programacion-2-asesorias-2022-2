#include <iostream>
#include <vector>

#define deb(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

class Alumno {
  string nombre;
  int edad;
  double nota;

public:
  Alumno(string nombre, int edad, double nota) {
    this->nombre = nombre;
    this->edad = edad;
    this->nota = nota;
  }

  double getNota() {
    return nota;
  }

  void setNota(const double& nota) {
    this->nota = nota;
  }

  void print() {
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Nota: " << nota << endl;
  }

  ~Alumno() = default;
};

int main() {
  vector<Alumno*> alumnos = {
    new Alumno("Pedro", 18, 15),
    new Alumno("Pablo", 17, 4),
    new Alumno("Maria", 18, 10),
    new Alumno("Juana", 19, 5),
    new Alumno("Tomas", 20, 12),
  };

  double promedio = 0;
  for (const auto& alumno : alumnos) {
    promedio += alumno->getNota();
  }

  promedio /= alumnos.size();

  if (promedio < 11) {
    for (const auto& alumno : alumnos) {
      alumno->setNota(alumno->getNota() * 1.2);
    }
  } else if (promedio <= 15) {
    for (const auto& alumno : alumnos) {
      alumno->setNota(alumno->getNota() * 1.1);
    }
  }

  vector<Alumno*> alumnosAprobados;
  vector<Alumno*> alumnosDesaprobados;

  for (const auto& alumno : alumnos) {
    if (alumno->getNota() >= 10) {
      alumnosAprobados.push_back(alumno);
    } else {
      alumnosDesaprobados.push_back(alumno);
    }
  }

  cout << "=====================" << endl;
  cout << "Promedio del curso: " << promedio << endl;
  cout << "=====================" << endl;
  cout << "Alumnos aprobados: " << endl;
  for (const auto& alumno : alumnosAprobados) {
    alumno->print();
    cout << endl;
  }
  cout << "=====================" << endl;
  cout << "Alumnos desaprobados: " << endl;
  for (const auto& alumno : alumnosDesaprobados) {
    alumno->print();
    cout << endl;
  }

  for (auto& alumno : alumnos) {
    delete alumno;
  }

  return 0;
}
