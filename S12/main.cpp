#include <iostream>
#include <vector>
#include <fstream>

#include "prettyprint.hpp"

// cout = ostream -> consola
// cin = istream -> consola
// file = fstream -> archivo

// ios::in = lectura
// ios::out = escritura sobreescribir
// ios::app = escritura agregar

#define deb(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

class Persona;

void writeCsv(const vector<Persona*>&, const string&);

vector<Persona*> readCsv(const string&);

vector<string> split(const string&, const char&);

ostream& operator << (ostream&, const Persona&);

class Persona {
  string name;
  string lastname;
  int age;
  string city;

public:
  Persona(string name, string lastname, int age, string city) {
    this->name = name;
    this->lastname = lastname;
    this->age = age;
    this->city = city;
  }

  void setName(string name) {
    this->name = name;
  }

  void sumarAno() {
    this->age++;
  }

  friend void writeCsv(const vector<Persona*>&, const string&);
  friend vector<Persona*> readCsv(const string&);

  friend ostream& operator << (ostream&, const Persona&);
};

int main() {
  vector<Persona*> personas;
  personas.push_back(new Persona("Juan", "Perez", 21, "Lima"));
  personas.push_back(new Persona("Jose", "Feliciano", 20, "Arequipa"));
  personas.push_back(new Persona("Andrea", "Gonzales", 30, "Lima"));
  personas.push_back(new Persona("Alonso", "Barrios", 25, "Piura"));

  writeCsv(personas, "data.csv");

  for (auto& persona : personas) {
    delete persona;
  }

  auto nuevasPersonas = readCsv("data.csv");

  for (auto& persona : nuevasPersonas) {
    persona->setName("Fiestas");
    persona->sumarAno();
  }

  writeCsv(nuevasPersonas, "data2.csv");

  for (auto& persona : nuevasPersonas) {
    cout << *persona << endl;
  }

  for (auto& persona : nuevasPersonas) {
    delete persona;
  }

  return 0;
}

void writeCsv(const vector<Persona*>& personas, const string& filename) {
  fstream file(filename, ios::out);

  for (auto& persona : personas) {
    file << persona->name << "," << persona->lastname << "," << persona->age << "," << persona->city << endl;
  }

  file.close();
}

vector<Persona*> readCsv(const string& filename) {
  vector<Persona*> personas;

  fstream file(filename, ios::in);

  string line;

  while(getline(file, line)) {
    auto items = split(line, ',');

    personas.push_back(new Persona(items[0], items[1], stoi(items[2]), items[3]));
  }

  file.close();

  return personas;
}

vector<string> split(const string& line, const char& sep = ',') {
  vector<string> items;

  string word = "";

  for (const auto& letter : line) {
    if (letter == sep) {
      items.push_back(word);
      word = "";
    } else {
      word += letter;
    }
  }

  items.push_back(word);

  return items;
}

ostream& operator << (ostream& out, const Persona& p) {
  out << "Nombre: " << p.name << " - Apellido: " << p.lastname << " - " << p.age << " - " << p.city;

  return out;
}
