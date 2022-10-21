#include <iostream>
#include <algorithm>
#include <vector>

#define deb(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

void print(const vector<int>& v) {
  cout << "{";
  FOR(i, 0, v.size()) {
    cout << v[i];

    if (i != v.size() - 1) {
      cout << ", ";
    }
  }
  cout << "}" << endl;
}

void eliminarDuplicados(vector<int>& v) {
  sort(v.begin(), v.end());
  auto it = unique(v.begin(), v.end());

  v.resize(distance(v.begin(), it));
}

int main() {
  vector<int> v1 = {1 ,2 ,1 ,3 ,4 ,5};
  vector<int> v2 = {1 ,6 ,7 ,8 ,9};

  eliminarDuplicados(v1);
  eliminarDuplicados(v2);

  vector<int> v3;
  for (const auto& elemento : v1) {
    v3.push_back(elemento);
  }

  for (const auto& elemento : v2) {
    v3.push_back(elemento);
  }


  eliminarDuplicados(v3);

  vector<int> v1Modificado;
  for (const auto& elemento : v1) {
    auto it = find(v2.begin(), v2.end(), elemento);

    if (it == v2.end()) {
      v1Modificado.push_back(elemento);
    }
  }

  vector<int> v2Modificado;
  for (const auto& elemento : v2) {
    auto it = find(v1.begin(), v1.end(), elemento);

    if (it == v1.end()) {
      v2Modificado.push_back(elemento);
    }
  }

  cout << "v1: ";
  print(v1);

  cout << "v2: ";
  print(v2);

  cout << endl;

  cout << "v3: ";
  print(v3);

  cout << "v1Modificado: ";
  print(v1Modificado);

  cout << "v2Modificado: ";
  print(v2Modificado);

  return 0;
}
