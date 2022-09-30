#include <iostream>
#include <vector>
#include "prettyprint.hpp"

#define deb(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

int main() {
  // string = vector<char>
  string s = "Hola";

  deb(s);

  s += 's';
  s.push_back('r');
  deb(s);

  cout << endl;
  for (auto& c : s) {
    cout << c << endl;
  }

  return 0;
}
