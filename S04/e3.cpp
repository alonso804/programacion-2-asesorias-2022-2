#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

bool filtro(char* color, bool* a) {
  if (*color != 'a' && *color != 'r' && *color != 'b') {
    cout << "Torre rechazada. No puedo construir una torre con esa secuencia de colores según mi programa de trabajo.Fir - mado: robots A y B : )" << endl;
    return false;
  }

  if (*a) {
    if (*color == 'r') {
      *a = false;
    }
  }

  return true;
}

int main(int argc, char const* argv[]) {
  string c;
  bool a = true;

  cout << "Ingrese la secuencia de piezas de colores:" << endl;

  cin >> c;

  FOR(i, 0, 3) {
    if (!filtro(&c[i], &a)) {
      return 0;
    }
  }

  return 0;
}