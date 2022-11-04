#include <iostream>
#include <fstream>

#define deb(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

void readFile(const string& filename) {
  fstream limpio("limpio.txt", ios::out);

  fstream file(filename, ios::in);

  string line;
  string newLine = "";

  while (getline(file, line)) {
    for (auto word : line) {
      if (word != ' ') {
        newLine += word;
      }
    }

    limpio << newLine << endl;
    newLine = "";
  }

  file.close();
  limpio.close();
}

int main() {
  readFile("main.cpp");

  return 0;
}
