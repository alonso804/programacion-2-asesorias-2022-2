#include <iostream>
#include <vector>

using namespace std;

class Padre {

public:
  virtual ~Padre() {}
};

class Hijo : public Padre {
public:
  void printHijo() {
    cout << "Soy un hijo" << endl;
  }
};

class Hija : public Padre {
public:
  void printHija() {
    cout << "Soy una hija" << endl;
  }
};

int main() {
  vector<Padre*> v;

  v.push_back(new Hijo());
  v.push_back(new Hija());

  cout << boolalpha << (dynamic_cast<Hijo*>(v[0]) == nullptr) << endl; // false
  cout << boolalpha << (dynamic_cast<Hija*>(v[0]) == nullptr) << endl; // true

  cout << boolalpha << (dynamic_cast<Hijo*>(v[1]) == nullptr) << endl; // true
  cout << boolalpha << (dynamic_cast<Hija*>(v[1]) == nullptr) << endl; // false

  return 0;
}
