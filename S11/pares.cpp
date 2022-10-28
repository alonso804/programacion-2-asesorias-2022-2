#include <iostream>
#include <utility>

#include "prettyprint.hpp"

#define deb(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

int main() {
  string nombres[2] = { "Tierra", "Marte" };
  double masas[2] { 1, 2 };

  pair<string, double> planetas[2];
  planetas[0] = { "Tierra", 1 };
  planetas[1] = { "Marte", 2 };

  for (int i = 0; i < 2; i++) {
    cout << nombres[i] << " - " << masas[i] << endl;
    cout << planetas[i].first << " + " << planetas[i].second << endl;
    cout << planetas[i] << endl;
    cout << endl;
  }

  return 0;
}
