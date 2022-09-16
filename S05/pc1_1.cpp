#include <bits/stdc++.h>

#define deb(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

double distancia(pair<int, int> x, pair<int, int> y) {
  return sqrt(pow(x.first - y.first, 2) + pow(x.second - y.second, 2));
}

int main() {
  int r, d;

  cout << "r d: ";
  cin >> r >> d;

  int n;
  cout << "n: ";
  cin >> n;

  int count = 0;

  FOR(i, 1, n + 1) {
    unsigned x, y, radio;
    cout << "c" << i << ": ";
    cin >> x >> y >> radio;

    double dist = distancia({x, y}, {0, 0});
    if ((dist - radio) >= r - d && (dist + radio) <= r) {
      count++;
    }
  }

  cout << endl;
  deb(count);

  return 0;
}
