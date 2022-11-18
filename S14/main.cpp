#include <iostream>
#include <vector>
#include <fstream>

#define deb(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

void leer();
void escribir();

class Persona;

void filePersona(const string&, Persona&);
void filePersona(const string&, vector<Persona*>&);

ostream& operator << (ostream&, const Persona&);
ostream& operator << (ostream&, const vector<Persona*>&);

class Persona {
  string nombre;
  int edad;

public:
  Persona(string nombre, int edad) {
    this->nombre = nombre;
    this->edad = edad;
  }

  friend ostream& operator << (ostream&, const Persona&);
  friend ostream& operator << (ostream&, const vector<Persona*>&);

  ~Persona() {}
};


int main() {
  vector<Persona*> personas;
  personas.push_back(new Persona("Juan", 20));
  personas.push_back(new Persona("Pedro", 30));
  personas.push_back(new Persona("Maria", 40));

  filePersona("personas.csv", personas);

  for (auto& persona : personas) {
    delete persona;
  }

  return 0;
}

void leer() {
  // ifstream file("temp.txt");
  fstream file("temp.txt", ios::in);

  string line;

  while (getline(file, line)) {
    cout << line << endl;
  }

  file.close();
}

void escribir() {
  // ofstream file("escritura.txt");
  fstream file("escritura2.txt", ios::out);

  for (int i = 0; i < 10; i++) {
    file << "Linea " << i * 9 << endl;
  }

  file.close();
}

void filePersona(const string& filename, Persona& persona) {
  fstream file(filename, ios::out);

  // file << "Nombre: " << persona.nombre << endl;
  // file << "Edad: " << persona.edad << endl;

  file << persona << endl;

  file.close();
}

ostream& operator << (ostream& os, const Persona& persona) {
  os << "nombre,edad" << endl;
  os << persona.nombre << "," << persona.edad;

  return os;
}

void filePersona(const string& filename, vector<Persona*>& personas) {
  fstream file(filename, ios::out);

  file << personas << endl;

  file.close();
}

ostream& operator << (ostream& os, const vector<Persona*>& personas) {
  os << "nombre,edad" << endl;

  for (const auto& persona : personas) {
    os << persona->nombre << "," << persona->edad << endl;
  }

  return os;
}
