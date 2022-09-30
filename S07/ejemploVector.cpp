#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include "prettyprint.hpp"

#define deb(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

using Estrella = pair<string, char>;

void anadir(vector<Estrella>& estrellas) {
  string estrella;
  char tipo;

  cin >> estrella >> tipo;
  estrellas.push_back({ estrella, tipo });
}

void borrar(vector<Estrella>& estrellas) {
  string estrella;
  cin >> estrella;

  FOR(i, 0, estrellas.size()) {
    if (estrellas[i].first == estrella) {
      estrellas.erase(estrellas.begin() + i);
      cout << "Borrada" << endl;
      return;
    }
  }

  cout << "No existe" << endl;
}

void buscar1(vector<Estrella>& estrellas) {
  string estrella;
  cin >> estrella;

  FOR(i, 0, estrellas.size()) {
    if (estrellas[i].first == estrella) {
      cout << "Estrella " << estrellas[i].first << " Tipo " << estrellas[i].second << endl;
      return;
    }
  }

  cout << "No existe" << endl;
}

void buscar2(vector<Estrella>& estrellas) {
  string estrella;
  cin >> estrella;

  auto cmp = [&estrella](Estrella& e) {
    return e.first == estrella;
  };

  auto it = find_if(estrellas.begin(), estrellas.end(), cmp);

  /* if (it != estrellas.end()) {
    cout << "Estrella " << (*it).first << " Tipo " << (*it).second << endl;
  } else {
    cout << "No se encontro" << endl;
  } */

  // (condicion) ? (si es verdadero) : (si es falso)
  string mensaje = (it != estrellas.end())
                    ? "Estrella " + (*it).first + " Tipo " + (*it).second
                    : "No se encontro";

  cout << mensaje << endl;
}

void ordenar(vector<Estrella>& estrellas) {
  auto cmp = [] (Estrella& e1, Estrella& e2) {
    return e1.first < e2.first;
  };

  sort(estrellas.begin(), estrellas.end(), cmp);
}

int main() {
  vector<Estrella> estrellas = {
    { "Zeta Puppis", 'O' },
    { "Aludra", 'B' },
    { "Formalhaut", 'A' },
    { "Canopus", 'F' },
    { "Sol", 'G' },
    { "Arcturus", 'K' },
    { "Antares", 'M' },
  };

  cout << estrellas << endl;
  ordenar(estrellas);
  cout << estrellas << endl;

  return 0;
}
