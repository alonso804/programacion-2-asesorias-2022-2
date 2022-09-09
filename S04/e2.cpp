#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

string generarBitsRandom() {
  string rand1 = "";

  FOR(i, 0, 8) {
    rand1 += to_string(rand() % 2);
  }

  return rand1;
}

string descifrar(string bits) {
  string d = "";
  int unos = 0;
  int ceros = 0;

  FOR(i, 0, bits.size()) {
    if (bits[i] == '0') {
      if (ceros == 0) {
        d += 'z';
      }
      else if (ceros == 1) {
        d += 'y';
      }
      else if (ceros == 2) {
        d += 'x';
      }
      else if (ceros == 3) {
        d += 'w';
      }
      else if (ceros == 4) {
        d += 'v';
        ceros = -1;
      }
      ceros++;
    }
    else {
      if (unos == 0) {
        d += 'u';
      }
      else if (unos == 1) {
        d += 'o';
      }
      else if (unos == 2) {
        d += 'i';
      }
      else if (unos == 3) {
        d += 'e';
      }
      else if (unos == 4) {
        d += 'a';
        unos = -1;
      }
      unos++;
    }

  }

  return d;
}

int main(int argc, char const* argv[]) {
  srand(time(0));
  string rand1 = generarBitsRandom();

  string rand2 = "";
  int i = 1;

  while (rand2 != rand1) {
    rand2 = generarBitsRandom();
    i++;
  }

  cout << "Clave encontrada despues de " << i << " intentos: " << rand2 << endl;
  cout << descifrar(rand2) << endl;

  return 0;
}
