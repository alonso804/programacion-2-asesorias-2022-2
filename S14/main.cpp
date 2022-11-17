#include <iostream>
#include <fstream>

#define deb(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

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

int main() {
  escribir();

  return 0;
}
