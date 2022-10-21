#include <iostream>
#include <vector>

#define LOCALES 7
#define CAPACIDAD 2000

#define deb(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

int randInt(const int& min, const int& max) {
  return min + rand() % (max - min + 1);
}

char randChar() {
  return 'a' + rand() % 26;
}

void agregar(vector<int>* locales, int& producto, int idx) {
  if (locales[idx].size() < CAPACIDAD) {
    locales[idx].push_back(producto);
    return;
  }

  FOR(i, 0, LOCALES) {
    if (locales[i].size() < CAPACIDAD) {
      locales[i].push_back(i);
      return;
    }
  }
}

int main() {
  srand(time(NULL));
  vector<int> productos;
 
  FOR(i, 0, 5000) {
    productos.push_back(randInt(2022, 2032));
  }

  vector<int> locales[LOCALES];

  for (auto& producto : productos) {
    if (2022 <= producto && producto <= 2025) {
      agregar(locales, producto, 0);
    } else if (2026 <= producto && producto <= 2030) {
      agregar(locales, producto, 1);
    } else {
      agregar(locales, producto, 2);
    }
  }

  vector<int> temp = locales[1];
  locales[1].clear();
  
  for (auto& producto : temp) {
    if (producto % 2 == 0) {
      agregar(locales, producto, 3);
    } else {
      agregar(locales, producto, 4);
    }
  }

  vector<int> nuevos;
  FOR(i, 0, 2000) {
    nuevos.push_back(randInt(2022, 2032));
  }
  
  for (auto& producto : nuevos) {
    if (producto % 2 == 0) {
      agregar(locales, producto, 3);
    } else {
      agregar(locales, producto, 4);
    }
  }

  FOR(i, 0, LOCALES) {
    cout << "Local " << i << ": " << locales[i].size() << endl;
  }

  return 0;
}
