#include <bits/stdc++.h>

#define deb(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

int main() {
  int n = 0;

  do {
    cin >> n;
  } while (n < 15);

  int minimum = INT_MAX;
  int maximum = INT_MIN;
  int* arr = new int[n];
  int total = 0;

  FOR(i, 0, n) {
    cin >> arr[i];

    total += arr[i];

    minimum = min(minimum, arr[i]);
    maximum = max(maximum, arr[i]);
  }

  cout << "Prom. sin min ni max: " << (total - minimum - maximum) / double(n - 2) << endl;

  int countMin = 0;
  int countMax = 0;
  bool firstMin = true;
  bool firstMax = true;
  int sum = 0;

  FOR(i, 0, n) {
    if (arr[i] == minimum) {
      if (firstMin) {
        sum += arr[i];
        firstMin = false;
      } else {
        countMin++;
      }
    } else if (arr[i] == maximum) {
      if (firstMax) {
        sum += arr[i];
        firstMax = false;
      } else {
        countMax++;
      }
    } else {
      sum += arr[i];
    }
  }

  cout << "Prom: " << sum / double(n - countMin - countMax) << endl;

  delete[] arr;

  return 0;
}
